/*Razdel=[��������� �����������]*/
/*Name=[������ ������������ ��������� ��������� (������������) ��� ���������� ������� ���������]*/
#ifndef _ovbs_H_
#define _ovbs_H_
typedef struct {
psbool x; /* name=[x - ������� ��������] type=in*/
psfloat tz; /* name=[tz - ������ ��������, sek] type=tune*/
psbool y; /* name=[y - �������� ��������] type=out*/
psfloat tx; /* name=[tx - ���������� ��������] type=internal*/
}*_lpS_ovbs,_S_ovbs;
void ovbs(_lpS_ovbs ovbs_s);
#endif
