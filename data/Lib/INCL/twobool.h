/*Razdel=[Блоки моделирования объекта управления]*/
/*Name=[Размножение логического сигнала на 2]*/
#ifndef _twobool_H_
#define _twobool_H_
typedef struct {
psbool S; /* name=[S (psbool)  - входной сигнал] type=in*/

psint Ter; /* name=[Ter (psint)  - тип неисправности] type=tune*/

psbool Out1; /* name=[Out1 (psbool) - первый выходной сигнал] type=out*/
psbool Out2; /* name=[Out2 (psbool) - второй выходной сигнал] type=out*/

psbool Out10; /* name=[Out10 (psbool) - прошлое значение выходного сигнала] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_twobool,_S_twobool;
void twobool(_lpS_twobool twobool_s);
#endif

