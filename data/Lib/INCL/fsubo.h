/*Razdel=[Элементарные функции]*/
/*Name=[Модуль вычитания вещественных параметров]*/
#ifndef _fsubo_H_
#define _fsubo_H_
typedef struct {
psfloat x1; /* name=[x1 - уменьшаемое] type=in*/
psfloat x2; /* name=[x2 - вычитаемое] type=in*/
psfloat y; /* name=[y - разность y=x1-x2] type=out*/
}*_lpS_fsubo,_S_fsubo;
void fsubo(_lpS_fsubo fsubo_s);
#endif
