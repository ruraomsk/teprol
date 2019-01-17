package router

import (
	"fmt"
	"strings"
	"time"

	"rura/teprol/logger"
	"rura/teprol/project"
)

var mapProj map[string]project.Project
var listProj ListItems
var listPros *[]project.FullProject

//ProjectRouter роутер для проектов
func ProjectRouter(prs *[]project.FullProject) {
	listPros = prs
	mapProj = make(map[string]project.Project)
	listSubs.Init()
	for _, pr := range *prs {
		one := OneItem{Name: pr.Project.General.Name, Description: pr.Project.General.Description, LastTime: time.Now()}
		listProj.Append(one)
		mapProj[pr.Project.General.Name] = pr.Project
	}
	for {
		select {
		case syscom := <-AllChans.CommonChan:
			if hiProjectCommand(syscom) {
				return
			}

		case msgin := <-AllChans.Project.Input:
			res, err := makeProjectResponse(msgin)
			if err != nil {
				logger.Error.Printf("Запрос %s ошибка %s", msgin, err.Error())
			}

			AllChans.Project.Output <- res
			continue

		}
	}

}
func hiProjectCommand(msg string) bool {
	switch msg {
	case "stop":
		return true
	case "save":
		// drvHead.SaveAll()
		return false
	}
	return false
}
func makeProjectResponse(msg Request) (Responce, error) {
	res := msg.NewResponce()
	switch msg.Command {
	case "list":
		body, err := listProj.ToJSON()
		res.SetOk(err)
		res.SetBody(0, "JSON", body)
		return res, err
	case "get":
		pr := mapProj[msg.PartTwo]
		body, err := pr.ToJSON()
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
		// names := strings.Split(msg.PartTwo, ":")
		// if len(names) != 3 {
		// 	err := fmt.Errorf("Not found %s in command %s", msg.PartTwo, msg.Command)
		// 	res.SetOk(err)
		// 	return res, err
		// }

		// for _, pr := range *listProjects {
		// 	if strings.Compare(names[0], pr.Project.General.Name) == 0 {
		// 		var sub project.Subsystem
		// 		err := json.Unmarshal(msg.Body, &sub)
		// 		if err != nil {
		// 			res.SetOk(err)
		// 			return res, err
		// 		}
		// 		pr.SubsMap[names[1]+":"+names[2]] = sub
		// 		listSubs.UpdateTime(pr.Project.General.Name+":"+names[1]+":"+names[2])
		// 		return res, err
		// 	}
		// }
		err := fmt.Errorf("for project this command blocked %s", msg.Command)
		res.SetOk(err)
		return res, err
		// return res, fmt.Errorf("not found %s", msg.PartTwo)
	case "insert":
		err := fmt.Errorf("for project this command blocked %s", msg.Command)
		res.SetOk(err)
		return res, err

	}
	err := fmt.Errorf("not found command %s", msg.Command)
	res.SetOk(err)
	return res, err
}
