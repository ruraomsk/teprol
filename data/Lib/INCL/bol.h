/*Razdel=[Логические звенья]*/
/*Name=[Логический модуль "Больше"]*/
#ifndef _bol_H_
#define _bol_H_
typedef struct {
psfloat x1; /* name=[X1] type=in*/
psfloat x2; /* name=[X2] type=in*/
psbool y; /* name=[Y] type=out*/
}*_lpS_bol,_S_bol;
void bol(_lpS_bol bol_s);
#endif