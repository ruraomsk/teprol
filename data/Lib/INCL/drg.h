/*Razdel=[Нелинейные элементы]*/
/*Name=[Модуль 'Двухпозиционное реле с гистерезисом', входной параметр вещественного типа, выходной параметр логического типа]*/
#ifndef _drg_H_
#define _drg_H_
typedef struct {
psfloat x; /* name=[x - входной параметр] type=in*/
psbool a; /* name=[a - A-граница участка насыщения a] type=tune*/
psbool b; /* name=[b - B-граница участка насыщения b] type=tune*/
psfloat e; /* name=[e - E-нижняя граница участка неоднозначности, ед.изм.пар.] type=tune*/
psfloat f; /* name=[f - F-верхняя граница участка неоднозначности, ед.изм.пар.] type=tune*/
psbool y; /* name=[y - выходной параметр] type=out*/
psbool y1; /* name=[y1 - внутренний параметр] type=internal*/
}*_lpS_drg,_S_drg;
void drg(_lpS_drg drg_s);
#endif
