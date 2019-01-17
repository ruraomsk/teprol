/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Логический элемент ИЛИ на 3 входа']*/
#ifndef _or3_H_
#define _or3_H_
typedef struct {
psbool x1; /* name=[x1 - вход 1] type=in */
psbool x2; /* name=[x2 - вход 2] type=in */
psbool x3; /* name=[x3 - вход 3] type=in */
psbool y; /* name=[y - выходной параметр] type=out*/
}*_lpS_or3,_S_or3;
void or3(_lpS_or3 or3_s);
#endif
