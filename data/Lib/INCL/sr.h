/*Razdel=[Элементарные функции]*/
/*Name=[Модуль вычисления среднего значения из массива вещественных параметров]*/
#ifndef _sr_H_
#define _sr_H_
typedef struct {
psfloat *x; /* name=[x - массив входных параметров] type=in depend=[n]*/
psint n; /* name=[n - N-размерность массива x] type=tune*/
psfloat y; /* name=[y - среднее значение параметров входного массива] type=out*/
}*_lpS_sr,_S_sr;
void sr(_lpS_sr sr_s);
#endif
