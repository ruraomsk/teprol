/*Razdel=[Логические звенья]*/
/*Name=[Логический модуль " Больше " ( с цел. входами )]*/
#ifndef _bolz_H_
#define _bolz_H_
typedef struct {
psint x1; /* name=[X1] type=in*/
psint x2; /* name=[X2] type=in*/
psbool y; /* name=[Y] type=out*/
}*_lpS_bolz,_S_bolz;
void bolz(_lpS_bolz bolz_s);
#endif