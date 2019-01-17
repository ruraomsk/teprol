/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Логический элемент И на 4 входа']*/
#ifndef _or5_H_
#define _or5_H_
typedef struct {
psbool x1; /* name=[x1 - вход 1] type=in */
psbool x2; /* name=[x2 - вход 2] type=in */
psbool x3; /* name=[x3 - вход 3] type=in */
psbool x4; /* name=[x4 - вход 4] type=in */
psbool x5; /* name=[x5 - вход 5] type=in */
psbool y; /* name=[y - выходной параметр] type=out*/
}*_lpS_or5,_S_or5;
void or5(_lpS_or5 or5_s);
#endif
