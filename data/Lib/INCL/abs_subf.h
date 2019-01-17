/*Razdel=[Элементарные функции]*/
/*Name=[Модуль анализа абсолютного значения разности двух параметров(float)]*/
#ifndef _abs_subf_H_
#define _abs_subf_H_
typedef struct {
psfloat x1; /* name=[х1 - первый входной параметр] type=in*/
psfloat x2; /* name=[х2 - второй входной параметр] type=in*/
psfloat Delta; /* name=[Delta - delta-допустимое рассогласование входных параметров] type=tune*/
psfloat y; /* name=[у - абсолютное значение разности x1 и x2 (y=|x1-x2|)] type=out*/
psbool s; /* name=[s - признак наличия рассогласования между входными параметрами] type=out*/
}*_lpS_abs_subf,_S_abs_subf;
void abs_subf(_lpS_abs_subf abs_subf_s);
#endif