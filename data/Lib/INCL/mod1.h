/*Razdel=[Динамические звенья]*/
/*Name=[Модуль 'Апериодическое звено первого порядка']*/
#ifndef _mod1_H_
#define _mod1_H_
typedef struct {
psfloat x; /* name=[x - входной параметр] type=in*/
psfloat k; /* name=[k - Kф-коэффициент усиления] type=tune*/
psfloat tau; /* name=[tau - Tф-постоянная времени, с] type=tune*/
psfloat y; /* name=[y - выходной параметр] type=out*/
psfloat y0; /* name=[y0 - внутренний параметр] type=internal*/
}*_lpS_mod1,_S_mod1;
void mod1(_lpS_mod1 mod1_s);
#endif
