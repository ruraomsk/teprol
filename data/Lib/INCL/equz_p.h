/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Равно параметру']*/
#ifndef _equz_p_H_
#define _equz_p_H_
typedef struct {
psint x; /* name=[x - входной параметр] type=in*/
psint p; /* name=[p - настроечное значение] type=tune*/
psbool y; /* name=[y - признак равенства x=p] type=out*/
}*_lpS_equz_p,_S_equz_p;
void equz_p(_lpS_equz_p equz_p_s);
#endif