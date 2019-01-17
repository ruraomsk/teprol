/*Razdel=[Модули Bars4]*/
/*Name=[Модуль определения фактического направления движения механизма]*/
#ifndef _fnapb_H_
#define _fnapb_H_
typedef struct {
psfloat x; /* name=[x - текущее  положение механизма в мм] type=in*/
psfloat xz; /* name=[xz - заданное положение механизма в мм] type=in*/
psbool CheckSpeed; /* name=[CheckSpeed - признак измерения скорости] type=in*/
psbool KvitSam; /* name=[KvitSam - квитирование самохода] type=in*/
psbool Dvig; /* name=[Dvig - есть команда на движение] type=in*/
psfloat Vz; /* name=[Vz - заданная скорость, м/мин] type=in*/

psfloat Trz; /* name=[Trz - время разгона механизма при переходе на новую скорость] type=tune*/
psfloat Delta; /* name=[Delta - допустимое превышение скорости,м/мин] type=tune*/
psfloat MDelta; /* name=[MDelta - допустимое уменьшение скорости,м/мин] type=tune*/
psfloat p; /* name=[p - уставка опеределения самохода в мм(гр.)] type=tune*/
psfloat pl; /* name=[pl - Минимальное перемещение для измерения скорости в мм(гр.)] type=tune*/
psint n;  /* name=[n - размерность массива мгновенных значений] type=tune*/
psfloat tz; /* name=[tz - длительность переходного процесса остановки sek] type=tune*/
psfloat tnm; /* name=[tnm - уставка срабатывания блокировки по недвижению sek] type=tune*/
psfloat tzZS; /* name=[tzZS - время задержки самохода после достижения 0 скорости sek] type=tune*/

psbool ToLeft; /* name=[ToLeft - ход влево,вперёд,вверх,прот.часовой] type=out*/
psbool ToRight; /* name=[ToRight - ход вправо,назад,вниз,по.часовой] type=out*/
psfloat Speed; /* name=[Speed - скорость перемещения] type=out*/
psbool Shift; /* name=[Shift - признак самохода] type=out*/
psbool NoMove; /* name=[NoMove - блокировка по отсутствию перемещения] type=out*/
psbool Bl; /* name=[Bl - блокировка по превышению скорости] type=out*/
psbool MBl; /* name=[MBl - блокировка по отклонению скорости в меньшую сторону] type=out*/
psfloat SrcPoint; /* name=[SrcPoint - начальная точка из которой произошел самоход] type=out*/

psint xptr; /* name=[указатель текущей позиции в массиве координат] type=internal*/
psfloat *x0; /* name=[x0 - массив мгновенных значений координат] type=internal depend=[n]*/
psfloat *tim0; /* name=[tim0 - массив значений времени цикла] type=internal depend=[n]*/
psint mcount; /* name=[count - счетчик заполнения массива значений координат] type=internal*/
psfloat sumtim; /* name=[sumtim - время в пути] type=internal*/
psfloat sumtakt; /* name=[sumtim - время в пути] type=internal*/
psfloat StSpeed; /* name=[StSpeed - стартовая скорость - с которой начинается изменение скорости] type=internal*/
psfloat Vz0; /* name=[Vz0 - предыдущая заданная скорость] type=internal*/
psint flRazg; /* name=[признак разгона/торможения] type=internal*/
psfloat DelSp; /* name=[DelSp - время переключения скоростей] type=internal*/
psfloat z0; /* name=[z0 - точка прекращения движения] type=internal*/
psfloat txZS; /* name=[txZS] type=internal*/
psfloat tx; /* name=[tx] type=internal*/
psfloat txd; /* name=[txd] type=internal*/
psfloat txMBl; /* name=[tx] type=internal*/
psfloat txBl; /* name=[tx] type=internal*/
psfloat Speed0; /* name=[Speed0 - предыдущее значение скорости перемещения] type=internal*/
psfloat xz0; /* name=[xz0 - новое задание мм] type=internal*/
psfloat tz0; /* name=[tz0 - время защиты от нового задания сек] type=internal*/
psbool Shift0; /* name=[Shift0 - признак самохода] type=internal*/
psbool ShCntlSp0; /* name=[ShCntlSp0 - признак выдержки времени после достижения 0 скорости] type=internal*/
psbool ShiftControl; /* name=[ShiftControl - признак самохода] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_fnapb,_S_fnapb;
void fnapb(_lpS_fnapb fnapb_s);
#endif
