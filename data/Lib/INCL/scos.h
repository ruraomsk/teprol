/*Razdel=[Элементарные функции]*/
/*Name=[Модуль вычисления косинуса]*/
#ifndef _scos_H_
#define _scos_H_
typedef struct {
psfloat x; /* name=[x - входной параметр] type=in*/
psfloat y; /* name=[y - выходной параметр] type=out*/
psbool berr; /* name=[berr - признак недостоверности выходного параметра] type=out*/
}*_lpS_scos,_S_scos;
void scos(_lpS_scos scos_s);
#endif
