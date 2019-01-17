/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Мультиплексор арифметический' для вещественных параметров]*/
#ifndef _ma_H_
#define _ma_H_
typedef struct {
psfloat *x; /* name=[x - массив входных параметров] type=in depend=[n]*/
psint r; /* name=[r - управляющий параметр] type=in*/
psint n; /* name=[n - N-размерность массива x] type=tune*/
psfloat y; /* name=[y - выходной параметр] type=out*/
}*_lpS_ma,_S_ma;
void ma(_lpS_ma ma_s);
#endif
