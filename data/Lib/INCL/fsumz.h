/*Razdel=[Элементарные функции]*/
/*Name=[Модуль 'Сумматор' целочисленных параметров на два входа]*/
#ifndef _fsumz_H_
#define _fsumz_H_
typedef struct {
psint x1; /* name=[x1 - первое слагаемое] type=in*/
psint x2; /* name=[x2 - второе слагаемое] type=in*/
psint y; /* name=[y - сумма y=x1+x2] type=out*/
}*_lpS_fsumz,_S_fsumz;
void fsumz(_lpS_fsumz fsumz_s);
#endif
