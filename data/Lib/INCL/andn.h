/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Логический элемент И']*/
#ifndef _andn_H_
#define _andn_H_
typedef struct {
psbool *x; /* name=[x - массив входных параметров] type=in depend=[n]*/
psint n; /* name=[n - N-размерность массива входных параметров] type=tune*/
psbool y; /* name=[y - выходной параметр] type=out*/
}*_lpS_andn,_S_andn;
void andn(_lpS_andn andn_s);
#endif

