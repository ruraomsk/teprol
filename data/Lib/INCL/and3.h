/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Логический элемент И на 3 входа']*/
#ifndef _and3_H_
#define _and3_H_
typedef struct {
psbool x1; /* name=[x1 - вход 1] type=in */
psbool x2; /* name=[x2 - вход 2] type=in */
psbool x3; /* name=[x3 - вход 3] type=in */
psbool y; /* name=[y - выходной параметр] type=out*/
}*_lpS_and3,_S_and3;
void and3(_lpS_and3 and3_s);
#endif