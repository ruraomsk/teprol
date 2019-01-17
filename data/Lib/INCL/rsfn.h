/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'rsfn-триггер' с приоритетом сброса]*/
#ifndef _rsfn_H_
#define _rsfn_H_
typedef struct {
psbool r; /* name=[r - сигнал сброса R] type=in*/
psfloat s; /* name=[s - входной сигнал S] type=in*/
psfloat q; /* name=[q - выходной параметр] type=out*/
psfloat q0; /* name=[q0 - внутренний параметр] type=internal*/
}*_lpS_rsfn,_S_rsfn;
void rsfn(_lpS_rsfn rsfn_s);
#endif
