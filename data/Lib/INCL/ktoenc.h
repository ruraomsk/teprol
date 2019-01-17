/*Razdel=[Модули СУПТ В-1000]*/
/*Name=[Модуль преобразования координаты в показания энкодера]*/
#ifndef _ktoenc_H_
#define _ktoenc_H_
typedef struct {
psfloat Xtek; /* name=[Xtek - текущее положение механизма, мм] type=in*/
psfloat C; /* name=[C - коэффициент для преобразования тиков в мм] type=tune*/
psfloat CNsm; /* name=[CNsm - величина смещения, мм] type=tune*/
psint Ter; /* name=[Ter - тип неисправности] type=tune*/
pslong Ytek; /* name=[Ytek - текущее положение механизма в тиках] type=out*/
psbool Mov; /* name=[Mov - признак движения] type=out*/
psbool ClkW; /* name=[ClkW - движение по часовой стрелке ] type=out*/
psbool UnClkW; /* name=[UnClkW - движение против часовой стрелки] type=out*/
pslong Enc; /* name=[Enc - данные, которые должны быть считаны драйвером vencf] type=out*/
psfloat Xtek0;  /* name=[Xtek0 - положение механизма на прошлом шаге, мм] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_ktoenc,_S_ktoenc;
void ktoenc(_lpS_ktoenc ktoenc_s);
#endif
