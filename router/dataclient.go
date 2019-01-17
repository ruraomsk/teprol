package router

import (
	"strconv"
)

//Request типовой запрос
type Request struct {
	PartOne string
	PartTwo string
	Command string
	Body    []byte
}

//ToString в строку
func (r Request) ToString() string {
	return "Запрос \t" + r.PartOne + "\t" + r.PartTwo + "\t" + r.Command + "\t" + string(r.Body)
}

//Responce типовой ответ
type Responce struct {
	PartOne string
	PartTwo string
	Command string
	Status  string
	Bodys   map[int]Body
}

//Body собственно тело ответа
type Body struct {
	Header string
	Body   []byte
}

//ToString в строку
func (r Responce) ToString() string {
	result := "Ответ \t" + r.PartOne + "\t" + r.PartTwo + "\t" + r.Command + "\t" + r.Status + "\n"
	for i, body := range r.Bodys {
		result += "Body" + strconv.Itoa(i) + "\t" + body.Header + ":\t" + string(body.Body) + "\n"
	}
	return result
}

//NewResponce создает новый ответ на основе запроса
func (r *Request) NewResponce() Responce {
	var rs Responce
	rs.PartOne = r.PartOne
	rs.PartTwo = r.PartTwo
	rs.Command = r.Command
	rs.Status = "undefine"
	rs.Bodys = make(map[int]Body)
	return rs
}

//SetBody сохранить тело
func (r Responce) SetBody(number int, format string, body []byte) {
	r.Bodys[number] = Body{Header: format, Body: body}
}

//SetOk Установить значение статуса в Ок
func (r *Responce) SetOk(err error) {
	r.Status = "Ok"
	if err != nil {
		r.Status = err.Error()
	}
}
