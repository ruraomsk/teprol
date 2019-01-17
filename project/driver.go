package project

import (
	"encoding/xml"
	"io/ioutil"
	"os"

	"github.com/clbanning/mxj"

	// "fmt"
	"rura/teprol/logger"
)

//LoadDriverTable загрузка таблицы описания модбаса
func LoadDriverTable(namefile string) (*DriverXML, error) {
	t := new(DriverXML)
	buf, err := ioutil.ReadFile(namefile)
	if err != nil {
		logger.Error.Println(err.Error())
		return nil, err
	}
	err = xml.Unmarshal(buf, &t)
	t.Path = namefile
	// fmt.Println(t.ToString())
	return t, err

}

//SaveDriverTable сохраняет таблицу в формате XML
func (t *DriverXML) SaveDriverTable() error {
	result, err := xml.Marshal(t)
	if err != nil {
		logger.Error.Println(err.Error())
		return err
	}
	// result = bytes.Replace(result, []byte("<TableXML"), []byte("<table"), -1)
	result, err = mxj.BeautifyXml(result, "", "\t")
	if err != nil {
		logger.Error.Println(err.Error())
		return err
	}
	file, err := os.Create(t.Path)
	if err != nil {
		logger.Error.Println(err.Error())
		return err
	}
	defer file.Close()
	_, err = file.Write(result)
	return err
}
