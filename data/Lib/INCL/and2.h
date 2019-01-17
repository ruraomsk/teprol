/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Логический элемент И на 2 входа']*/
#ifndef _and2_H_
#define _and2_H_
typedef struct {
psbool x1; /* name=[x1 - вход 1] type=in */
psbool x2; /* name=[x2 - вход 2] type=in */
psbool y; /* name=[y - выходной параметр] type=out*/
}*_lpS_and2,_S_and2;
void and2(_lpS_and2 and2_s);
#endif
