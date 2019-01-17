package project
import(
	"encoding/json"
)

//Project описание одного проекта системы
type Project struct {
	Path       string     `xml:"path" json:"path"`
	General    General    `xml:"general" json:"general"`
	Subsystems Subsystems `xml:"subsystem" json:"subsystem"`
}
//ToJSON вывод в JSOM
func (p *Project) ToJSON() ([]byte,error){
	return json.Marshal(p)
}

//Subsystems описание списка подсистем
type Subsystems struct {
	Sub []Sub `xml:"subs" json:"subs"`
}

//General описание параматров всего проекта
type General struct {
	Name        string `xml:"name,attr" json:"name"`
	Description string `xml:"description,attr" json:"desription"`
}

//Sub описание одной подсистемы
type Sub struct {
	Name        string `xml:"name,attr" json:"name"`
	Path        string `xml:"path,attr" json:"path"`
	Platform    string `xml:"platform,attr" json:"platform"`
	Description string `xml:"description,attr" json:"desription"`
	Type        string `xml:"type,attr" json:"type"`
	Step        string `xml:"step,attr" json:"step"`
}

//ToString вывод в строку
func (p *Project) ToString() string {
	result := p.General.Name + ":" + p.General.Description + " =" + p.Path + "\n"
	for _, sub := range p.Subsystems.Sub {
		result += sub.Name + "\t" + sub.Description + "\t" + sub.Path + "\t" + sub.Platform + "\t" + sub.Type + "\t" + sub.Step + "\t" + sub.Path + "\n"
	}
	return result
}

//Subsystem описание подсистемы
type Subsystem struct {
	Path      string	`xml:"path" json:"path"`
	Name 		string `xml:"name" json:"name"`
	Ifaces    Ifaces    `xml:"iface" json:"iface"`
	Modules   Modules   `xml:"modules" json:"modules"`
	Devices   Devices   `xml:"devices" json:"devices"`
	Saved     Saved     `xml:"saves" json:"saves"`
	Variables Variables `xml:"vars" json:"vars"`
}
//ToJSON вывод в формате JSON
func (s *Subsystem) ToJSON() ([]byte,error){
	return json.Marshal(s)
}
//ToString возвращает в символьном виде всю подсистему
func (s *Subsystem) ToString() string {
	result := s.Name+" "+s.Path + "\n"
	result += s.Modules.ToString()
	result += s.Ifaces.ToString()
	result += s.Devices.ToString()
	result += s.Saved.ToString()
	result += s.Variables.ToString()
	return result
}

//Ifaces описание внешних интерфейсов подсистемы
type Ifaces struct {
	Modbuses []Modbus `xml:"modbus" json:"modbus"`
}

//ToString возвращает в символьном виде
func (i *Ifaces) ToString() string {
	result := "Iface:\n"
	for _, mod := range i.Modbuses {
		result += mod.ToString()
	}
	return result + "\n"
}

//Modules list Module addreses processors
type Modules struct {
	ListModule []Module `xml:"module" json:"module"`
}

//ToString печатает все адреса
func (m *Modules) ToString() string {
	result := "Modules:"
	for _, mod := range m.ListModule {
		result += mod.IP + "\t"
	}
	return result + "\n"
}

//Module описание одгого IP адреса модуля
type Module struct {
	IP string `xml:"ip,attr" json:"ip"`
}

//Devices описание списка всех устройств
type Devices struct {
	ListDevices []Device `xml:"device" json:"device"`
}

//ToString возвращает в символьном виде
func (d *Devices) ToString() string {
	result := "Devices:\n"
	for _, dev := range d.ListDevices {
		result += dev.ToString()
	}
	return result + "\n"
}

//Modbus описание интерфейса мModBus подситемы
type Modbus struct {
	Name        string `xml:"name,attr" json:"name"`
	Description string `xml:"description,attr" json:"desription"`
	Type        string `xml:"type,attr" json:"type"`
	Port        string `xml:"port,attr,omitempty" json:"port"`
	Slave       string `xml:"slave,attr,omitempty" json:"slave"`
	Step        string `xml:"step,attr,omitempty" json:"step"`
	XMLModbus   string `xml:"xml,attr,omitempty" json:"xml"`
}

//ToString возвращает в символьном виде
func (m *Modbus) ToString() string {
	return "\t" + m.Name + "\t:" + m.Description + "\t\t\t" + m.Type + "\t" + m.Port + "\t" + m.Slave + "\t" + m.Step + "\t" + m.XMLModbus + "\n"
}

//Device Перечень драйверов и закрепление переменных на них
type Device struct {
	Name        string `xml:"name,attr" json:"name"`
	Description string `xml:"description,attr" json:"desription"`
	Driver      string `xml:"driver,attr" json:"driver"`
	Slot        string `xml:"slot,attr" json:"slot"`
	Defs        []Def  `xml:"def" json:"def"`
}

//ToString возвращает в символьном виде
func (d *Device) ToString() string {
	result := "Device " + d.Name + ":" + d.Description + " driver=" + d.Driver + ":" + d.Slot + "\n"
	for _, def := range d.Defs {
		result += def.ToString()
	}
	return result + "\n"
}

//Def одна строка свящи переменной с имем на драйвере
type Def struct {
	Name       string `xml:"name,attr" json:"name"`
	DriverName string `xml:",chardata" json:"drivername"`
}

//ToString возвращает в символьном виде
func (d *Def) ToString() string {
	return "<<\t" + d.Name + "\t\t:\t" + d.DriverName + "\n"
}

//Saved сохранениеи переменных на внешний носитель
type Saved struct {
	NameFile string `xml:"name,attr" json:"namefile"`
	Saves    []Save `xml:"save" json:"save"`
}

//ToString возвращает в символьном виде
func (s *Saved) ToString() string {
	result := "Saved " + s.NameFile + "\n"
	for _, sav := range s.Saves {
		result += sav.ToString()
	}
	return result + "\n"
}

// Save описание одной переменной хранения
type Save struct {
	Value string `xml:"value,attr" json:"value"`
	Name  string `xml:",chardata" json:"name"`
}

//ToString возвращает в символьном виде
func (s *Save) ToString() string {
	return ">>\t" + s.Name + "\t\t:\t" + s.Value + "\n"
}

//Variables описание всех переменных модели
type Variables struct {
	ListVariable []Variable `xml:"var" json:"var"`
}

//ToString возвращает в символьном виде
func (v *Variables) ToString() string {
	result := "Variables \n"
	for _, vv := range v.ListVariable {
		result += vv.ToString()
	}
	return result + "\n"
}

//Variable собственно описание переменной
type Variable struct {
	Name        string `xml:"name,attr" json:"name"`
	Description string `xml:"description,attr" json:"desription"`
	Format      string `xml:"format,attr" json:"format"`
	Size        string `xml:"size,attr,omitempty" json:"size"`
}

//ToString возвращает в символьном виде
func (v *Variable) ToString() string {
	return "\t" + v.Name + "\t\t:" + v.Description + "\t\t\t" + v.Format + " " + v.Size + "\n"
}

//FullProject проект полностью
type FullProject struct {
	Project Project
	SubsMap map[string]Subsystem
	ModBus  map[string]Registers
}

//ToString возвращает в символьном виде
func (fp *FullProject) ToString() string {
	result := "FullProject:\n"
	result += fp.Project.ToString()
	for _, sub := range fp.SubsMap {
		result += sub.ToString()
	}
	for v, mb := range fp.ModBus {
		
		result += "Modbus "+v+"\n"+mb.ToString()
	}
	return result + "\n"
}
