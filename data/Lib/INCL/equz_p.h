/*Razdel=[���������� ������]*/
/*Name=[������ '����� ���������']*/
#ifndef _equz_p_H_
#define _equz_p_H_
typedef struct {
psint x; /* name=[x - ������� ��������] type=in*/
psint p; /* name=[p - ����������� ��������] type=tune*/
psbool y; /* name=[y - ������� ��������� x=p] type=out*/
}*_lpS_equz_p,_S_equz_p;
void equz_p(_lpS_equz_p equz_p_s);
#endif