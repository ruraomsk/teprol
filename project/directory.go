package project

import (
	"io/ioutil"
	"strings"

	"rura/teprol/logger"
)

//LoadAllProjects Загружает все проекты из стартового каталога
func LoadAllProjects(path string) ([]FullProject, error) {
	result := make([]FullProject, 0)
	dirs, err := ioutil.ReadDir(path)
	if err != nil {
		logger.Error.Printf("Ошибка чтения каталога %s %s \n", path, err.Error())
		return nil, err
	}
	path += "/"
	for _, dir := range dirs {
		fp, err := LoadFullProject(path + dir.Name())
		if err != nil {
			logger.Error.Printf("Ошибка проекта из каталога %s %s \n", path+dir.Name(), err.Error())
			return nil, err
		}
		result = append(result, *fp)
	}
	return result, nil
}

//LoadAllDrivers загружает все драйвера
func LoadAllDrivers(path string) (Drivers, error) {
	drvs := new(Drivers)
	drvs.Drivers = make(map[string]DriverXML)
	dirs, err := ioutil.ReadDir(path)
	if err != nil {
		logger.Error.Printf("Ошибка чтения каталога %s %s \n", path, err.Error())
		return *drvs, err
	}
	path += "/"
	for _, dir := range dirs {
		if !dir.IsDir() {
			continue
		}
		npath := path + dir.Name()
		files, err := ioutil.ReadDir(npath)
		if err != nil {
			logger.Error.Printf("Ошибка чтения каталога %s %s \n", npath, err.Error())
			return *drvs, err
		}
		for _, file := range files {
			if file.IsDir() {
				continue
			}
			nfile := npath + "/" + file.Name()
			drv, err := LoadDriverTable(nfile)
			if err != nil {
				logger.Error.Printf("Ошибка загрузки драйвера  %s %s \n", nfile, err.Error())
				return *drvs, err
			}
			drvs.Drivers[dir.Name()+":"+drv.Driver.Name] = *drv
		}
	}

	return *drvs, nil
}

//SaveAll сохраняет все открытые драйвера
func (d *Drivers) SaveAll() error {
	for name, drv := range d.Drivers {
		err := drv.SaveDriverTable()
		if err != nil {
			logger.Error.Printf("Ошибка выгрузки драйвера  %s %s %s \n", name, drv.Path, err.Error())
			return err
		}
	}
	return nil
}

//LoadAllSVG загружает все SVG файла с иконками для функций
func LoadAllSVG(path string) (map[string][]byte, error) {
	result := make(map[string][]byte)
	dirs, err := ioutil.ReadDir(path)
	if err != nil {
		logger.Error.Printf("Ошибка чтения каталога %s %s \n", path, err.Error())
		return result, err
	}
	path += "/"
	for _, file := range dirs {
		if file.IsDir() {
			continue
		}
		nfile := path + file.Name()
		buf, err := ioutil.ReadFile(nfile)
		if err != nil {
			logger.Error.Printf("Ошибка загрузки иконуи функции  %s %s \n", nfile, err.Error())
			return result, err
		}
		result[strings.Replace(file.Name(), ".svg", "", -1)] = buf
	}
	return result, nil
}
