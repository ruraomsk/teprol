/*Razdel=[����� ������������� ������� ����������]*/
/*Name=[������ ����������� ��� � ������� ����������]*/
#ifndef _orrsim_H_
#define _orrsim_H_
typedef struct {
psbool RA0;/* name=[ RA0 - �������� �����] type=in*/
psbool RA1;/* name=[ RA1 - �������� �����] type=in*/
psbool RA2;/* name=[ RA2 - 0-� ��� ��������] type=in*/
psbool RA3;/* name=[ RA3 - ���������� ��������] type=in*/
psbool RA4;/* name=[ RA4 - 1-� ��� ��������] type=in*/
psbool RA5;/* name=[ RA5 - 2-� ��� ��������] type=in*/
psbool RB3;/* name=[ RB3 - ������� ������� (�����)] type=in*/ 
psbool Klo;/* name=[ Klo - ������ ������ ��л ������� (����������)] type=in*/ 
psbool Klz;/* name=[ Klz - ������ ������� ��л ������� (����������)] type=in*/ 
psbool EMo;/* name=[ EMo - ���������� ������������� ���] type=in*/ 
psfloat Xk; /* name=[Xk - ���������� ��� �� �� ��] type=in*/
psfloat Shk; /* name=[Shk - ���������� ����� ��� �� �� ��] type=in*/
psfloat IRV; /* name=[XV - �������� �������� ��/� �������� ��� �� ��] type=in*/
psfloat IShV; /* name=[ShV - �������� �������� �����/� �������� ����� ��� �� ��] type=in*/
psbool IsMg;/* name=[ IsMg - ���� ������� ������� �� ����� ���] type=tune*/
psfloat *Vr;/* name=[*Vm - ������ ��������� �������� (����� � �������)] type=tune size = 8*/
psfloat Kpr;/* name=[Kpr - ����������� �������������� ������� ��������� � �������� ��� ��/�] type=tune*/
psfloat Pup;/* name=[Pup - �������� � ������� �� ������ ] type=tune*/
psfloat Pdw;/* name=[Pdw - �������� � ������� �� �����] type=tune*/
psfloat Ldemp;/* name=[Ldemp - ���������� ��������� ��������� ��������] type=tune*/
psfloat Tau;/* name=[Tau - ���������� ������� ��������� ��������(���)] type=tune*/
psfloat Aps;/* name=[Aps - ��������� ������ �� ���������� - g (��/�^2)] type=tune*/
psint   Ter;/* name=[Ter - ������������� ���] type=tune*/
psfloat KPpv;/* name=[KPpv - ���������� �������������� �������� ����������� ��� ��] type=tune*/
psfloat KPav;/* name=[KPav - ���������� ���.���������� ����������� ��� ��] type=tune*/
psfloat KZav;/* name=[KZav - ���������� ���.���������� ����������� ��� ��] type=tune*/
psfloat Dlt;/* name=[Dlt - ���� ������������ �� ��������� ��] type=tune*/
psfloat X0;/* name=[X0 - ���������� ���] type=tune*/
psfloat Sh0;/* name=[Sh0 - ���������� ����� ���] type=tune*/
psfloat RV0;/* name=[V0 - ������� �������� ���] type=tune*/
psfloat ShV0;/* name=[V0 - ������� �������� ����� ���] type=tune*/
psfloat X;/* name=[X - ���������� ���] type=out*/
psfloat Sh;/* name=[Sh - ���������� ����� ���] type=out*/
psbool  Ppv;/* name=[Ppv - ������������� ������� ����������� ���(80 ��)] type=out*/
psbool  Pav;/* name=[Pav - ���.��������� ����������� ���(��)] type=out*/
psbool  Zav;/* name=[Zav - ���.��������� ����������� ���(��)] type=out*/
psfloat RV;/* name=[RV - ������� �������� ��� ��/�] type=out*/
psfloat ShV;/* name=[ShV - ������� �������� ����� ��� ��/�] type=out*/
psbool SKlo;/* name=[SKlo - ������ ������ ��л ������ (���������)] type=out*/
psbool SKlz;/* name=[SKlz - ������ ������� ��л ������ (���������)] type=out*/
psbool SEMo;/* name=[SEMo - ��������� ������������� ���] type=out*/
psbool SZMo;/* name=[SZMo - �������� ������������� ���] type=out*/
psbool Ppv0;/* name=[Ppv0 - ������������� ������� ����������� ���(80 ��)] type=internal*/
psbool Pav0;/* name=[Pav0 - ���.��������� ����������� ���] type=internal*/
psbool Zav0;/* name=[Zav0 - ���.��������� ����������� ���] type=internal*/
psbool RA00;/* name=[RA00 - ��������� ������� ������] type=internal*/
psbool RA10;/* name=[RA10 - ��������� ������� �����] type=internal*/
pschar RA50;/* name=[Ra50 - ��������� ������� ��������] type=internal*/
psbool  fls;/* name=[ fls - ���� ������������ ������] type=internal*/
psbool  flp;/* name=[ flp - ���� ������/������� �� ���������� (0 - ���, 1-�����, 2-������)] type=internal*/
psbool MyFirstEnterFlag; /* name=[MyFirstEnterFlag] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_orrsim,_S_orrsim;
void orrsim(_lpS_orrsim orrsim_s);
#endif
