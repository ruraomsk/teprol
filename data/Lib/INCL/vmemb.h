/*Razdel=[Динамические звенья]*/
/*Name=[Модуль памяти для логического параметра]*/
#ifndef _vmemb_H_
#define _vmemb_H_
typedef struct {
psbool x; /* name=[x - входной параметр] type=in*/
psbool y; /* name=[y - выходной параметр] type=out*/
psbool x0; /* name=[x0 - значение входного параметра на предыдущем шаге] type=internal*/
}*_lpS_vmemb,_S_vmemb;
void vmemb(_lpS_vmemb vmemb_s);
#endif
