/*Razdel=[Блоки моделирования объекта управления]*/
/*Name=[Модель ионизационной камеры]              */
#ifndef _vchs_H_
#define _vchs_H_
typedef struct {
psfloat N1;   /* name=[N1 - поток нейтронов от АЗ1 (нейтр/с)] type=in*/
psfloat N2;   /* name=[N2 - поток нейтронов от АЗ2 (нейтр/с)] type=in*/
psfloat XAz1; /* name=[XAz1 - x-координата АЗ1 cм] type=tune*/
psfloat YAz1; /* name=[YAz1 - y-координата АЗ1 cм] type=tune*/
psfloat YAz2; /* name=[YAz2 - y-координата АЗ2 cм] type=tune*/
psfloat XCm; /* name=[XCm - x-координата камеры cм] type=tune*/
psfloat YCm; /* name=[YCm - y-координата камеры см] type=tune*/
pschar  type; /* name=[type - тип камеры] type=tune*/
psfloat Ak; /* name=[Ak - калибровочный коэффициент-1 преобразования нейтр/с - имп/с] type=tune*/
psfloat Bk; /* name=[Bk - калибровочный коэффициент-2 преобразования нейтр/с - имп/с] type=tune*/
psfloat Fk; /* name=[Fk - коэфф. преобразования частота->нейтр/с] type=tune*/
psfloat FMax; /* name=[FMax - предельная частота измеряемая камерой Гц] type=tune*/
psfloat FMin; /* name=[FMin - минимальная частота измеряемая камерой Гц] type=tune*/
psfloat Reff; /* name=[Reff -эффективный радиус РУ (см)] type=tune*/
psfloat Chim; /* name=[Chim - частота импульсов камеры Гц] type=out*/
psfloat Chim0; /* name=[измеренная частота импульсов камеры Гц] type=internal*/
}*_lpS_vchs,_S_vchs;
void vchs(_lpS_vchs vchs_s);
#endif
