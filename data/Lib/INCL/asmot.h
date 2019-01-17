/*Razdel=[Блоки моделирования объекта управления]*/
/*Name=[Модель перемещения механизма с шаговым двигателем]*/
#ifndef _asmot_H_
#define _asmot_H_
typedef struct {
psbool RA0;/* name=[ RA0 - движение вперёд] type=in*/
psbool RA1;/* name=[ RA1 - движение назад] type=in*/
psfloat XYvk; /* name=[XYvk - координата мм от ИС] type=in*/
psfloat Vzvk; /* name=[Vzvk - заданная скорость мм/с движения от ИС] type=in*/
psfloat  Vm;/* name=[Vm - Cкорость передвижения (мм/с)] type=tune*/
psfloat  Tp;/* name=[Tp - Тормозной путь мм] type=tune*/
psint   Ter;/* name=[Ter - Неисправности механизма] type=tune*/
psfloat KPav;/* name=[KPav - координата пер.аварийного выключателя механизма мм] type=tune*/
psfloat KZav;/* name=[KZav - координата зад.аварийного выключателя механизма мм] type=tune*/
psfloat KPv;/* name=[KPv - координата пер. выключателя механизма мм] type=tune*/
psfloat KZv;/* name=[KZv - координата зад. выключателя механизма мм] type=tune*/
psfloat Dlt;/* name=[Dlt - зона срабатывания КВ механизма мм] type=tune*/
psfloat  X0;/* name=[ X0 - заданная координата механизма] type=tune*/
psfloat  V0;/* name=[ V0 - заданная скорость механизма] type=tune*/
psfloat   X;/* name=[X - координата механизма] type=out*/
psbool  Pav;/* name=[Pav - Пер.аварийный выключатель механизма] type=out*/
psbool  Zav;/* name=[Zav - Зад.аварийный выключатель механизма] type=out*/
psbool  Pv;/* name=[Pv - Пер. выключатель механизма] type=out*/
psbool  Zv;/* name=[Zv - Зад. выключатель механизма] type=out*/
psfloat  V;/* name=[Vt - текущая скорость механизма] type=out*/
psbool Mup;/* name=[ Mup - фактическое движение вперёд] type=out*/
psbool Mdw;/* name=[ Mdw - фактическое движение назад] type=out*/
psbool Pav0;/* name=[ - Пер.аварийный выключатель механизма] type=internal*/
psbool Zav0;/* name=[ - Зад.аварийный выключатель механизма] type=internal*/
psbool Pv0;/* name=[ - Пер. выключатель механизма] type=internal*/
psbool Zv0;/* name=[ - Зад. выключатель механизма] type=internal*/
psbool RA00;/* name=[ - последнее задание вперед] type=internal*/
psbool RA10;/* name=[ - последнее задание назад] type=internal*/
psbool MyFirstEnterFlag; /* name=[MyFirstEnterFlag] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_asmot,_S_asmot;
void asmot(_lpS_asmot asmot_s);
#endif