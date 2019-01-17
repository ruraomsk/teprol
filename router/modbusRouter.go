package router

import (
	"encoding/json"
	"fmt"
	"strings"
	"time"

	"rura/teprol/logger"
	"rura/teprol/project"
)

var mapModbus map[string]project.Registers
var listModbuses ListItems
var listProjects *[]project.FullProject

//ModbusRouter роутер для драйверов
func ModbusRouter(prs *[]project.FullProject) {
	listProjects = prs
	mapModbus = make(map[string]project.Registers)
	listModbuses.Init()
	for _, pr := range *prs {
		for name, modbus := range pr.ModBus {
			mod := OneItem{Name: pr.Project.General.Name + ":" + name, Description: modbus.Description, LastTime: time.Now()}
			listModbuses.Append(mod)
			mapModbus[pr.Project.General.Name+":"+name] = modbus
		}

	}
	for {
		select {
		case syscom := <-AllChans.CommonChan:
			if hiModbusCommand(syscom) {
				return
			}

		case msgin := <-AllChans.ModBus.Input:
			res, err := makeModbusResponse(msgin)
			if err != nil {
				logger.Error.Printf("Запрос %s ошибка %s", msgin, err.Error())
			}

			AllChans.ModBus.Output <- res
			continue

		}
	}

}
func hiModbusCommand(msg string) bool {
	switch msg {
	case "stop":
		return true
	case "save":
		// drvHead.SaveAll()
		return false
	}
	return false
}
func makeModbusResponse(msg Request) (Responce, error) {
	res := msg.NewResponce()
	switch msg.Command {
	case "list":
		body, err := listModbuses.ToJSON()
		res.SetOk(err)
		res.SetBody(0, "JSON", body)
		return res, err
	case "get":
		modbus := mapModbus[msg.PartTwo]
		body, err := modbus.ToJSON()
		res.SetOk(err)
		res.SetBody(0, "JSON", body)
		return res, err
	case "time":
		for _, modbus := range listModbuses.ListItems {
			if strings.Compare(msg.PartTwo, modbus.Name) == 0 {
				body, err := modbus.LastTime.MarshalJSON()
				res.SetOk(err)
				res.SetBody(0, "TIME", body)
				return res, err
			}
		}
		return res, fmt.Errorf("not found %s", msg.PartTwo)
	case "update":
		names := strings.Split(msg.PartTwo, ":")
		if len(names) != 3 {
			err := fmt.Errorf("Not found %s in command %s", msg.PartTwo, msg.Command)
			res.SetOk(err)
			return res, err
		}
		// table:=project.NewTAbleXML()
		// table.UpdateRegisters(mapModbus[msg.PartTwo])

		for _, pr := range *listProjects {
			if strings.Compare(names[0], pr.Project.General.Name) == 0 {
				oldregs := pr.ModBus[names[1]+":"+names[2]]
				var regs project.Registers
				err := json.Unmarshal(msg.Body, &regs)
				if err != nil {
					res.SetOk(err)
					return res, err
				}
				regs.Name = oldregs.Name
				regs.Description = oldregs.Description
				pr.ModBus[names[1]+":"+names[2]] = regs
				listModbuses.UpdateTime(pr.Project.General.Name + ":" + names[1] + ":" + names[2])
				return res, err
			}
		}
		return res, fmt.Errorf("not found %s", msg.PartTwo)
	case "insert":
		err := fmt.Errorf("for modbus this command blocked %s", msg.Command)
		res.SetOk(err)
		return res, err

	}
	err := fmt.Errorf("not found command %s", msg.Command)
	res.SetOk(err)
	return res, err
}
