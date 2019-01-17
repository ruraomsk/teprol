/*Razdel=[Метрологическое обеспечение]*/
/*Name=[Модуль отсчёта 10 сек]*/
#ifndef _decatron_H_
#define _decatron_H_
typedef struct {
psbool pusk; /* name=[pusk - разрешение выполнения программы] type=in*/
psint Sek;  /* name=[Sek - до конца программы (секунд)] type=out*/
pslong TimS; /* name=[Время старта] type=internal*/
}*_lpS_decatron,_S_decatron;
void decatron(_lpS_decatron decatron_s);
#endif