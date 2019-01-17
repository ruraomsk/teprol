/*Razdel=[��������� �����������]*/
/*Name=[������ ����������� ������������� �������� �������� � ��������������� ���������]*/
#ifndef _irm_H_
#define _irm_H_
typedef struct {
psfloat wz; /* name=[wz - �������� ��������] type=in*/
psfloat wt; /* name=[wt - ������� ��������] type=in*/
psfloat kz; /* name=[kz - �������� c ������ ���������� ��] type=in*/
psfloat kt; /* name=[kt - ������� ���������� ��] type=in*/
psfloat Tp; /* name=[Tp - ������� ������] type=in*/
psfloat Tm; /* name=[Tm - ������� �����������] type=in*/
psbool  Avt; /* name=[Avt - ���������� ������ ����������] type=in*/
psfloat Zn; /* name=[Zn - ���� ������������������, %] type=tune*/
psfloat MinDk; /* name=[MinDk - ����������� ��������� ����������, ��] type=tune*/
psfloat MaxKr; /* name=[MaxKr - ������������ ���������� ����� ��, ��] type=tune*/
psfloat MaxTime; /* name=[MaxTime - ���������� ����� ������ �� �������� ����� 100��, ���] type=tune*/
psfloat W1; /* name=[W1 - ����������� ���������� ��� ������ �� ��������� ������������] type=tune*/
psfloat W2; /* name=[W2 - ����������� ��������������� �� ���������� ��� ��������� ������������] type=tune*/
psfloat W3; /* name=[W3 - ����������� ���������� ��� ������ �� 0-� ������������] type=tune*/
psfloat A1; /* name=[A1 - ����������� a1 �-��� ����������� ��������� �� � 0-� �������������] type=tune*/
psfloat A0; /* name=[A0 - ����������� a0 �-��� ����������� ��������� �� � 0-� �������������] type=tune*/
psfloat T1; /* name=[T1 - ����������� t1 �-��� ������������� ������������� ��] type=tune*/
psfloat T0; /* name=[T0 - ����������� t0 �-��� ������������� ������������� ��] type=tune*/
psfloat MT1; /* name=[MT1 - ����������� mt1 �-��� �������� ����. ����. ��������� �� �� ��������] type=tune*/
psfloat MT0; /* name=[MT0 - ����������� mt0 �-��� �������� ����. ����. ��������� �� �� ��������] type=tune*/
psfloat Nmin; /* name=[Nmin - ������ ������� ��������� �������� ��� ��������� ������� (����)] type=tune*/
psfloat Ktz; /* name=[Ktz - ������� ������� �� ���������� ��] type=out*/
psfloat Tk; /* name=[Tk - ������������� ������������� ���������� ��] type=out*/
psfloat Rct; /* name=[Rct - ���������� ��������� ������������] type=out*/
psfloat kizm; /* name=[ kizm - ���������� ��������� �� 0-� ������������ ] type=out*/
psbool  Fin; /* name=[Fin - ���������� ������ ���������� �� ����������� ����� ������ �� ��������] type=out*/
psfloat t100; /* name=[ - ����� ������ �� �������� ����� 100��, ��� ] type=out*/
psfloat Vf0; /* name=[ - �������� ��������� �������� ] type=out*/
psint   stage; /* name=[ - ���� 0 - �� ��������, 53 - ����� � 0 �����,51-��������, 52 - ���������, 54- �� ����� �������] type=out*/

}*_lpS_irm,_S_irm;
void irm(_lpS_irm irm_s);
#endif
