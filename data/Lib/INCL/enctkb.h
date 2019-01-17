/*Razdel=[Модули СУПТ В-1000]*/
/*Name=[Модуль преобразования показаний энкодера в координату]*/
#ifndef _enctkb_H_
#define _enctkb_H_
typedef struct {
psbool  Regim; /* name=[Regim - режим работы-установка смещения/преобразование показаний] type=in*/
psfloat Kt; /* name=[Kt - текущее, известное(контрольное) положение механизма, мм] type=in*/
pslong  Nk; /* name=[Nk - текущее показание энкодера, в тиках] type=in*/
pslong  LeftBound; /* name=[LB - нижняя граница доп.знач энкодера, в тиках] type=tune*/
pslong  RightBound; /* name=[RB - верхняя граница доп.знач энкодера, в тиках] type=tune*/
psfloat C;   /* name=[C - коэффициент для преобразования тиков в мм] type=tune*/
psfloat KtSt; /* name=[KtSt - Стартовое положение механизма, мм] type=tune*/
pslong  Nsm;  /* name=[Nsm - величина смещения координаты относительно 0 энкодера] type=tune*/
psfloat Ytek; /* name=[Ytek - текущее положение механизма с учетом смещения, мм (гр.)] type=out*/
psbool  Sam;  /* name=[Sam- признак настройки смещения] type=out*/
psbool  bErr;  /* name=[bErr- признак наличия ошибки энкодера] type=out*/
pslong  Nk0;  /* name=[Nk0 - предыдущее показание энкодера, в тиках] type=internal*/
psbool  SetFlag; /* name=[SetFlag - признак записи смещения в ЭСППЗУ] type=internal*/
psbool  FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_enctkb,_S_enctkb;
void enctkb(_lpS_enctkb enctkb_s);
#endif
