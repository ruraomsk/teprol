/*Razdel=[��������� �����������]*/
/*Name=[������ ��������� ����� ��������������� ���������� ������ �����]*/
#ifndef _geterr_H_
#define _geterr_H_
typedef struct {
psfloat fx; /* name=[fx - ������������ ����] type=in*/
pslong lx; /* name=[lx - ������� ������������� ����] type=in*/
psint ix; /* name=[ix - ������������� ����] type=in*/
pschar cx; /* name=[cx - �������� ����] type=in*/
pschar efx; /* name=[efx - ���� ��������������� ������������� �����] type=out*/
pschar elx; /* name=[elx - ���� ��������������� �������� �������������� �����] type=out*/
pschar eix; /* name=[eix - ���� ��������������� �������������� �����] type=out*/
pschar ecx; /* name=[ecx - ���� ��������������� ��������� �����] type=out*/
psbool lgx; /* name=[lgx - ������� ��������������� ������ �� ������] type=out*/
}*_lpS_geterr,_S_geterr;                             
void geterr(_lpS_geterr geterr_s);
#endif
