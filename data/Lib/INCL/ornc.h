/*Razdel=[Логические звенья]*/
/*Name=[Логический модуль "ИЛИ" с индикацией входов]*/
#ifndef _ornc_H_
#define _ornc_H_
typedef struct {
psbool *x; /* name=[X-вход] type=in depend=[n]*/
psint n; /* name=[N-число входов] type=tune*/
psbool y; /* name=[Y(лог)] type=out*/
pschar SetInd; /* name=[SetInd - индикатор состояния входов] type=out*/
}*_lpS_ornc,_S_ornc;
void ornc(_lpS_ornc ornc_s);
#endif
