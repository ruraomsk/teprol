/*Razdel=[Элементарные функции]*/
/*Name=[Вычисление среднего с учётом диагностики]*/
#ifndef _srm_H_
#define _srm_H_
typedef struct {
psfloat *x; /* name=[х - массив значений] type=in depend=[n]*/
psbool *diag; /* name=[ diag - массив диагностики(1-испр)] type=in depend=[n]*/
psint n; /* name=[n - размерность массива] type=tune*/
psint mk; /* name=[mk - минимальное количество корректных данных] type=tune*/
psfloat y; /* name=[Y - среднее значение по корректным данным] type=out*/
psbool az; /* name=[az - признак нарушения количества корректных данных] type=out*/
}*_lpS_srm,_S_srm;
void srm(_lpS_srm srm_s);
#endif
