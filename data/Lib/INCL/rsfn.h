/*Razdel=[���������� ������]*/
/*Name=[������ 'rsfn-�������' � ����������� ������]*/
#ifndef _rsfn_H_
#define _rsfn_H_
typedef struct {
psbool r; /* name=[r - ������ ������ R] type=in*/
psfloat s; /* name=[s - ������� ������ S] type=in*/
psfloat q; /* name=[q - �������� ��������] type=out*/
psfloat q0; /* name=[q0 - ���������� ��������] type=internal*/
}*_lpS_rsfn,_S_rsfn;
void rsfn(_lpS_rsfn rsfn_s);
#endif
