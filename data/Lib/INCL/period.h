/*Razdel=[Метрологическое обеспечение]*/
/*Name=[Модуль вычисления периода разгона реактора]*/
#ifndef _period_H_
#define _period_H_
typedef struct {
psfloat Np; /* name=[Np - мощность РУ (ватт)] type=in*/
psbool  Flerr;  /* name=[Err - флаг неисправности канала] type=in*/
psint n; /* name=[n - размерность массива усреднения потока] type=tune*/
psfloat TiStep; /* name=[TiStep - шаг измерения периода (сек)] type=tune*/
psfloat Tmax; /* name=[Tmax - предельное время ожидания роста потока (сек)] type=tune*/
psfloat Nmin; /* name=[Nmin - нижняя граница интервала мощности для измерения периода (ватт)] type=tune*/
psfloat Period; /* name=[Per - Период разгона РУ] type=out*/
psfloat *tst; /* name=[- массив времени фиксации стартовой мощности] type=internal depend=[n]*/
psfloat *trz; /* name=[- массив времени фиксации очередного периода] type=internal depend=[n]*/
psfloat *N1; /* name=[- массив значения мощности в начале замера] type=internal depend=[n]*/
psfloat *N2; /* name=[- массив значения мощности в конце замера] type=internal depend=[n]*/
psfloat Period0; /* name=[Per - Период разгона РУ] type=internal*/
psbool MyFirstEnterFlag; /* name=[ FirstEnterFlag] type=internal*/

}*_lpS_period,_S_period;
void period(_lpS_period period_s);
#endif
