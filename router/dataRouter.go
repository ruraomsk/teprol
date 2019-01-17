package router

import (
	"encoding/json"
	"rura/teprol/project"
	"strings"
	"time"
)

//ListItems ответ по списку
type ListItems struct {
	ListItems []OneItem `json:"listitems"`
}

//Init инициалищация
func (l *ListItems) Init() {
	l.ListItems = make([]OneItem, 0)
}

//Append добавить элемент
func (l *ListItems) Append(a OneItem) {
	l.ListItems = append(l.ListItems, a)
}

//UpdateTime установить время последнего изменения
func (l *ListItems) UpdateTime(name string) {
	for _, item := range l.ListItems {
		if strings.Compare(name, item.Name) == 0 {
			item.LastTime = time.Now()
			return
		}
	}
}

//OneItem описание одноой позиции
type OneItem struct {
	Name        string    `json:"name"`
	Description string    `json:"description"`
	LastTime    time.Time `json:"time"`
}

//ToJSON вывод в формате Json
func (l *ListItems) ToJSON() ([]byte, error) {
	return json.Marshal(l)
}

//ChanelsRouters Структура хранения всех каналов роутеров
type ChanelsRouters struct {
	LibRouter  ChansRouter
	Drivers    ChansRouter
	Subs       ChansRouter
	ModBus     ChansRouter
	Project    ChansRouter
	CommonChan chan string
}

//ChansRouter Собственно описание двух каалов ввода вывода
type ChansRouter struct {
	Input  chan Request
	Output chan Responce
}

//Init Создает каналы обмена
func (c *ChansRouter) Init() {
	c.Input = make(chan Request)
	c.Output = make(chan Responce)
}

// var stopCommand = "stop"
// var listCommand = "list"

//AllChans хранение всех каналов роутеров
var AllChans ChanelsRouters

//InitChans настраивает область хранения всех каналов
func InitChans(prs []project.FullProject) ChanelsRouters {
	AllChans.CommonChan = make(chan string)
	AllChans.LibRouter.Init()
	AllChans.Drivers.Init()
	AllChans.Subs.Init()
	AllChans.ModBus.Init()
	AllChans.Project.Init()
	return AllChans
}
