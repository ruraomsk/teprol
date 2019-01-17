/*Razdel=[Блоки моделирования объекта управления]*/
/*Name=[Преобразование в код Fas4]*/
#ifndef _toao_H_
#define _toao_H_
typedef struct {
psfloat x; /* name=[x   - входной сигнал] type=in*/
psfloat a; /* name=[a   -  минимальное значение сигнала, который надо подать на ФАС] type=tune*/
psfloat b; /* name=[b   -  максимальное значение сигнала, который надо подать на ФАС] type=tune*/
psfloat c; /* name=[c   - мин. значение кода ФАС] type=tune*/
psfloat d; /* name=[d - макс.  значение кода ФАС] type=tune*/
psint Ter; /* name=[Ter (psint)  - тип неисправности] type=tune*/
psint min; /* name=[min - минимальное возможное значение выходного сигнала] type=tune*/
psint max; /* name=[max - максимальное возможное значение выходного сигнала] type=tune*/
psfloat dis; /* name=[dis - дисперсия "шума"] type=tune*/
psint v; /* name=[y   - выходной сигнал ] type=out*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_toao,_S_toao;
void toao(_lpS_toao toao_s);
#endif
