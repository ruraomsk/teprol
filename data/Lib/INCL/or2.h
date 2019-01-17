/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Логический элемент ИЛИ на 2 входа']*/
#ifndef _or2_H_
#define _or2_H_
typedef struct {
psbool x1; /* name=[x1 - вход 1] type=in */
psbool x2; /* name=[x2 - вход 2] type=in */
psbool y; /* name=[y - выходной параметр] type=out*/
}*_lpS_or2,_S_or2;
void or2(_lpS_or2 or2_s);
#endif
