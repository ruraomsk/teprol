/*Razdel=[���������� ��������]*/
/*Name=[������ '��������������� ���� � ������������', ������� �������� ������������� ����, �������� �������� ����������� ����]*/
#ifndef _drg_H_
#define _drg_H_
typedef struct {
psfloat x; /* name=[x - ������� ��������] type=in*/
psbool a; /* name=[a - A-������� ������� ��������� a] type=tune*/
psbool b; /* name=[b - B-������� ������� ��������� b] type=tune*/
psfloat e; /* name=[e - E-������ ������� ������� ���������������, ��.���.���.] type=tune*/
psfloat f; /* name=[f - F-������� ������� ������� ���������������, ��.���.���.] type=tune*/
psbool y; /* name=[y - �������� ��������] type=out*/
psbool y1; /* name=[y1 - ���������� ��������] type=internal*/
}*_lpS_drg,_S_drg;
void drg(_lpS_drg drg_s);
#endif
