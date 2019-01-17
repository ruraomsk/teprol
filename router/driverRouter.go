package router

import (
	"encoding/json"
	"fmt"
	"strings"
	"time"

	"rura/teprol/logger"
	"rura/teprol/project"
)

var drvHead *project.Drivers
var listDrivers ListItems

//DriverRouter роутер для драйверов
func DriverRouter(dh *project.Drivers) {
	drvHead = dh
	listDrivers.Init()
	for name, drv := range drvHead.Drivers {
		dr := OneItem{Name: name, Description: drv.Driver.Description, LastTime: time.Now()}
		listDrivers.Append(dr)
	}
	for {
		select {
		case syscom := <-AllChans.CommonChan:
			if hiDriverCommand(syscom) {
				return
			}

		case msgin := <-AllChans.Drivers.Input:
			res, err := makeDriverResponse(msgin)
			if err != nil {
				logger.Error.Printf("Запрос %s ошибка %s", msgin, err.Error())
			}

			AllChans.Drivers.Output <- res
			continue

		}
	}

}
func hiDriverCommand(msg string) bool {
	switch msg {
	case "stop":
		return true
	case "save":
		drvHead.SaveAll()
		return false
	}
	return false
}
func makeDriverResponse(msg Request) (Responce, error) {
	res := msg.NewResponce()
	switch msg.Command {
	case "list":
		body, err := listDrivers.ToJSON()
		res.SetOk(err)
		res.SetBody(0, "JSON", body)
		return res, err
	case "get":
		for name, drv := range drvHead.Drivers {
			if strings.Compare(msg.PartTwo, name) == 0 {
				body, err := drv.ToJSON()
				res.SetOk(err)
				res.SetBody(0, "JSON", body)
				return res, err
			}
		}
		return res, fmt.Errorf("not found %s", msg.PartTwo)
	case "time":
		for _, drv := range listDrivers.ListItems {
			if strings.Compare(msg.PartTwo, drv.Name) == 0 {
				body, err := drv.LastTime.MarshalJSON()
				res.SetOk(err)
				res.SetBody(0, "TIME", body)
				return res, err
			}
		}
		return res, fmt.Errorf("not found %s", msg.PartTwo)
	case "update":
		for name, drv := range drvHead.Drivers {
			if strings.Compare(msg.PartTwo, name) == 0 {
				path := drv.Path
				var drvnew project.DriverXML
				err := json.Unmarshal(msg.Body, &drvnew)
				drvnew.Path = path
				res.SetOk(err)
				if err == nil {
					drvHead.Drivers[name] = drvnew
					listDrivers.UpdateTime(name)
				}
				return res, err
			}
		}
		return res, fmt.Errorf("not found %s", msg.PartTwo)
	case "insert":
		err := fmt.Errorf("for drivers this command blocked %s", msg.Command)
		res.SetOk(err)
		return res, err

	}
	err := fmt.Errorf("not found command %s", msg.Command)
	res.SetOk(err)
	return res, err
}
