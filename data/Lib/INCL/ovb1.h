/*Razdel=[��������� �����������]*/
/*Name=[������ ������������ ��������� ��������� (������������) ��� ���������� ������� ���������]*/
#ifndef _ovb1_H_
#define _ovb1_H_
typedef struct {
psbool x; /* name=[x - ������� ��������] type=in*/
psint tz; /* name=[tz - ������ ��������, 10-�� ��] type=tune*/
psbool y; /* name=[y - �������� ��������] type=out*/
psint tx; /* name=[tx - ���������� ��������] type=internal*/
}*_lpS_ovb1,_S_ovb1;
void ovb1(_lpS_ovb1 ovb1_s);
#endif

