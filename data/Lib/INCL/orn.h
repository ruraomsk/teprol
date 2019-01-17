/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Логический элемент ИЛИ']*/
#ifndef _orn_H_
#define _orn_H_
typedef struct {
psbool *x; /* name=[x - массив входных параметров] type=in depend=[n]*/
psint n; /* name=[n - N-размерность массива x] type=tune*/
psbool y; /* name=[y - выходной параметр] type=out*/
}*_lpS_orn,_S_orn;
void orn(_lpS_orn orn_s);
#endif
