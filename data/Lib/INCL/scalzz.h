/*Razdel=[Модули первичной обработки информации]*/
/*Name=[Модуль масштабирования вых.сигнала (цел.) c контролем обрыва]*/
#ifndef _scalzz_H_
#define _scalzz_H_
typedef struct {
psint x; /* name=[x] type=in*/
psint a; /* name=[a] type=tune*/
psint b; /* name=[b] type=tune*/
psfloat c; /* name=[c] type=tune*/
psfloat d; /* name=[d] type=tune*/
psfloat y; /* name=[y] type=out*/
psfloat y0; /* name=[y0] type=internal*/
}*_lpS_scalzz,_S_scalzz;
void scalzz(_lpS_scalzz scalzz_s);
#endif
