/*Razdel=[������������ �������]*/
/*Name=[���������� �������� � ������ �����������]*/
#ifndef _srm_H_
#define _srm_H_
typedef struct {
psfloat *x; /* name=[� - ������ ��������] type=in depend=[n]*/
psbool *diag; /* name=[ diag - ������ �����������(1-����)] type=in depend=[n]*/
psint n; /* name=[n - ����������� �������] type=tune*/
psint mk; /* name=[mk - ����������� ���������� ���������� ������] type=tune*/
psfloat y; /* name=[Y - ������� �������� �� ���������� ������] type=out*/
psbool az; /* name=[az - ������� ��������� ���������� ���������� ������] type=out*/
}*_lpS_srm,_S_srm;
void srm(_lpS_srm srm_s);
#endif
