package project

import (
	"encoding/xml"
	"fmt"
	"io/ioutil"
	"os"
	"path/filepath"
	"rura/teprol/logger"

	"github.com/clbanning/mxj"
)

//LoadFullProject загружает полный проект
func LoadFullProject(path string) (*FullProject, error) {
	var err error
	pr, err := LoadProject(path)
	if err != nil {
		return nil, err
	}
	fpr := new(FullProject)
	fpr.SubsMap = make(map[string]Subsystem)
	fpr.ModBus = make(map[string]Registers)
	fpr.Project = pr
	// fmt.Println(fpr.Project.ToString())

	for _, sub := range pr.Subsystems.Sub {
		lsub, err := pr.LoadSubsystem(sub.Name)
		if err != nil {
			logger.Error.Printf("Загрузка подсистемы %s %s", sub.Name, err.Error())
			return nil, err
		}
		fpr.SubsMap[sub.Name] = *lsub
	}
	for _, sub := range fpr.SubsMap {
		// fmt.Println(sub.Name)
		for _, mb := range sub.Ifaces.Modbuses {
			// fmt.Println(mb.Name)
			if mb.Type == "slave" {
				name := sub.Name + ":" + mb.Name
				filename := filepath.Dir(sub.Path) + "/" + mb.Name + ".xml"
				// fmt.Println(sub.Path, filename)
				table, err := LoadModbusTable(filename)
				if err != nil {
					logger.Error.Printf("Загрузка modbus %s %s %s", sub.Name, mb.Name, err.Error())
					return nil, err
				}
				rgs := table.GetRegisters(mb.Name, mb.Description)
				fpr.ModBus[name] = *rgs
				// fmt.Println(name)
			}
		}
	}
	return fpr, nil
}

//SaveFullProject сохранение всего проета XML
func (fp *FullProject) SaveFullProject() error {
	err := fp.Project.SaveProject()
	if err != nil {
		logger.Error.Println(err.Error())
		return err
	}
	for _, sub := range fp.SubsMap {
		if err != nil {
			logger.Error.Println(err.Error())
			return err
		}
		err = sub.SaveSubsystem()
		if err != nil {
			logger.Error.Println(err.Error())
			return err
		}
	}
	return nil
}

//LoadProject загружает заголовок конкретного проекта
func LoadProject(path string) (Project, error) {
	var pr Project
	pr.Path = path
	namefile := path + "/main.xml"
	buf, err := ioutil.ReadFile(namefile)
	if err != nil {
		logger.Error.Println(err.Error())
		return pr, err
	}
	err = xml.Unmarshal(buf, &pr)
	// fmt.Println(pr.ToString())
	return pr, err
}

//SaveProject сохраняет заголовок проекта в виде XML
func (p *Project) SaveProject() error {
	path := p.Path
	namefile := path + "/main.xml"
	result, err := xml.Marshal(p)
	if err != nil {
		logger.Error.Println(err.Error())
		return err
	}
	// result = bytes.Replace(result, []byte("<Project"), []byte("<"), -1)
	result, err = mxj.BeautifyXml(result, "", "\t")
	if err != nil {
		logger.Error.Println(err.Error())
		return err
	}
	file, err := os.Create(namefile)
	if err != nil {
		logger.Error.Println(err.Error())
		return err
	}
	defer file.Close()
	_, err = file.Write(result)
	return err

}

//LoadSubsystem загружает подсистему проекта
func (p *Project) LoadSubsystem(name string) (*Subsystem, error) {
	for _, sub := range p.Subsystems.Sub {
		// fmt.Println(sub.Name)
		if sub.Name == name {
			subb := new(Subsystem)
			namefile := p.Path + "/" + name + "/" + name + sub.Platform + ".xml"
			subb.Path = namefile
			subb.Name = name
			buf, err := ioutil.ReadFile(namefile)
			if err != nil {
				logger.Error.Println(err.Error())
				return nil, err
			}
			err = xml.Unmarshal(buf, &subb)
			if err != nil {
				logger.Error.Println(err.Error())
				return nil, err
			}
			return subb, err
		}
	}
	return nil, fmt.Errorf("Нет такой подсистемы %s", name)
}

//SaveSubsystem сохраняет подсистему в формате XML
func (s *Subsystem) SaveSubsystem() error {
	namefile := s.Path
	result, err := xml.Marshal(s)
	if err != nil {
		logger.Error.Println(err.Error())
		return err
	}
	// result = bytes.Replace(result, []byte("<Project"), []byte("<"), -1)
	result, err = mxj.BeautifyXml(result, "", "\t")
	if err != nil {
		logger.Error.Println(err.Error())
		return err
	}
	file, err := os.Create(namefile)
	if err != nil {
		logger.Error.Println(err.Error())
		return err
	}
	defer file.Close()
	_, err = file.Write(result)
	return err
}
