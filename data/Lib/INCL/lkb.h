/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Логический клапан' для логического параметра]*/
#ifndef _lkb_H_
#define _lkb_H_
typedef struct {
psbool x; /* name=[x - входной параметр] type=in*/
psbool s; /* name=[s - управляющий параметр] type=in*/
psbool y; /* name=[y - выходной параметр] type=out*/
}*_lpS_lkb,_S_lkb;
void lkb(_lpS_lkb lkb_s);
#endif
