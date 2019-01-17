/*Razdel=[Элементарные функции]*/
/*Name=[Модуль 'Усилитель', умножение вещественного параметра на коэффициент]*/
#ifndef _ampl_H_
#define _ampl_H_
typedef struct {
psfloat x; /* name=[x - входной параметр] type=in*/
psfloat k; /* name=[k - коэффициент усиления] type=tune*/
psfloat y; /* name=[y - выходной параметр] type=out*/
}*_lpS_ampl,_S_ampl;
void ampl(_lpS_ampl ampl_s);
#endif
