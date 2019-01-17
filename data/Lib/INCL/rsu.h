/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'rsu-триггер' с приоритетом сброса, ненулевой сигнал фиксируется]*/
/*  */
#ifndef _rsu_H_
#define _rsu_H_
typedef struct {
psbool r; /* name=[r - сигнал сброса R] type=in*/
pslong s; /* name=[s - входной сигнал S] type=in*/
pslong q; /* name=[q - выходной параметр] type=out*/
pslong q0; /* name=[q0 - внутренний параметр] type=internal*/
}*_lpS_rsu,_S_rsu;
void rsu(_lpS_rsu rsu_s);
#endif
