/*Razdel=[����� ������������� ������� ����������]*/
/*Name=[������ ����������� ������������� �������]*/
#ifndef _to3val_H_
#define _to3val_H_
typedef struct {
psfloat x1; /* name=[x1 - ������� ������] type=in*/
psfloat ampl; /* name=[ampl - ��������� ��������������� ����������] type=tune*/
psfloat m1; /* name=[m1 - �������� ���������� ������� ������� �� ��������] type=tune*/
psfloat m2; /* name=[m2 - �������� ���������� �������� ������� �� ��������] type=tune*/
psfloat dis; /* name=[dis - ��������� ���������� ��������] type=tune*/
psfloat maxs1; /* name=[maxs1 - ���c. �������� ������� �������] type=tune*/
psfloat maxs2; /* name=[maxs2 - ���c. �������� �������� �������] type=tune*/
psint Ter; /* name=[Ter (psint)  - ��� �������������] type=tune*/
psfloat y1; /* name=[y1 - �������� ������] type=out*/
psfloat y2; /* name=[y2 - �������� ������] type=out*/
psfloat y3; /* name=[y3 - �������� ������] type=out*/
psbool FirstEnterFlag; /* name=[FirsEnterFlag] type=internal*/
}*_lpS_to3val,_S_to3val;
void to3val(_lpS_to3val to3val_s);
#endif
