/*Razdel=[Элементарные функции]*/
/*Name=[Модуль 'Сумматор' вещественных параметров на два входа]*/
#ifndef _fsumo_H_
#define _fsumo_H_
typedef struct {
psfloat x1; /* name=[x1 - первое слагаемое] type=in*/
psfloat x2; /* name=[x2 - второе слагаемое] type=in*/
psfloat y; /* name=[y - сумма y=x1+x2] type=out*/
}*_lpS_fsumo,_S_fsumo;
void fsumo(_lpS_fsumo fsumo_s);
#endif
