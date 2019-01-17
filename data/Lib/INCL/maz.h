/*Razdel=[Ћогические звень€]*/
/*Name=[ћультиплексор арифметический целочисленный]*/
#ifndef _maz_H_
#define _maz_H_
typedef struct {
psint *x; /* name=[x - массив входных сигналов] type=in depend=[n]*/
psint r; /* name=[r - управл€ющий сигнал] type=in*/
psint n; /* name=[n - размерность входного массива] type=tune*/
psint y; /* name=[y - выходной сигнал] type=out*/
}*_lpS_maz,_S_maz;
void maz(_lpS_maz maz_s);
#endif
