package dataBase

import (
	"database/sql"
	"fmt"
	"rura/teprol/config"
	"rura/teprol/logger"

	_ "github.com/lib/pq"
)

type DBConnect struct {
	db      *sql.DB
	prepare *sql.Stmt
	rows    *sql.Rows
	work    bool
}

func DBConnectMake(conf config.SystemConfig) (conDB DBConnect, err error) {
	// var conDB DBConnect
	conDB.work = false
	dbinfo := fmt.Sprintf("server=%s user=%s password=%s dbname=%s sslmode=disable", conf.ServerDB, conf.UserDB, conf.Password, conf.NameDB)
	conDB.db, err = sql.Open("postgres", dbinfo)
	if err != nil {
		logger.Error.Printf("Запрос на открытие %s ошибка %s", dbinfo, err.Error())
		return
	}
	conDB.work = true
	return
}
func (dbc *DBConnect) Close() {
	dbc.db.Close()
}
func (dbc *DBConnect) Prepare(command string) (err error) {
	if !dbc.work {
		err = fmt.Errorf("Not open database")
		return
	}
	dbc.prepare, err = dbc.db.Prepare(command)
	if err != nil {
		logger.Error.Printf("Операция: %s ошибка %s", command, err.Error())
		dbc.work = false
		return
	}
	return nil
}
func (dbc *DBConnect) Query(command string) (err error) {
	if !dbc.work {
		err = fmt.Errorf("Not open database")
		return
	}
	dbc.rows, err = dbc.db.Query(command)
	if err != nil {
		logger.Error.Printf("Операция: %s ошибка %s", command, err.Error())
		dbc.work = false
		return
	}
	return nil
}
