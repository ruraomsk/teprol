/*Razdel=[Модули СУПТ В-1000]*/
/*Name=[Модуль определения состояния механизма с неизвестным управлением]*/
#ifndef _nocnm_H_
#define _nocnm_H_
typedef struct {
psbool  Pv;/* name=[Pv - Пер. выключатель механизма] type=in*/
psbool  Zv;/* name=[Zv - Зад. выключатель механизма] type=in*/
psbool Mup;/* name=[ Mup - фактическое движение вперёд] type=out*/
psbool Mdw;/* name=[ Mdw - фактическое движение назад] type=out*/
psint Ready; /* name=[Ready - Готовность к управлению(0-движение,1-приехали, 2-нет команды,3-блокир)] type=out*/ 
psbool Pv0;/* name=[ - Пер. выключатель механизма] type=internal*/
psbool Zv0;/* name=[ - Зад. выключатель механизма] type=internal*/
psbool MyFirstEnterFlag; /* name=[MyFirstEnterFlag] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_nocnm,_S_nocnm;
void nocnm(_lpS_nocnm nocnm_s);
#endif