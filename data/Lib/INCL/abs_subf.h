/*Razdel=[������������ �������]*/
/*Name=[������ ������� ����������� �������� �������� ���� ����������(float)]*/
#ifndef _abs_subf_H_
#define _abs_subf_H_
typedef struct {
psfloat x1; /* name=[�1 - ������ ������� ��������] type=in*/
psfloat x2; /* name=[�2 - ������ ������� ��������] type=in*/
psfloat Delta; /* name=[Delta - delta-���������� ��������������� ������� ����������] type=tune*/
psfloat y; /* name=[� - ���������� �������� �������� x1 � x2 (y=|x1-x2|)] type=out*/
psbool s; /* name=[s - ������� ������� ��������������� ����� �������� �����������] type=out*/
}*_lpS_abs_subf,_S_abs_subf;
void abs_subf(_lpS_abs_subf abs_subf_s);
#endif