/*Razdel=[����� ������������� ������� ����������]*/
/*Name=[������ ����������� ��������� � ������� ����������]*/
#ifndef _asmot_H_
#define _asmot_H_
typedef struct {
psbool RA0;/* name=[ RA0 - �������� �����] type=in*/
psbool RA1;/* name=[ RA1 - �������� �����] type=in*/
psfloat XYvk; /* name=[XYvk - ���������� �� �� ��] type=in*/
psfloat Vzvk; /* name=[Vzvk - �������� �������� ��/� �������� �� ��] type=in*/
psfloat  Vm;/* name=[Vm - C������� ������������ (��/�)] type=tune*/
psfloat  Tp;/* name=[Tp - ��������� ���� ��] type=tune*/
psint   Ter;/* name=[Ter - ������������� ���������] type=tune*/
psfloat KPav;/* name=[KPav - ���������� ���.���������� ����������� ��������� ��] type=tune*/
psfloat KZav;/* name=[KZav - ���������� ���.���������� ����������� ��������� ��] type=tune*/
psfloat KPv;/* name=[KPv - ���������� ���. ����������� ��������� ��] type=tune*/
psfloat KZv;/* name=[KZv - ���������� ���. ����������� ��������� ��] type=tune*/
psfloat Dlt;/* name=[Dlt - ���� ������������ �� ��������� ��] type=tune*/
psfloat  X0;/* name=[ X0 - �������� ���������� ���������] type=tune*/
psfloat  V0;/* name=[ V0 - �������� �������� ���������] type=tune*/
psfloat   X;/* name=[X - ���������� ���������] type=out*/
psbool  Pav;/* name=[Pav - ���.��������� ����������� ���������] type=out*/
psbool  Zav;/* name=[Zav - ���.��������� ����������� ���������] type=out*/
psbool  Pv;/* name=[Pv - ���. ����������� ���������] type=out*/
psbool  Zv;/* name=[Zv - ���. ����������� ���������] type=out*/
psfloat  V;/* name=[Vt - ������� �������� ���������] type=out*/
psbool Mup;/* name=[ Mup - ����������� �������� �����] type=out*/
psbool Mdw;/* name=[ Mdw - ����������� �������� �����] type=out*/
psbool Pav0;/* name=[ - ���.��������� ����������� ���������] type=internal*/
psbool Zav0;/* name=[ - ���.��������� ����������� ���������] type=internal*/
psbool Pv0;/* name=[ - ���. ����������� ���������] type=internal*/
psbool Zv0;/* name=[ - ���. ����������� ���������] type=internal*/
psbool RA00;/* name=[ - ��������� ������� ������] type=internal*/
psbool RA10;/* name=[ - ��������� ������� �����] type=internal*/
psbool MyFirstEnterFlag; /* name=[MyFirstEnterFlag] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_asmot,_S_asmot;
void asmot(_lpS_asmot asmot_s);
#endif