/*Razdel=[������������ ������]*/
/*Name=[������ '�������������� ����� ������� �������']*/
#ifndef _mod1_H_
#define _mod1_H_
typedef struct {
psfloat x; /* name=[x - ������� ��������] type=in*/
psfloat k; /* name=[k - K�-����������� ��������] type=tune*/
psfloat tau; /* name=[tau - T�-���������� �������, �] type=tune*/
psfloat y; /* name=[y - �������� ��������] type=out*/
psfloat y0; /* name=[y0 - ���������� ��������] type=internal*/
}*_lpS_mod1,_S_mod1;
void mod1(_lpS_mod1 mod1_s);
#endif
