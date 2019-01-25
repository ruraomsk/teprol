package main

import (
	"fmt"
	"rura/teprol/config"
	"rura/teprol/dataBase"
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

var ConDB dataBase.DBConnect

func main() {

	Config = config.SetupConfig()
	// fmt.Println(Config.ToString())
	fmt.Println("Config loaded.")
	err = logger.Init(Config.LogPath)
	if err != nil {
		fmt.Printf("ERROR init loggin subsystem %s\nExit server...", err.Error())
		return
	}
	fmt.Println("Loggin system ready.")
	ConDB, err = dataBase.DBConnectMake(Config)
	if err != nil {
		fmt.Printf("ERROR init DataBase subsystem %s\nExit server...", err.Error())
		return
	}
	fmt.Println("DataBase ready.")

	ListUsers, err = router.LoadAllUsers(Config.Users)
	if err != nil {
		fmt.Printf("ERROR loading users %s\nExit server...", err.Error())
		return
	}
	fmt.Println("Users loaded.")

	AllProjects, err = project.LoadAllProjects(Config.ProjectPath)
	if err != nil {
		fmt.Printf("ERROR loading progects %s\nExit server...", err.Error())
		return
	}
	fmt.Println("All projects loaded.")
	AllDrivers, err = project.LoadAllDrivers(Config.DriversPath)
	if err != nil {
		fmt.Printf("ERROR loading drivers %s\nExit server...", err.Error())
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
	// Создаем базу даннх

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
