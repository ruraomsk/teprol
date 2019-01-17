/*Razdel=[Динамические звенья]*/
/*Name=[Задержка переднего фронта сек]*/
#ifndef _zpfs_H_
#define _zpfs_H_
typedef struct {
psbool x; /* name=[x - входной сигнал] type=in*/
psfloat tz; /* name=[tz - время задержки сек] type=tune*/
psbool y; /* name=[y - выходной сигнал] type=out*/
psfloat tx; /* name=[tx - время накопленное сек] type=internal*/
pschar y0; /* name=[y0] type=internal*/
}*_lpS_zpfs,_S_zpfs;
void zpfs(_lpS_zpfs zpfs_s);
#endif

