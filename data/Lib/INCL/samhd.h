/*Razdel=[Алгоблоки стандартные]*/
/*Name=[Модуль управления пневматикой и двигателем ]*/
#ifndef _samhd_H_
#define _samhd_H_
typedef struct {
psbool KvitSam; /* name=[KvitSam - квитирование самохода] type=in*/
psbool BLDv; /* name=[BlDv - Блокировка движения вперёд] type=in*/
psbool BLVz; /* name=[BlVz - Блокировка движения назад] type=in*/
psbool DvUp; /* name=[DvUp - есть команда на движение вперёд] type=in*/
psbool DvDw; /* name=[DvDw - есть команда на движение назад] type=in*/
psbool FDvUp; /* name=[FDvUp - факт. движение вперёд] type=in*/
psbool FDvDw; /* name=[FvDw - факт. движение назад] type=in*/
psbool Pkv; /* name=[Pkv - передний конечный выключатель] type=in*/
psbool Pkav; /* name=[Pkav - передний конечный аварийный выключатель] type=in*/
psbool Zkv; /* name=[Zkv - задний конечный выключатель] type=in*/
psbool Zkav; /* name=[Zkav - задний конечный аварийный выключатель] type=in*/
pschar TypeDev; /* name=[TypeDev - тип механизма 0-двигатель, 1-пневмоклапан, 2-двиг. с координатой ] type=tune*/
psfloat tzNm; /* name=[tzNm - время задержки сигнализации недвижения(дес.мс)] type=tune*/
psfloat tzSm; /* name=[tzSm - время задержки сигнализации самохода (дес.мс)] type=tune*/
psfloat tzLd; /* name=[tzLd - время задержки сигнализации превышения времени движения (дес.мс)] type=tune*/
psbool Shift; /* name=[Shift - признак самохода] type=out*/
psbool NoMove; /* name=[NoMove - блокировка по отсутствию перемещения] type=out*/
psbool BadMove; /* name=[BadMove - признак ошибки в направлении перемещения] type=out*/
psbool LongMove; /* name=[LongMove - признак превышения времени перемещения] type=out*/
psbool UpMove; /* name=[UpMove - Сигнал перемещения вверх,вперед,открыть] type=out*/ 
psbool DwMove; /* name=[DwMove - Сигнал перемещения вниз,назад,закрыть] type=out*/ 
psbool FUpMove; /* name=[FUpMove - Факт перемещение вверх,вперед,открыть] type=out*/ 
psbool FDwMove; /* name=[FDwMove - Факт перемещение вниз,назад,закрыть] type=out*/ 
psint Ready; /* name=[Ready - Готовность к управлению(0-движение,1-приехали, 2-нет команды,3-блокир)] type=out*/ 
psbool FinMove; /* name=[FoutMove - признак завершения перемещения] type=out*/ 
psbool CanMove; /* name=[CanMove - признак разрешения перемещения] type=out*/ 
pschar DvUp0; /* name=[- есть команда на движение вперёд] type=internal*/
pschar DvDw0; /* name=[- есть команда на движение назад] type=internal*/
pschar FDvUp0; /* name=[- есть команда на движение вперёд] type=internal*/
pschar FDvDw0; /* name=[- есть команда на движение назад] type=internal*/
pschar BlDv0; /* name=[- была блокировка] type=internal*/
pschar Pkv0; /* name=[Pkv - передний конечный выключатель] type=internal*/
pschar Pkav0; /* name=[Pkav - передний конечный аварийный выключатель] type=internal*/
pschar Zkv0; /* name=[Zkv - задний конечный выключатель] type=internal*/
pschar Zkav0; /* name=[Zkav - задний конечный аварийный выключатель] type=internal*/
psfloat txNm; /* name=[txNm - счётчик задержки сигнализации недвижения] type=internal*/
psfloat txSm; /* name=[txSm - счётчик задержки сигнализации самохода] type=internal*/
psfloat txHr; /* name=[txHr - счётчик задержки сигнализации ошибки направления перемещения] type=internal*/
psfloat txLd; /* name=[txLd - счётчик задержки сигнализации превышения времени перемещения] type=internal*/
pschar fef; /* name=[fef] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_samhd,_S_samhd;
void samhd(_lpS_samhd samhd_s);
#endif

