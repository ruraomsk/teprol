/*Razdel=[Модули первичной обработки информации]*/
/*Name=[Алгоритм расчёта реактивности реактора по периоду разгона]*/
#ifndef _react_H_
#define _react_H_
typedef struct {
psfloat t; /* name=[t-период разгона] type=in*/
psfloat r; /* name=[r - текущая реактивность РУ] type=out*/
}*_lpS_react,_S_react;
void react(_lpS_react react_s);
#endif
