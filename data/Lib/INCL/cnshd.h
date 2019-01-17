/*Razdel=[Модули СУПТ В-1000]*/
/*Name=[модуль управления скоростью движения механизма с шаговым двигателем]*/
#ifndef _cnshd_H_
#define _cnshd_H_
typedef struct {
psbool KvitSam; /* name=[KvitSam - квитирование самохода] type=in*/
psfloat Xt; /* name=[Xt - текущее  положение механизма мм] type=in*/
psfloat Xz; /* name=[Xz - заданное положение механизма мм] type=in*/
psfloat UstK; /* name=[UstK - введённая уставка по координате мм] type=in*/
psbool Rr; /* name=[Rr - есть команда] type=in*/
psbool BLDv; /* name=[BlDv - Блокировка движения] type=in*/
psbool AvtSt; /* name=[AvtSt - разрешение от автомат/шаг] type=in*/
psint nspd_fw; /* name=[nspd_fw - размерность шкалы движения вперёд] type=tune*/
psfloat  *Lt_fw; /* name=[Lt_fw - шкала координат выбора скорости движения вперёд(мм)] type=tune depend=[nspd_fw]*/
psint *Vr_fw; /* name=[Vr_fw - шкала скоростей движения вперёд(2-6)] type=tune depend=[nspd_fw]*/
psint nspd_bw; /* name=[nspd_bw - размерность шкалы движения назад] type=tune*/
psfloat  *Lt_bw; /* name=[Lt_bw - шкала координат выбора скорости движения назад(мм)] type=tune depend=[nspd_bw]*/
psint *Vr_bw; /* name=[Vr_bw - шкала скоростей движения назад(2-6)] type=tune depend=[nspd_bw]*/
psfloat Dlt; /* name=[Dlt - зона нечувствительности в мм (гр.)] type=tune*/
psfloat DltRet; /* name=[DltRet - зона возврата в мм (гр.)] type=tune*/
psfloat Tim; /* name=[Tim - время расширения зона нечувствительности до зоны возврата, сек] type=tune*/
psfloat Kpr; /* name=[Kpr - коэффициент преобразования скорости из частоты в мм/сек] type=tune*/
psbool Nz; /* name=[Nz = 1 - механизм в зоне неч.] type=out*/
psbool OnUst; /* name=[OnUst = 1 - механизм на заданной уставке] type=out*/
psfloat Xts; /* name=[Xts - текущее  положение механизма мм] type=out*/
psbool RA3;/* name=[ RA3 - разрешение движения] type=out*/
psbool RA0;/* name=[ RA0 - движение вперёд] type=out*/
psbool RA1;/* name=[ RA1 - движение назад] type=out*/
psbool RA2;/* name=[ RA2 - 0-й бит скорости] type=out*/
psbool RA4;/* name=[ RA4 - 1-й бит скорости] type=out*/
psbool RA5;/* name=[ RA5 - 2-й бит скорости] type=out*/
psbool RB3;/* name=[ RB3 - паритет команды (нечет)] type=out*/ 
psfloat Vz; /* name=[Vz - заданная скорость механизма (мм/сек)] type=out*/
pschar Ready; /* name=[Ready - Готовность к управлению(0-движение,1-приехали, 2-нет команды,3-блокир)] type=out*/ 
psfloat X0; /* name=[текущая зона нечувствительности (Dlt/Du) в мм (гр.)] type=internal*/
psfloat t0; /* name=[время нахождения в зоне возврата] type=internal*/
pschar BLDv0; /* name=[BlDv - Блокировка движения] type=internal*/
}*_lpS_cnshd,_S_cnshd;
void cnshd(_lpS_cnshd cnshd_s);
#endif
