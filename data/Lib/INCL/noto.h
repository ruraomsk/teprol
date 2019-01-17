/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Логический элемент НЕ']*/
#ifndef _noto_H_
#define _noto_H_
typedef struct {
psbool x; /* name=[x - входной параметр] type=in*/
psbool y; /* name=[y - выходной параметр] type=out*/
}*_lpS_noto,_S_noto;
void noto(_lpS_noto noto_s);
#endif
