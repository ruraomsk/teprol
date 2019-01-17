/*Razdel=[��������������� �����������]*/
/*Name=[������ ���������� ������� ������� ��������]*/
#ifndef _period_H_
#define _period_H_
typedef struct {
psfloat Np; /* name=[Np - �������� �� (����)] type=in*/
psbool  Flerr;  /* name=[Err - ���� ������������� ������] type=in*/
psint n; /* name=[n - ����������� ������� ���������� ������] type=tune*/
psfloat TiStep; /* name=[TiStep - ��� ��������� ������� (���)] type=tune*/
psfloat Tmax; /* name=[Tmax - ���������� ����� �������� ����� ������ (���)] type=tune*/
psfloat Nmin; /* name=[Nmin - ������ ������� ��������� �������� ��� ��������� ������� (����)] type=tune*/
psfloat Period; /* name=[Per - ������ ������� ��] type=out*/
psfloat *tst; /* name=[- ������ ������� �������� ��������� ��������] type=internal depend=[n]*/
psfloat *trz; /* name=[- ������ ������� �������� ���������� �������] type=internal depend=[n]*/
psfloat *N1; /* name=[- ������ �������� �������� � ������ ������] type=internal depend=[n]*/
psfloat *N2; /* name=[- ������ �������� �������� � ����� ������] type=internal depend=[n]*/
psfloat Period0; /* name=[Per - ������ ������� ��] type=internal*/
psbool MyFirstEnterFlag; /* name=[ FirstEnterFlag] type=internal*/

}*_lpS_period,_S_period;
void period(_lpS_period period_s);
#endif
