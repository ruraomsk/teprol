package project

import (
	"bufio"
	"encoding/xml"
	"io/ioutil"
	"os"
	"rura/teprol/logger"
	"strings"
	"time"

	"github.com/clbanning/mxj"
	"golang.org/x/text/encoding/charmap"
	"golang.org/x/text/transform"
)

//NeedReloadFunction проверяет нужно ли переобновить xml
func NeedReloadFunction(path, namexml string) (bool, error) {
	dirs, err := ioutil.ReadDir(path)
	if err != nil {
		logger.Error.Printf("Ошибка чтения каталога %s %s \n", path, err.Error())
		return false, err
	}
	datexml := time.Unix(0, 0)
	maxdate := time.Unix(0, 0)

	for _, dir := range dirs {
		if dir.IsDir() {
			continue
		}
		if strings.Compare(dir.Name(), namexml) == 0 {
			datexml = dir.ModTime()
			continue
		}
		if !strings.HasSuffix(dir.Name(), ".h") {
			continue
		}
		if dir.ModTime().After(maxdate) {
			maxdate = dir.ModTime()
		}
	}
	return maxdate.After(datexml), nil
}

//MakeFromHeaders создает структуру из заголовков файлов на С
func MakeFromHeaders(path, namexml string, win1251 bool) (libhead LibHeader, err error) {
	libhead.Path = path + "/" + namexml
	libhead.ListHeaders = make([]Header, 0)
	dirs, err := ioutil.ReadDir(path)
	if err != nil {
		logger.Error.Printf("Ошибка чтения каталога %s %s \n", path, err.Error())
		return libhead, err
	}
	for _, dir := range dirs {
		if dir.IsDir() {
			continue
		}
		if !strings.HasSuffix(dir.Name(), ".h") {
			continue
		}
		nfile := path + "/" + dir.Name()
		head, err := LoadOneHeader(nfile, win1251)
		if err != nil {
			logger.Error.Printf("Ошибка загрузки хедера  %s %s \n", nfile, err.Error())
			return libhead, err
		}
		if head != nil {
			libhead.ListHeaders = append(libhead.ListHeaders, *head)
		}
	}
	return libhead, nil
}

//LoadOneHeader зашружает из текстового файла хидер функции
func LoadOneHeader(path string, win1251 bool) (*Header, error) {
	head := new(Header)
	head.Parameters = make([]Parameter, 0)
	file, err := os.Open(path)
	if err != nil {
		logger.Error.Printf("Ошибка открытия %s %s \n", path, err.Error())
		return nil, err
	}
	defer file.Close()
	// fmt.Println("FILE ",path)
	scanner := bufio.NewScanner(file)
	work := false
	for scanner.Scan() {
		str := scanner.Text()
		if len(str) == 0 {
			continue
		}
		if win1251 {
			sr := strings.NewReader(str)
			tr := transform.NewReader(sr, charmap.Windows1251.NewDecoder())
			buf, err := ioutil.ReadAll(tr)
			if err != nil {
				return nil, err
			}
			str = string(buf)
		}
		// fmt.Println(str)
		if strings.HasPrefix(str, "/*Razdel") {
			head.Chart = readPar(str)
			work = true
			continue
		}
		if !work {
			return nil, nil
		}
		if strings.HasPrefix(str, "/*Name") {
			head.Description = readPar(str)
			continue
		}
		if strings.HasPrefix(str, "typedef") {
			continue
		}
		if strings.HasPrefix(str, "void ") {
			end := strings.Index(str, "(")
			if end < 0 {
				head.Name = "ERROR"
			} else {
				head.Name = str[5:end]
			}
			head.Pointer = "_lpS_" + head.Name
			head.Direct = "_S_" + head.Name
			continue
		}
		if strings.HasPrefix(str, "#") {
			continue
		}
		if strings.Contains(str, "_lpS_") {
			continue
		}
		par := new(Parameter)
		par.Format = getFormat(str)
		par.Name = getName(str)
		par.Description = getDescription(str)
		par.Type = getType(str)
		par.Depended = getDepended(str)
		par.Size = getSize(str)
		head.Parameters = append(head.Parameters, *par)

	}
	if err := scanner.Err(); err != nil {
		logger.Error.Printf("Ошибка разбора %s %s \n", path, err.Error())
		return nil, err
	}

	return head, nil
}
func readPar(str string) string {
	start := strings.Index(str, "=[")
	end := strings.Index(str, "]")
	return strings.Replace(str[start+2:end], "\"", "'", -1)
}
func getFormat(str string) string {
	end := strings.Index(str, " ")
	if end < 0 {
		return "ERROR"
	}
	return str[0:end]

}
func getName(str string) string {
	start := strings.Index(str, " ")
	if start < 0 {
		return "ERROR"
	}
	end := strings.Index(str, ";")
	if end < 0 {
		return "ERROR"
	}

	return strings.TrimLeft(strings.TrimLeft(str[start+1:end], " "), "*")
}
func getDescription(str string) string {
	start := strings.Index(str, "name=[")
	if start < 0 {
		return "ERROR"
	}
	str = str[start+6:]
	end := strings.Index(str, "]")
	if end < 0 {
		return "ERROR"
	}
	return strings.Replace(strings.Replace(strings.Replace(str[:end], "\"", "'", -1), ">", ")", -1), "<", "(", -1)
}
func getType(str string) string {
	start := strings.Index(str, "type=")
	if start < 0 {
		return "ERROR"
	}
	str = str[start+5:]
	end := strings.Index(str, " ")
	if end < 0 {
		end = strings.Index(str, "*/")
		if end < 0 {
			return "ERROR"
		}
	}
	return str[:end]
}
func getSize(str string) string {
	start := strings.Index(str, "size=")
	if start < 0 {
		return ""
	}
	str = str[start+5:]
	end := strings.Index(str, " ")
	if end < 0 {
		end = strings.Index(str, "*/")
		if end < 0 {
			return "ERROR"
		}
	}
	return str[:end]
}
func getDepended(str string) string {
	start := strings.Index(str, "depend=[")
	if start < 0 {
		return ""
	}
	str = str[start+8:]
	end := strings.Index(str, "]")
	if end < 0 {
		return "ERROR"
	}
	return str[:end]
}

//SaveLibFunctions сохраняет описание функций в формате XML
func (l *LibHeader) SaveLibFunctions() error {
	path := l.Path
	result, err := xml.Marshal(l)
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
	file, err := os.Create(path)
	if err != nil {
		logger.Error.Println(err.Error())
		return err
	}
	defer file.Close()
	_, err = file.Write(result)
	return err
}

//LoadLibFunctions загружаем из XML
func LoadLibFunctions(path string) (l LibHeader, err error) {
	l.Path = path
	buf, err := ioutil.ReadFile(path)
	if err != nil {
		logger.Error.Println(err.Error())
		return l, err
	}
	err = xml.Unmarshal(buf, &l)
	return l, err
}
