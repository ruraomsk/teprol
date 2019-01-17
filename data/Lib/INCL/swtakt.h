/*Razdel=[Динамические звенья]*/
/*Name=[Модуль переключения имитации на короткий шаг]*/
#ifndef _swtakt_H_
#define _swtakt_H_
typedef struct {
psbool x; /* name=[x - переключения имитации на короткий шаг] type=in*/
psbool y; /* name=[y - переключить] type=out*/
psbool x0; /* name=[x0 - значение входного параметра на предыдущем шаге] type=internal*/
}*_lpS_swtakt,_S_swtakt;
void swtakt(_lpS_swtakt swtakt_s);
#endif
