/*Razdel=[Алгоблоки стандартные]*/
/*Name=[Модуль выделения байта недостоверности параметров разных типов]*/
#ifndef _geterr_H_
#define _geterr_H_
typedef struct {
psfloat fx; /* name=[fx - вещественный вход] type=in*/
pslong lx; /* name=[lx - длинный целочисленный вход] type=in*/
psint ix; /* name=[ix - целочисленный вход] type=in*/
pschar cx; /* name=[cx - байтовый вход] type=in*/
pschar efx; /* name=[efx - байт недостоверности вещественного входа] type=out*/
pschar elx; /* name=[elx - байт недостоверности длинного целочисленного входа] type=out*/
pschar eix; /* name=[eix - байт недостоверности целочисленного входа] type=out*/
pschar ecx; /* name=[ecx - байт недостоверности байтового входа] type=out*/
psbool lgx; /* name=[lgx - признак недостоверности одного из входов] type=out*/
}*_lpS_geterr,_S_geterr;                             
void geterr(_lpS_geterr geterr_s);
#endif
