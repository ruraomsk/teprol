/*Razdel=[Логические звенья]*/
/*Name=[Модуль 'Мультиплексор логический' для вещественных параметров]*/
#ifndef _ml_H_
#define _ml_H_
typedef struct {
psfloat x1; /* name=[x1 - первый входной параметр] type=in*/
psfloat x2; /* name=[x2 - второй входной параметр] type=in*/
psbool s; /* name=[s - управляющий параметр] type=in*/
psfloat y; /* name=[y - выходной параметр] type=out*/
}*_lpS_ml,_S_ml;
void ml(_lpS_ml ml_s);
#endif
