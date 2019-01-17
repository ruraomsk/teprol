/*Razdel=[Алгоблоки стандартные]*/
/*Name=[Модуль импульсного регулирования мощности реактора в логарифмическом диапазоне]*/
#ifndef _irm_H_
#define _irm_H_
typedef struct {
psfloat wz; /* name=[wz - заданная мощность] type=in*/
psfloat wt; /* name=[wt - текущая мощность] type=in*/
psfloat kz; /* name=[kz - заданная c пульта координата ИМ] type=in*/
psfloat kt; /* name=[kt - текущая координата ИМ] type=in*/
psfloat Tp; /* name=[Tp - текущий период] type=in*/
psfloat Tm; /* name=[Tm - текущая температура] type=in*/
psbool  Avt; /* name=[Avt - разрешение работы регулятора] type=in*/
psfloat Zn; /* name=[Zn - зона нечувствительности, %] type=tune*/
psfloat MinDk; /* name=[MinDk - минимальное изменение координаты, мм] type=tune*/
psfloat MaxKr; /* name=[MaxKr - максимальная координата штока ИМ, мм] type=tune*/
psfloat MaxTime; /* name=[MaxTime - предельное время работы на мощности более 100Вт, сек] type=tune*/
psfloat W1; /* name=[W1 - коэффициент опережения для выхода на разгонную реактивность] type=tune*/
psfloat W2; /* name=[W2 - коэффициент рассогласования по координате для разгонной реактивности] type=tune*/
psfloat W3; /* name=[W3 - коэффициент опережения для выхода на 0-ю реактивность] type=tune*/
psfloat A1; /* name=[A1 - коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью] type=tune*/
psfloat A0; /* name=[A0 - коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью] type=tune*/
psfloat T1; /* name=[T1 - коэффициент t1 ф-ции температурной корректировки ИМ] type=tune*/
psfloat T0; /* name=[T0 - коэффициент t0 ф-ции температурной корректировки ИМ] type=tune*/
psfloat MT1; /* name=[MT1 - коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности] type=tune*/
psfloat MT0; /* name=[MT0 - коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности] type=tune*/
psfloat Nmin; /* name=[Nmin - нижняя граница интервала мощности для измерения периода (ватт)] type=tune*/
psfloat Ktz; /* name=[Ktz - текущее задание по координате ИМ] type=out*/
psfloat Tk; /* name=[Tk - температурная корректировка координаты ИМ] type=out*/
psfloat Rct; /* name=[Rct - рассчётная стартовая реактивность] type=out*/
psfloat kizm; /* name=[ kizm - координата положения ИМ 0-й реактивности ] type=out*/
psbool  Fin; /* name=[Fin - завершение работы регулятора по предельному время работы на мощности] type=out*/
psfloat t100; /* name=[ - время работы на мощности более 100Вт, сек ] type=out*/
psfloat Vf0; /* name=[ - скорость изменения мощности ] type=out*/
psint   stage; /* name=[ - этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание] type=out*/

}*_lpS_irm,_S_irm;
void irm(_lpS_irm irm_s);
#endif
