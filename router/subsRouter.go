package router

import (
	"encoding/json"
	"fmt"
	"strings"
	"time"

	"rura/teprol/logger"
	"rura/teprol/project"
)

var mapSubs map[string]project.Subsystem
var listSubs ListItems
var listProjs *[]project.FullProject

//SubsystemRouter роутер для подсистем
func SubsystemRouter(prs *[]project.FullProject) {
	listProjs = prs
	mapSubs = make(map[string]project.Subsystem)
	listSubs.Init()
	for _, pr := range *prs {
		for _, sub := range pr.Project.Subsystems.Sub {
			s := OneItem{Name: pr.Project.General.Name + ":" + sub.Name, Description: sub.Description, LastTime: time.Now()}
			listSubs.Append(s)
			mapSubs[pr.Project.General.Name+":"+sub.Name] = pr.SubsMap[sub.Name]
		}

	}
	for {
		select {
		case syscom := <-AllChans.CommonChan:
			if hiSubsCommand(syscom) {
				return
			}

		case msgin := <-AllChans.Subs.Input:
			res, err := makeSubsResponse(msgin)
			if err != nil {
				logger.Error.Printf("Запрос %s ошибка %s", msgin, err.Error())
			}

			AllChans.Subs.Output <- res
			continue

		}
	}

}
func hiSubsCommand(msg string) bool {
	switch msg {
	case "stop":
		return true
	case "save":
		// drvHead.SaveAll()
		return false
	}
	return false
}
func makeSubsResponse(msg Request) (Responce, error) {
	res := msg.NewResponce()
	switch msg.Command {
	case "list":
		body, err := listSubs.ToJSON()
		res.SetOk(err)
		res.SetBody(0, "JSON", body)
		return res, err
	case "get":
		sub := mapSubs[msg.PartTwo]
		body, err := sub.ToJSON()
		res.SetOk(err)
		res.SetBody(0, "JSON", body)
		return res, err
	case "time":
		for _, sub := range listSubs.ListItems {
			if strings.Compare(msg.PartTwo, sub.Name) == 0 {
				body, err := sub.LastTime.MarshalJSON()
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

		for _, pr := range *listProjects {
			if strings.Compare(names[0], pr.Project.General.Name) == 0 {
				var sub project.Subsystem
				err := json.Unmarshal(msg.Body, &sub)
				if err != nil {
					res.SetOk(err)
					return res, err
				}
				pr.SubsMap[names[1]+":"+names[2]] = sub
				listSubs.UpdateTime(pr.Project.General.Name + ":" + names[1] + ":" + names[2])
				return res, err
			}
		}
		return res, fmt.Errorf("not found %s", msg.PartTwo)
	case "insert":
		err := fmt.Errorf("for subs this command blocked %s", msg.Command)
		res.SetOk(err)
		return res, err

	}
	err := fmt.Errorf("not found command %s", msg.Command)
	res.SetOk(err)
	return res, err
}
