/*Razdel=[Логические звенья]*/
/*Name=[Логический модуль "ИЛИ" с индикацией состояния входов]*/
#ifndef _orni_H_
#define _orni_H_
typedef struct {
psbool *x; /* name=[x - массив входных сигналов] type=in depend=[n]*/
psint n; /* name=[n - размерность массива входных сигналов] type=tune*/
psbool y; /* name=[y - выходной сигнал] type=out*/
pslong SetInd; /* name=[SetInd - индикатор состояния входов] type=out*/
}*_lpS_orni,_S_orni;
void orni(_lpS_orni orni_s);
#endif
