/*Razdel=[Элементарные функции]*/
/*Name=[Модуль вычисления натурального логарифма]*/
#ifndef _lnn_H_
#define _lnn_H_
typedef struct {
psfloat x; /* name=[x - аргумент] type=in*/
psfloat y; /* name=[y - выходной параметр y=ln(x)] type=out*/
}*_lpS_lnn,_S_lnn;
void lnn(_lpS_lnn lnn_s);
#endif
