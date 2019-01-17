/*Razdel=[Блоки моделирования объекта управления]*/
/*Name=[Модель реактора (точечная)]              */
#ifndef _azbars_H_
#define _azbars_H_
typedef struct {
psfloat Kbb; /* name=[Kbb - координата ББ] type=in*/
psfloat Krb; /* name=[Krb - координата РБ] type=in*/
psfloat Kis; /* name=[Kis- координата ИС] type=in*/
psfloat N2; /* name=[N2 - концентрация нейтронов другой АЗ] type=in*/
psfloat RIt;   /* name=[RIt - реактивность, вносимая облучаемыми образцами] type=in*/
psbool  BlowOut;   /* name=[BlowOut - Клапан "Обдув АЗ" открыть (обесточить)] type=in*/
psbool  NIatVU;   /* name=[NIatVU - Нейтронный Источник на ВУ] type=in*/
psbool  IsANI;   /* name=[IsANI - Аварийный нейтронный источник установлен] type=in*/
psbool  ImpINI;   /* name=[ImpINI - Запуск системы инициирования] type=in*/
psfloat Lg; /* name=[Lg - Среднее время генерации миллиона нейтронов] type=tune*/
psfloat Bz; /* name=[Bz - доля запаздывающих нейтронов в общем количестве нейтронов] type=tune*/ 
psfloat AT; /* name=[AT - Температурный коэффициент ]type=tune*/
psfloat MT; /* name=[MT - Масса топлива в АЗ(кГ)] type=tune*/
psfloat CT; /* name=[CT - Удельная теплоёмкость топлива кДж/кГ*град] type=tune*/
psfloat EN; /* name=[EN - Энергия 1 деления ядра  (Дж) * E^-13] type=tune*/
psfloat EVt; /* name=[EVt - Кол-во делений/сек на 1 ватт * E^6] type=tune*/
psfloat Sani; /* name=[Sani - мощность источника нейтронов при наличии АНИ] type=tune*/
psfloat Sno; /* name=[Sno - мощность источника нейтронов без АНИ] type=tune*/
psfloat ABB0; /* name=[ABB0 - Коэффициент-0 функции реактивности вносимой ББ] type=tune*/
psfloat ABB1; /* name=[ABB1 - Коэффициент-1 функции реактивности вносимой ББ] type=tune*/
psfloat ARB0; /* name=[ARB0 - Коэффициент-0 функции реактивности вносимой РБ] type=tune*/
psfloat ARB1; /* name=[ARB1 - Коэффициент-1 функции реактивности вносимой РБ] type=tune*/
psfloat AIS0; /* name=[AIS0 - Коэффициент-0 функции реактивности вносимой ИС] type=tune*/
psfloat AIS1; /* name=[AIS1 - Коэффициент-1 функции реактивности вносимой ИС] type=tune*/
psfloat K11; /* name=[K11 - Коэффициент 11 связи АЗ1,2] type=tune*/
psfloat K12; /* name=[K12 - Коэффициент 12 связи АЗ1,2] type=tune*/
psfloat Tn0; /* name=[Tn0 - нормальная температура АЗ] type=tune*/
psfloat RBlow; /* name=[RBlow - конвекционное сопротивление при обдуве] type=tune*/
psfloat N0; /* name=[N0 - Стартовая концентрация нейтронов] type=tune*/
psfloat R0; /* name=[R0 - Стартовая реактивность] type=tune*/
psfloat T0; /* name=[T0 - Стартовая температура] type=tune*/
psfloat N; /* name=[N - концентрация нейтронов] type=out*/
psfloat Pn; /* name=[Pn - поток нейтронов(нейтр/с)] type=out*/
psfloat R; /* name=[R - текущая реактивность] type=out*/
psfloat T; /* name=[T - текущая температура] type=out*/
psbool  IsBlow;   /* name=[IsBlow - Клапан "Обдув АЗ" открыт (обесточен)] type=out*/
psfloat Period; /* name=[Period - период разгона РУ] type=out*/
psfloat Npn;  /* name=[Npn- мощность потока нейтронов(ватт)] type=out */
psfloat C1; /* name=[C1 - концентрация запаздывающих нейтронов 1-го типа] type=internal*/
psfloat C2; /* name=[C2 - концентрация запаздывающих нейтронов 2-го типа] type=internal*/
psfloat C3; /* name=[C3 - концентрация запаздывающих нейтронов 3-го типа] type=internal*/
psfloat C4; /* name=[C4 - концентрация запаздывающих нейтронов 4-го типа] type=internal*/
psfloat C5; /* name=[C5 - концентрация запаздывающих нейтронов 5-го типа] type=internal*/
psfloat C6; /* name=[C6 - концентрация запаздывающих нейтронов 6-го типа] type=internal*/
psfloat N20; /* name=[N20 - пред. концентрация нейтронов второй АЗ] type=internal*/
psfloat *C0; /* name=[*C0 - пред. концентрация запаздывающих нейтронов] type=internal size=6 */ 
psbool  ImpINI0;   /* name=[ImpINI - Запуск системы инициирования(пред.)] type=internal*/
psbool MyFirstEnterFlag; /* name=[MyFirstEnterFlag] type=internal*/
psbool FirstEnterFlag; /* name=[ FirstEnterFlag] type=internal*/
}*_lpS_azbars,_S_azbars;
void azbars(_lpS_azbars azbars_s);
#endif