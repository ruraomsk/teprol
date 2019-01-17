/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'rsun-триггер' с приоритетом сброса]*/
#ifndef _rsun_H_
#define _rsun_H_
typedef struct {
psbool r; /* name=[r - сигнал сброса R] type=in*/
pslong s; /* name=[s - входной сигнал S] type=in*/
pslong q; /* name=[q - выходной параметр] type=out*/
psint qi; /* name=[qi - выходной параметр] type=out*/
pslong q0; /* name=[q0 - внутренний параметр] type=internal*/
}*_lpS_rsun,_S_rsun;
void rsun(_lpS_rsun rsun_s);
#endif
