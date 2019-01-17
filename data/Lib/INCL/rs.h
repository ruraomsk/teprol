/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'RS-триггер' с приоритетом сброса]*/
#ifndef _rs_H_
#define _rs_H_
typedef struct {
psbool r; /* name=[r - сигнал сброса R] type=in*/
psbool s; /* name=[s - входной сигнал S] type=in*/
psbool q; /* name=[q - выходной параметр] type=out*/
psbool nq; /* name=[nq - инверсия q] type=out*/
psbool q0; /* name=[q0 - внутренний параметр] type=internal*/
}*_lpS_rs,_S_rs;
void rs(_lpS_rs rs_s);
#endif
