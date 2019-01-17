/*Razdel=[������ ���� �-1000]*/
/*Name=[������ ���������� ��������� �������� ��������� � ������� ����������]*/
#ifndef _cnshd_H_
#define _cnshd_H_
typedef struct {
psbool KvitSam; /* name=[KvitSam - ������������ ��������] type=in*/
psfloat Xt; /* name=[Xt - �������  ��������� ��������� ��] type=in*/
psfloat Xz; /* name=[Xz - �������� ��������� ��������� ��] type=in*/
psfloat UstK; /* name=[UstK - �������� ������� �� ���������� ��] type=in*/
psbool Rr; /* name=[Rr - ���� �������] type=in*/
psbool BLDv; /* name=[BlDv - ���������� ��������] type=in*/
psbool AvtSt; /* name=[AvtSt - ���������� �� �������/���] type=in*/
psint nspd_fw; /* name=[nspd_fw - ����������� ����� �������� �����] type=tune*/
psfloat  *Lt_fw; /* name=[Lt_fw - ����� ��������� ������ �������� �������� �����(��)] type=tune depend=[nspd_fw]*/
psint *Vr_fw; /* name=[Vr_fw - ����� ��������� �������� �����(2-6)] type=tune depend=[nspd_fw]*/
psint nspd_bw; /* name=[nspd_bw - ����������� ����� �������� �����] type=tune*/
psfloat  *Lt_bw; /* name=[Lt_bw - ����� ��������� ������ �������� �������� �����(��)] type=tune depend=[nspd_bw]*/
psint *Vr_bw; /* name=[Vr_bw - ����� ��������� �������� �����(2-6)] type=tune depend=[nspd_bw]*/
psfloat Dlt; /* name=[Dlt - ���� ������������������ � �� (��.)] type=tune*/
psfloat DltRet; /* name=[DltRet - ���� �������� � �� (��.)] type=tune*/
psfloat Tim; /* name=[Tim - ����� ���������� ���� ������������������ �� ���� ��������, ���] type=tune*/
psfloat Kpr; /* name=[Kpr - ����������� �������������� �������� �� ������� � ��/���] type=tune*/
psbool Nz; /* name=[Nz = 1 - �������� � ���� ���.] type=out*/
psbool OnUst; /* name=[OnUst = 1 - �������� �� �������� �������] type=out*/
psfloat Xts; /* name=[Xts - �������  ��������� ��������� ��] type=out*/
psbool RA3;/* name=[ RA3 - ���������� ��������] type=out*/
psbool RA0;/* name=[ RA0 - �������� �����] type=out*/
psbool RA1;/* name=[ RA1 - �������� �����] type=out*/
psbool RA2;/* name=[ RA2 - 0-� ��� ��������] type=out*/
psbool RA4;/* name=[ RA4 - 1-� ��� ��������] type=out*/
psbool RA5;/* name=[ RA5 - 2-� ��� ��������] type=out*/
psbool RB3;/* name=[ RB3 - ������� ������� (�����)] type=out*/ 
psfloat Vz; /* name=[Vz - �������� �������� ��������� (��/���)] type=out*/
pschar Ready; /* name=[Ready - ���������� � ����������(0-��������,1-��������, 2-��� �������,3-������)] type=out*/ 
psfloat X0; /* name=[������� ���� ������������������ (Dlt/Du) � �� (��.)] type=internal*/
psfloat t0; /* name=[����� ���������� � ���� ��������] type=internal*/
pschar BLDv0; /* name=[BlDv - ���������� ��������] type=internal*/
}*_lpS_cnshd,_S_cnshd;
void cnshd(_lpS_cnshd cnshd_s);
#endif
