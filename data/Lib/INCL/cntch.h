/*Razdel=[Динамические звенья]*/
/*Name=[Модуль индикации изменения длинного целого]*/
#ifndef _cntch_H_
#define _cntch_H_
typedef struct {
pslong x; /* name=[x - входной параметр] type=in*/
psbool y; /* name=[y - выходной параметр] type=out*/
pslong x0; /* name=[x0 - значение входного параметра на предыдущем шаге] type=internal*/
}*_lpS_cntch,_S_cntch;
void cntch(_lpS_cntch cntch_s);
#endif
