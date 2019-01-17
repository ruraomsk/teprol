/*Razdel=[Преобразователи типов]*/
/*Name=[Преобр. символьной переменной в целочисленную]*/
#ifndef _charint_H_
#define _charint_H_
typedef struct {
pschar x; /* name=[X] type=in*/
psint y; /* name=[Y] type=out*/
}*_lpS_charint,_S_charint;
void charint(_lpS_charint charint_s);
#endif
