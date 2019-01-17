package router

import (
	"encoding/xml"
	"fmt"
	"io/ioutil"
	"rura/teprol/logger"
	"strings"
)

//Users описание всех пользователей в системе
type Users struct {
	ListUsers []User `xml:"user"`
}

//User описание одного пользователя
type User struct {
	Name        string `xml:"name,attr"`
	Password    string `xml:"password,attr"`
	Description string `xml:"description,attr,omitempty"`
}

//IsAccept проверяет разрешен ли пользователь
func (u Users) IsAccept(name, password string) (*User, error) {
	for _, user := range u.ListUsers {
		if strings.Compare(user.Name, name) == 0 {
			if strings.Compare(user.Password, password) == 0 {
				return &user, nil
			}
			return nil, fmt.Errorf("Bad password for user %s", name)
		}
	}
	return nil, fmt.Errorf("Not found user %s", name)
}

//LoadAllUsers Загрузка пользователей
func LoadAllUsers(path string) (Users, error) {
	var res Users
	buf, err := ioutil.ReadFile(path)
	if err != nil {
		logger.Error.Println(err.Error())
		return res, err
	}
	err = xml.Unmarshal(buf, &res)
	return res, err
}
