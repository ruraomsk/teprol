package project
import(
	"encoding/json"	
)

//LibHeader Заголовок структуры описания библиотечных функций
type LibHeader struct {
	Path    string   `xml:"path,attr" json:"path"`
 	ListHeaders []Header `xml:"header" json:"header"`
}

//ToString вывод содержимого в строку
func (l *LibHeader) ToString() string {
	result:= l.Path + "\n" //+l.Headers.ToString()
	for _, head := range l.ListHeaders {
		result += head.ToString() + "\n"
	}
	return result
}

//Header Заголовок описания одной фуункции
type Header struct {
	Name        string      `xml:"name,attr" json:"name"`
	Description string      `xml:"description,attr" json:"description"`
	Chart       string      `xml:"chart,attr" json:"chart"`
	Pointer     string      `xml:"pointer,attr" json:"pointer"`
	Direct      string      `xml:"direct,attr" json:"direct"`
	Parameters  []Parameter `xml:"parameter" json:"parameter"`
}
//ToJSON вывод в JSON
func (h *Header) ToJSON() ([]byte,error){
	return json.Marshal(h)
}
//ToString вывод содержимого в строку
func (h *Header) ToString() string {
	result := h.Name + "\t" + h.Description + "\t\t" + h.Chart + "\t" + h.Pointer + "\t" + h.Direct + "\n"
	for _, par := range h.Parameters {
		result += par.ToString() + "\n"
	}
	return result
}

//Parameter описание одного параметра
type Parameter struct {
	Name        string `xml:"name,attr" json:"name"`
	Description string `xml:"description,attr" json:"description"`
	Type        string `xml:"type,attr" json:"type"`
	Format      string `xml:"format,attr" json:"format"`
	Size        string `xml:"size,attr,omitempty" json:"size"`
	Depended    string `xml:"depended,attr,omitempty" json:"depended"`
}

//ToString вывод содержимого в строку
func (p *Parameter) ToString() string {
	return p.Name + "\t" + p.Description + "\t\t" + p.Type + "\t" + p.Format + "\t" + p.Size + "\t" + p.Depended
}

