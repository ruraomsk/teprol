package router

import (
	"fmt"
	"strings"
	"time"

	"rura/teprol/logger"
	"rura/teprol/project"
)

var libheader *project.LibHeader

var listFunctions ListItems
var svgMaps map[string][]byte

//LibraryRouter обслуживает запросы к библиотеке функций
func LibraryRouter(headers *project.LibHeader, svgmaps map[string][]byte) {
	libheader = headers
	svgMaps = svgmaps
	listFunctions.Init()
	for _, header := range headers.ListHeaders {
		of := OneItem{
			Name:        header.Name,
			Description: header.Description,
			LastTime:    time.Now(),
		}
		listFunctions.Append(of)
	}
	for {
		select {
		case syscom := <-AllChans.CommonChan:
			if hiLibCommand(syscom) {
				return
			}

		case msgin := <-AllChans.LibRouter.Input:
			res, err := makeLibResponse(msgin)
			if err != nil {
				logger.Error.Printf("Запрос %s ошибка %s", msgin, err.Error())
			}
			AllChans.LibRouter.Output <- res
			continue
		}
	}

}
func hiLibCommand(msg string) bool {
	switch msg {
	case "stop":
		return true
	case "save":
		libheader.SaveLibFunctions()
		return false
	}
	return false
}
func makeLibResponse(msg Request) (Responce, error) {
	res := msg.NewResponce()
	switch msg.Command {
	case "list":
		body, err := listFunctions.ToJSON()
		res.SetOk(err)
		res.SetBody(0, "JSON", body)
		return res, err
	case "get":
		for _, head := range libheader.ListHeaders {
			if strings.Compare(msg.PartTwo, head.Name) == 0 {
				body, err := head.ToJSON()
				res.SetOk(err)
				res.SetBody(0, "JSON", body)
				res.SetBody(1, "SVG", svgMaps[msg.PartTwo])
				return res, err
			}
		}
		return res, fmt.Errorf("not found %s", msg.PartTwo)
	case "time":
		for _, head := range listFunctions.ListItems {
			if strings.Compare(msg.PartTwo, head.Name) == 0 {
				body, err := head.LastTime.MarshalJSON()
				res.SetOk(err)
				res.SetBody(0, "TIME", body)
				return res, err
			}
		}
		return res, fmt.Errorf("not found %s", msg.PartTwo)
	case "update":
		err := fmt.Errorf("for library this command blocked %s", msg.Command)
		res.SetOk(err)
		return res, err
	case "insert":
		err := fmt.Errorf("for library this command blocked %s", msg.Command)
		res.SetOk(err)
		return res, err

	}
	err := fmt.Errorf("not found command %s", msg.Command)
	res.SetOk(err)
	return res, err
}
