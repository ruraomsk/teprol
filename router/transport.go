package router

import (
	"bytes"
	"net"
	"rura/teprol/logger"
	"strconv"
	"strings"
)

//Connection хранение соединения
type Connection struct {
	user *User
	conn net.Conn
}

//ReadMessage чтение сообщения
func (con Connection) ReadMessage() (req Request, err error) {
	req.Body = make([]byte, 0)
	req.Command = ""
	req.PartOne = ""
	req.PartTwo = ""
	var result bytes.Buffer
	buffer := make([]byte, 2048)
	var reqLen int
	work := true
	for work {
		reqLen, err = con.conn.Read(buffer)
		if err != nil {
			// logger.Error.Printf("Error for reading  %s", err.Error())
			return
		}
		if reqLen == 0 {
			break
		}
		index := 0
		for ; index < reqLen; index++ {
			if buffer[index] == 255 {
				work = false
				break
			}
		}
		result.Write(buffer[:index])
	}
	reqBody := bytes.Split(result.Bytes(), []byte{0, 255})
	text := string(reqBody[0][:])
	if len(reqBody) > 1 {
		req.Body = reqBody[1][:]
	}
	res := strings.Split(text, " ")
	if len(res) > 0 {
		req.PartOne = res[0]
	}
	if len(res) > 1 {
		req.PartTwo = res[1]
	}
	if len(res) > 2 {
		req.Command = res[2]
	}
	return req, nil
}

//SendMessage передача сообщения
func (con Connection) SendMessage(msg Responce) error {
	var result bytes.Buffer
	result.WriteString(msg.PartOne + " ")
	result.WriteString(msg.PartTwo + " ")
	result.WriteString(msg.Command)
	result.WriteByte(0)
	result.WriteString(msg.Status)
	result.WriteByte(0)

	for _, body := range msg.Bodys {
		result.WriteString(body.Header)
		result.Write(body.Body)
		result.WriteByte(0)
	}
	result.WriteByte(255)
	_, err := con.conn.Write(result.Bytes())
	return err
}

var allChans ChanelsRouters
var listUsers Users

//Transport протокол обмена с клиентами
func Transport(port int, canals ChanelsRouters, users Users) {
	allChans = canals
	listUsers = users
	listen, err := net.Listen("tcp", ":"+strconv.Itoa(port))
	if err != nil {
		logger.Error.Printf("Ошибка при listen %d %s", port, err.Error())
		panic(err.Error())
	}
	for {
		conn, err := listen.Accept()
		if err != nil {
			logger.Error.Printf("Ошибка при accept %s", err.Error())
			continue
		}
		go newUser(conn)
	}
}
func newUser(conn net.Conn) {
	var conUser Connection
	conUser.conn = conn
	request, err := conUser.ReadMessage()
	if err != nil {
		logger.Error.Printf("read message  %s ", err.Error())
		conn.Close()
		return
	}
	responce := request.NewResponce()
	user, err := listUsers.IsAccept(request.PartTwo, request.Command)
	if err != nil {
		logger.Error.Printf("login user %s ", err.Error())
		responce.SetOk(err)
		conUser.SendMessage(responce)
		conn.Close()
		return
	}
	conUser.user = user
	responce.SetOk(nil)
	conUser.SendMessage(responce)
	for {
		request, err := conUser.ReadMessage()
		if err != nil {
			if len(request.PartOne) != 0 || len(request.PartOne) != 0 || len(request.Command) != 0 {
				logger.Error.Printf("read message  %s ", err.Error())
				conn.Close()
			}
			return
		}
		// logger.Debug.Print("read message  %s %s %s", request.PartOne, request.PartTwo, request.Command)

		switch request.PartOne {
		case "library":
			allChans.LibRouter.Input <- request
			responce = <-allChans.LibRouter.Output
			conUser.SendMessage(responce)
			continue
		case "modbus":
			allChans.ModBus.Input <- request
			responce = <-allChans.ModBus.Output
			conUser.SendMessage(responce)
			continue
		case "subsystem":
			allChans.Subs.Input <- request
			responce = <-allChans.Subs.Output
			conUser.SendMessage(responce)
			continue
		case "drivers":
			allChans.Drivers.Input <- request
			responce = <-allChans.Drivers.Output
			conUser.SendMessage(responce)
			continue
		case "project":
			allChans.Project.Input <- request
			responce = <-allChans.Project.Output
			conUser.SendMessage(responce)
			continue

		}

	}

}
