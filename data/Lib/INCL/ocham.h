/*Razdel=[Метрологическое обеспечение]*/
/*Name=[Модуль вычисления нейтронного потока]*/
#ifndef _ocham_H_
#define _ocham_H_
typedef struct {
psfloat Ch1k; /* name=[Ch1 - частота импульсов от СНМ-11] type=in*/
psfloat Ch2k; /* name=[Ch2 - частота импульсов от КНК15-1] type=in*/
psfloat Ch3k; /* name=[Ch2 - частота импульсов от КНК53М] type=in*/
psfloat YAz2; /* name=[YAz2 - y-координата АЗ2 мм] type=in*/
psfloat XAz; /* name=[XAz - x-координата АЗ cм] type=tune*/
psfloat YAz1; /* name=[YAz1 - y-координата АЗ1 cм] type=tune*/
psfloat Reff; /* name=[Reff - эффективный радиус РУ cм] type=tune*/
psfloat Ak1; /* name=[Ak1 - калибр. коэфф-1. преобраз. частоты камеры СНМ-11 в нейтр. поток] type=tune*/
psfloat Bk1; /* name=[Bk1 - калибр. коэфф-2. преобраз. частоты камеры СНМ-11 в нейтр. поток] type=tune*/
psfloat Ak2; /* name=[Ak2 - калибр. коэфф-1. преобраз. частоты камеры КНК15-1 в нейтр. поток] type=tune*/
psfloat Bk2; /* name=[Bk2 - калибр. коэфф-2. преобраз. частоты камеры КНК15-1 нейтр. поток] type=tune*/
psfloat Ak3; /* name=[Ak3 - калибр. коэфф-1. преобраз. частоты камеры КНК53М в нейтр. поток] type=tune*/
psfloat Bk3; /* name=[Bk3 - калибр. коэфф-2. преобраз. частоты камеры КНК53М в нейтр. поток] type=tune*/
psfloat XCm1; /* name=[XCm1 - x-координата камеры СНМ-11 см] type=tune*/
psfloat YCm1; /* name=[YCm1 - y-координата камеры СНМ-11 см] type=tune*/
psfloat XCm2; /* name=[XCm2 - x-координата камеры КНК15-1 см] type=tune*/
psfloat YCm2; /* name=[YCm2 - y-координата камеры КНК15-1 см] type=tune*/
psfloat XCm3; /* name=[XCm3 - x-координата камеры КНК53М см] type=tune*/
psfloat YCm3; /* name=[YCm3 - y-координата камеры КНК53М см] type=tune*/
pschar  type; /* name=[type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ ] type=tune*/
psfloat Kpr1k; /* name=[Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 ] type=tune*/
psfloat Kpr2k; /* name=[Kpr2 - коэфф. преобразования частота->нейтр/с КНК15-1] type=tune*/
psfloat Kpr3k; /* name=[Kpr3 - коэфф. преобразования частота->нейтр/с КНК53М] type=tune*/
psfloat Kprm; /* name=[Kprm - коэфф. преобразования поток->мощность] type=tune*/
psfloat Np; /* name=[Np - поток нейтронов от РУ  (нейтр/с)] type=out*/
psfloat Nm; /* name=[Nm - мощность РУ] type=out*/
psbool  Flerr;  /* name=[Err - флаг неисправности канала] type=out*/
psfloat Np1; /* name=[Np1 - поток нейтронов от 1 камеры  (нейтр/с)] type=out*/
psfloat Np2; /* name=[Np2 - поток нейтронов от 2 камеры  (нейтр/с)] type=out*/
psfloat Np3; /* name=[Np3 - поток нейтронов от 3 камеры  (нейтр/с)] type=out*/
psint Nkm; /* name=[Nkm - ведущая камера 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей] type=out*/
psint  Nk; /* name=[Nk - ведущая камера] type=internal*/
}*_lpS_ocham,_S_ocham;
void ocham(_lpS_ocham ocham_s);
#endif
