/*Razdel=[������������ �������]*/
/*Name=[������ '���������', ��������� ������������� ��������� �� �����������]*/
#ifndef _ampl_H_
#define _ampl_H_
typedef struct {
psfloat x; /* name=[x - ������� ��������] type=in*/
psfloat k; /* name=[k - ����������� ��������] type=tune*/
psfloat y; /* name=[y - �������� ��������] type=out*/
}*_lpS_ampl,_S_ampl;
void ampl(_lpS_ampl ampl_s);
#endif
