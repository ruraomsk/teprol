package main

import (
	"fmt"
	"rura/teprol/config"
	"rura/teprol/logger"
	"rura/teprol/project"
	"rura/teprol/router"
	"time"
)

var err error

//Config настроечные параметры
var Config config.SystemConfig

//AllProjects храним все проекты
var AllProjects []project.FullProject

//AllDrivers храним все драйвера
var AllDrivers project.Drivers

//LibHeaders заголовки библиотеки
var LibHeaders project.LibHeader

//ListUsers все пользователи
var ListUsers router.Users

func main() {

	Config = config.SetupConfig()
	// fmt.Println(Config.ToString())
	fmt.Println("Config loaded.")

	if logger.Init(Config.LogPath) != nil {
		fmt.Println("ERROR init loggin subsystem.\nExit server...")
		return
	}
	fmt.Println("Loggin system ready.")
	ListUsers, err = router.LoadAllUsers(Config.Users)
	if err != nil {
		fmt.Printf("ERROR loading users %s\nExit server...", err.Error())
		return
	}
	fmt.Println("Users loaded.")

	AllProjects, err = project.LoadAllProjects(Config.ProjectPath)
	if err != nil {
		fmt.Println("ERROR loading progects %s\nExit server...", err.Error())
		return
	}
	fmt.Println("All projects loaded.")
	AllDrivers, err = project.LoadAllDrivers(Config.DriversPath)
	if err != nil {
		fmt.Println("ERROR loading drivers %s\nExit server...", err.Error())
		return
	}
	fmt.Println("All drivers loaded.")
	b, err := project.NeedReloadFunction(Config.LibPath, Config.LibXMLName)
	if err != nil {
		fmt.Printf("ERROR resolve headers %s \nExit server...", err.Error())
		return
	}
	if b {
		fmt.Println("Update describe library headers.")

		LibHeaders, err = project.MakeFromHeaders(Config.LibPath, Config.LibXMLName, Config.LibWin1251)
		if err != nil {
			fmt.Printf("ERROR loading headers %s \nExit server...", err.Error())
			return
		}
		err = LibHeaders.SaveLibFunctions()
		if err != nil {
			fmt.Printf("ERROR saving headers %s \nExit server...", err.Error())
			return
		}
	}
	LibHeaders, err = project.LoadLibFunctions(Config.LibPath + "/" + Config.LibXMLName)
	if err != nil {
		fmt.Printf("ERROR loading headers %s \nExit server...", err.Error())
		return
	}
	fmt.Println("All headers loaded.")

	SVGFiles, err := project.LoadAllSVG(Config.IconPath)
	if err != nil {
		fmt.Printf("ERROR loading SVG files %s \nExit server...", err.Error())
		return
	}
	fmt.Println("All SVG files loaded.")

	allChans := router.InitChans(AllProjects)
	fmt.Println("Server started")

	go router.ProjectRouter(&AllProjects)
	go router.LibraryRouter(&LibHeaders, SVGFiles)
	go router.DriverRouter(&AllDrivers)
	go router.ModbusRouter(&AllProjects)
	go router.SubsystemRouter(&AllProjects)
	go router.Transport(Config.Port, allChans, ListUsers)

	for {
		time.Sleep(time.Second * 5)
		fmt.Print(".")

	}
}
