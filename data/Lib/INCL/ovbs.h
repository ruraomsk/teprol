/*Razdel=[Алгоблоки стандартные]*/
/*Name=[Модуль формирования одиночных импульсов (одновибратор) при постоянном входном параметре]*/
#ifndef _ovbs_H_
#define _ovbs_H_
typedef struct {
psbool x; /* name=[x - входной параметр] type=in*/
psfloat tz; /* name=[tz - ширина импульса, sek] type=tune*/
psbool y; /* name=[y - выходной параметр] type=out*/
psfloat tx; /* name=[tx - внутренний параметр] type=internal*/
}*_lpS_ovbs,_S_ovbs;
void ovbs(_lpS_ovbs ovbs_s);
#endif
