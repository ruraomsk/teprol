/*Razdel=[Блоки моделирования объекта управления]*/
/*Name=[модель размножения вещественного сигнала]*/
#ifndef _to3val_H_
#define _to3val_H_
typedef struct {
psfloat x1; /* name=[x1 - входной сигнал] type=in*/
psfloat ampl; /* name=[ampl - амплетуда синусоидального отклонения] type=tune*/
psfloat m1; /* name=[m1 - величина отклонения второго сигнала от входного] type=tune*/
psfloat m2; /* name=[m2 - величина отклонения третьего сигнала от входного] type=tune*/
psfloat dis; /* name=[dis - дисперсия отклонения сигналов] type=tune*/
psfloat maxs1; /* name=[maxs1 - макc. значение второго сигнала] type=tune*/
psfloat maxs2; /* name=[maxs2 - макc. значение третьего сигнала] type=tune*/
psint Ter; /* name=[Ter (psint)  - тип неисправности] type=tune*/
psfloat y1; /* name=[y1 - выходной сигнал] type=out*/
psfloat y2; /* name=[y2 - выходной сигнал] type=out*/
psfloat y3; /* name=[y3 - выходной сигнал] type=out*/
psbool FirstEnterFlag; /* name=[FirsEnterFlag] type=internal*/
}*_lpS_to3val,_S_to3val;
void to3val(_lpS_to3val to3val_s);
#endif
