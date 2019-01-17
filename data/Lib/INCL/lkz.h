/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Логический клапан' для целочисленного параметра]*/
#ifndef _lkz_H_
#define _lkz_H_
typedef struct {
psint x; /* name=[х - входной параметр] type=in*/
psbool s; /* name=[s - управляющий параметр] type=in*/
psint y; /* name=[у - выходной параметр] type=out*/
}*_lpS_lkz,_S_lkz;
void lkz(_lpS_lkz lkz_s);
#endif
