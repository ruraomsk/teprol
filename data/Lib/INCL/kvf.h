/*Razdel=[Модули первичной обработки информации]*/
/*Name=[Контроль времени float]*/
#ifndef _kvf_H_
#define _kvf_H_
typedef struct {
psbool x1; /* name=[x - входной сигнал 1] type=in*/
psbool x2; /* name=[x - входной сигнал 2] type=in*/
psfloat intrv; /* name=[intrv - длительность интервала отсчёта в секундах] type=in*/
psfloat y; /* name=[y - интервал между сигналами х1 и х2 mc] type=out*/
psint imin; /* name=[imin - минуты до конца отсчёта] type=out*/
psint isek; /* name=[isek - секунды до конца отсчёта] type=out*/
psbool x0; /* name=[был приход сигнала x1] type=internal*/
psfloat y0; /* name=[интервал между сигналами х1 и х2] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_kvf,_S_kvf;
void kvf(_lpS_kvf kvf_s);
#endif
