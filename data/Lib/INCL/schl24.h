/*Razdel=[Логические звенья]*/
/*Name=[Логический модуль " Счетчик 2 из 4 "]*/
#ifndef _schl24_H_
#define _schl24_H_
typedef struct {
psbool x1; /* name=[X1 - вход] type=in*/
psbool x2; /* name=[X2 - вход] type=in*/
psbool x3; /* name=[X3 - вход] type=in*/
psbool x4; /* name=[X4 - вход] type=in*/
psbool y; /* name=[Y - выход] type=out*/
}*_lpS_schl24,_S_schl24;
void schl24(_lpS_schl24 schl24_s);
#endif
