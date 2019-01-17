/*Razdel=[Динамические звенья]*/
/*Name=[Задержка заднего фронта сек]*/
#ifndef _zzfs_H_
#define _zzfs_H_
typedef struct {
psbool x; /* name=[x - входной сигнал] type=in*/
psfloat tz; /* name=[tz - время задержки сек] type=tune*/
psbool y; /* name=[y - выходной сигнал] type=out*/
psfloat tx; /* name=[tx - время накопленное сек] type=internal*/
pschar y0; /* name=[y0] type=internal*/
}*_lpS_zzfs,_S_zzfs;
void zzfs(_lpS_zzfs zzfs_s);
#endif

