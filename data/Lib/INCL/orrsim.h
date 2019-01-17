/*Razdel=[Блоки моделирования объекта управления]*/
/*Name=[Модель перемещения ОРР с шаговым двигателем]*/
#ifndef _orrsim_H_
#define _orrsim_H_
typedef struct {
psbool RA0;/* name=[ RA0 - движение вперёд] type=in*/
psbool RA1;/* name=[ RA1 - движение назад] type=in*/
psbool RA2;/* name=[ RA2 - 0-й бит скорости] type=in*/
psbool RA3;/* name=[ RA3 - разрешение движения] type=in*/
psbool RA4;/* name=[ RA4 - 1-й бит скорости] type=in*/
psbool RA5;/* name=[ RA5 - 2-й бит скорости] type=in*/
psbool RB3;/* name=[ RB3 - паритет команды (нечет)] type=in*/ 
psbool Klo;/* name=[ Klo - Клапан «Сброс ОРР» открыть (обесточить)] type=in*/ 
psbool Klz;/* name=[ Klz - Клапан «Подъём ОРР» открыть (обесточить)] type=in*/ 
psbool EMo;/* name=[ EMo - Обесточить электромагнит ОРР] type=in*/ 
psfloat Xk; /* name=[Xk - координата ОРР мм от ИС] type=in*/
psfloat Shk; /* name=[Shk - координата штока ОРР мм от ИС] type=in*/
psfloat IRV; /* name=[XV - заданная скорость мм/с движения ОРР от ИС] type=in*/
psfloat IShV; /* name=[ShV - заданная скорость шагов/с движения штока ОРР от ИС] type=in*/
psbool IsMg;/* name=[ IsMg - Флаг наличия магнита на штоке ОРР] type=tune*/
psfloat *Vr;/* name=[*Vm - массив скоростей движения (шагов в секунду)] type=tune size = 8*/
psfloat Kpr;/* name=[Kpr - Коэффициент преобразования частоты двигателя в скорость ОРР мм/с] type=tune*/
psfloat Pup;/* name=[Pup - давление в системе на подъем ] type=tune*/
psfloat Pdw;/* name=[Pdw - давление в системе на сброс] type=tune*/
psfloat Ldemp;/* name=[Ldemp - расстояние включения масляного демпфера] type=tune*/
psfloat Tau;/* name=[Tau - постоянная времени масляного демпфера(сек)] type=tune*/
psfloat Aps;/* name=[Aps - ускорение сброса от пневматики - g (мм/с^2)] type=tune*/
psint   Ter;/* name=[Ter - Неисправности ОРР] type=tune*/
psfloat KPpv;/* name=[KPpv - координата промежуточного путевого выключателя ОРР мм] type=tune*/
psfloat KPav;/* name=[KPav - координата пер.аварийного выключателя ОРР мм] type=tune*/
psfloat KZav;/* name=[KZav - координата зад.аварийного выключателя ОРР мм] type=tune*/
psfloat Dlt;/* name=[Dlt - зона срабатывания КВ механизма мм] type=tune*/
psfloat X0;/* name=[X0 - координата ОРР] type=tune*/
psfloat Sh0;/* name=[Sh0 - координата штока ОРР] type=tune*/
psfloat RV0;/* name=[V0 - текущая скорость ОРР] type=tune*/
psfloat ShV0;/* name=[V0 - текущая скорость штока ОРР] type=tune*/
psfloat X;/* name=[X - координата ОРР] type=out*/
psfloat Sh;/* name=[Sh - координата штока ОРР] type=out*/
psbool  Ppv;/* name=[Ppv - Промежуточный путевой выключатель ОРР(80 мм)] type=out*/
psbool  Pav;/* name=[Pav - Пер.аварийный выключатель ОРР(ВУ)] type=out*/
psbool  Zav;/* name=[Zav - Зад.аварийный выключатель ОРР(НУ)] type=out*/
psfloat RV;/* name=[RV - текущая скорость ОРР мм/с] type=out*/
psfloat ShV;/* name=[ShV - текущая скорость штока ОРР мм/с] type=out*/
psbool SKlo;/* name=[SKlo - Клапан «Сброс ОРР» открыт (обесточен)] type=out*/
psbool SKlz;/* name=[SKlz - Клапан «Подъём ОРР» открыт (обесточен)] type=out*/
psbool SEMo;/* name=[SEMo - Обесточен электромагнит ОРР] type=out*/
psbool SZMo;/* name=[SZMo - зацеплен электромагнит ОРР] type=out*/
psbool Ppv0;/* name=[Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)] type=internal*/
psbool Pav0;/* name=[Pav0 - Пер.аварийный выключатель ОРР] type=internal*/
psbool Zav0;/* name=[Zav0 - Зад.аварийный выключатель ОРР] type=internal*/
psbool RA00;/* name=[RA00 - последнее задание вперед] type=internal*/
psbool RA10;/* name=[RA10 - последнее задание назад] type=internal*/
pschar RA50;/* name=[Ra50 - последнее задание скорости] type=internal*/
psbool  fls;/* name=[ fls - флаг одношагового режима] type=internal*/
psbool  flp;/* name=[ flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)] type=internal*/
psbool MyFirstEnterFlag; /* name=[MyFirstEnterFlag] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_orrsim,_S_orrsim;
void orrsim(_lpS_orrsim orrsim_s);
#endif
