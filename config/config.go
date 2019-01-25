package config

import (
	"encoding/xml"
	"fmt"
	"io/ioutil"
	"os"

	"github.com/clbanning/mxj"
)

//SystemConfig настроечные параметры системы
type SystemConfig struct {
	Users       string `xml:"users"`
	ProjectPath string `xml:"projectpath"`
	LogPath     string `xml:"logpath"`
	DriversPath string `xml:"driverspath"`
	LibPath     string `xml:"libpath"`
	LibXMLName  string `xml:"namexml"`
	LibWin1251  bool   `xml:"libwin1251"`
	IconPath    string `xml:"iconpath"`
	Port        int    `xml:"port"`
	ServerDB    string `xml:"serverDB"`
	NameDB      string `xml:"nameDB"`
	UserDB      string `xml:"userDB"`
	Password    string `xml:"password"`
}

//ToString вывод с строку
func (c *SystemConfig) ToString() (result string) {
	t := "нет"
	if c.LibWin1251 {
		t = "да"
	}
	result = "Основной путь к проектам " + c.ProjectPath + "\tЛогинрование в каталог " + c.LogPath +
		"\tПуть к описанию драйверов " + c.DriversPath +
		"\nБиблиотека описаний функций " + c.LibPath + "\t win1251 кодировка? " + t +
		"\nДиректория с иконками функций " + c.IconPath + "\n"
	return result
}

//SetupConfig загрузка настроечного файла
func SetupConfig() (c SystemConfig) {
	buf, err := ioutil.ReadFile("config.xml")
	if err != nil {
		fmt.Printf("Error read config file %s\n", err.Error())
		panic(err.Error())
	}
	err = xml.Unmarshal(buf, &c)
	return c
}

//SaveConfig сохранение конфигурационного файла
func (c *SystemConfig) SaveConfig() (err error) {
	result, err := xml.Marshal(c)
	if err != nil {
		fmt.Printf("Error save config file %s\n", err.Error())
		return err
	}
	result, err = mxj.BeautifyXml(result, "", "\t")
	if err != nil {
		fmt.Printf("Error save config file %s\n", err.Error())
		return err
	}
	file, err := os.Create("config.xml")
	if err != nil {
		fmt.Printf("Error save config file %s\n", err.Error())
		return err
	}
	defer file.Close()
	_, err = file.Write(result)
	return err

}
