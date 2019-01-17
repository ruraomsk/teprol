/*Razdel=[����� ������������� ������� ����������]*/
/*Name=[������ �������� (��������)]              */
#ifndef _azbars_H_
#define _azbars_H_
typedef struct {
psfloat Kbb; /* name=[Kbb - ���������� ��] type=in*/
psfloat Krb; /* name=[Krb - ���������� ��] type=in*/
psfloat Kis; /* name=[Kis- ���������� ��] type=in*/
psfloat N2; /* name=[N2 - ������������ ��������� ������ ��] type=in*/
psfloat RIt;   /* name=[RIt - ������������, �������� ����������� ���������] type=in*/
psbool  BlowOut;   /* name=[BlowOut - ������ "����� ��" ������� (����������)] type=in*/
psbool  NIatVU;   /* name=[NIatVU - ���������� �������� �� ��] type=in*/
psbool  IsANI;   /* name=[IsANI - ��������� ���������� �������� ����������] type=in*/
psbool  ImpINI;   /* name=[ImpINI - ������ ������� �������������] type=in*/
psfloat Lg; /* name=[Lg - ������� ����� ��������� �������� ���������] type=tune*/
psfloat Bz; /* name=[Bz - ���� ������������� ��������� � ����� ���������� ���������] type=tune*/ 
psfloat AT; /* name=[AT - ������������� ����������� ]type=tune*/
psfloat MT; /* name=[MT - ����� ������� � ��(��)] type=tune*/
psfloat CT; /* name=[CT - �������� ����������� ������� ���/��*����] type=tune*/
psfloat EN; /* name=[EN - ������� 1 ������� ����  (��) * E^-13] type=tune*/
psfloat EVt; /* name=[EVt - ���-�� �������/��� �� 1 ���� * E^6] type=tune*/
psfloat Sani; /* name=[Sani - �������� ��������� ��������� ��� ������� ���] type=tune*/
psfloat Sno; /* name=[Sno - �������� ��������� ��������� ��� ���] type=tune*/
psfloat ABB0; /* name=[ABB0 - �����������-0 ������� ������������ �������� ��] type=tune*/
psfloat ABB1; /* name=[ABB1 - �����������-1 ������� ������������ �������� ��] type=tune*/
psfloat ARB0; /* name=[ARB0 - �����������-0 ������� ������������ �������� ��] type=tune*/
psfloat ARB1; /* name=[ARB1 - �����������-1 ������� ������������ �������� ��] type=tune*/
psfloat AIS0; /* name=[AIS0 - �����������-0 ������� ������������ �������� ��] type=tune*/
psfloat AIS1; /* name=[AIS1 - �����������-1 ������� ������������ �������� ��] type=tune*/
psfloat K11; /* name=[K11 - ����������� 11 ����� ��1,2] type=tune*/
psfloat K12; /* name=[K12 - ����������� 12 ����� ��1,2] type=tune*/
psfloat Tn0; /* name=[Tn0 - ���������� ����������� ��] type=tune*/
psfloat RBlow; /* name=[RBlow - ������������� ������������� ��� ������] type=tune*/
psfloat N0; /* name=[N0 - ��������� ������������ ���������] type=tune*/
psfloat R0; /* name=[R0 - ��������� ������������] type=tune*/
psfloat T0; /* name=[T0 - ��������� �����������] type=tune*/
psfloat N; /* name=[N - ������������ ���������] type=out*/
psfloat Pn; /* name=[Pn - ����� ���������(�����/�)] type=out*/
psfloat R; /* name=[R - ������� ������������] type=out*/
psfloat T; /* name=[T - ������� �����������] type=out*/
psbool  IsBlow;   /* name=[IsBlow - ������ "����� ��" ������ (���������)] type=out*/
psfloat Period; /* name=[Period - ������ ������� ��] type=out*/
psfloat Npn;  /* name=[Npn- �������� ������ ���������(����)] type=out */
psfloat C1; /* name=[C1 - ������������ ������������� ��������� 1-�� ����] type=internal*/
psfloat C2; /* name=[C2 - ������������ ������������� ��������� 2-�� ����] type=internal*/
psfloat C3; /* name=[C3 - ������������ ������������� ��������� 3-�� ����] type=internal*/
psfloat C4; /* name=[C4 - ������������ ������������� ��������� 4-�� ����] type=internal*/
psfloat C5; /* name=[C5 - ������������ ������������� ��������� 5-�� ����] type=internal*/
psfloat C6; /* name=[C6 - ������������ ������������� ��������� 6-�� ����] type=internal*/
psfloat N20; /* name=[N20 - ����. ������������ ��������� ������ ��] type=internal*/
psfloat *C0; /* name=[*C0 - ����. ������������ ������������� ���������] type=internal size=6 */ 
psbool  ImpINI0;   /* name=[ImpINI - ������ ������� �������������(����.)] type=internal*/
psbool MyFirstEnterFlag; /* name=[MyFirstEnterFlag] type=internal*/
psbool FirstEnterFlag; /* name=[ FirstEnterFlag] type=internal*/
}*_lpS_azbars,_S_azbars;
void azbars(_lpS_azbars azbars_s);
#endif