/*Razdel=[Нелинейные элементы]*/
/*Name=[Модуль сигнализации завершения этапа]*/
#ifndef _newstage_H_
#define _newstage_H_
typedef struct {
psbool caz1; /* name=[сaz1-Разрешено управление механизмом АЗ1] type=in*/
psbool caz2; /* name=[сaz2-Разрешено управление механизмом АЗ2] type=in*/
psbool fin1; /* name=[fin1-завершено движение механизма АЗ1] type=in*/
psbool fin2; /* name=[fin2-завершено движение механизма АЗ2] type=in*/
psbool Let; /* name=[Let-Разрешить новый этап] type=out*/
}*_lpS_newstage,_S_newstage;
void newstage(_lpS_newstage newstage_s);
#endif