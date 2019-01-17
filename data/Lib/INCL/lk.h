/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Логический клапан' для вещественного параметра]*/
#ifndef _lk_H_
#define _lk_H_
typedef struct {
psfloat x; /* name=[x - входной параметр] type=in*/
psbool s; /* name=[s - управляющий параметр] type=in*/
psfloat y; /* name=[y - выходной параметр] type=out*/
}*_lpS_lk,_S_lk;
void lk(_lpS_lk lk_s);
#endif
