/*Razdel=[Алгоблоки стандартные]*/
/*Name=[Модуль формирования одиночных импульсов (одновибратор) при постоянном входном параметре]*/
#ifndef _ovb1_H_
#define _ovb1_H_
typedef struct {
psbool x; /* name=[x - входной параметр] type=in*/
psint tz; /* name=[tz - ширина импульса, 10-ки мс] type=tune*/
psbool y; /* name=[y - выходной параметр] type=out*/
psint tx; /* name=[tx - внутренний параметр] type=internal*/
}*_lpS_ovb1,_S_ovb1;
void ovb1(_lpS_ovb1 ovb1_s);
#endif

