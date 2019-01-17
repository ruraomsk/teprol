/*Razdel=[������ Bars4]*/
/*Name=[������ ����������� ������������ ����������� �������� ���������]*/
#ifndef _fnapb_H_
#define _fnapb_H_
typedef struct {
psfloat x; /* name=[x - �������  ��������� ��������� � ��] type=in*/
psfloat xz; /* name=[xz - �������� ��������� ��������� � ��] type=in*/
psbool CheckSpeed; /* name=[CheckSpeed - ������� ��������� ��������] type=in*/
psbool KvitSam; /* name=[KvitSam - ������������ ��������] type=in*/
psbool Dvig; /* name=[Dvig - ���� ������� �� ��������] type=in*/
psfloat Vz; /* name=[Vz - �������� ��������, �/���] type=in*/

psfloat Trz; /* name=[Trz - ����� ������� ��������� ��� �������� �� ����� ��������] type=tune*/
psfloat Delta; /* name=[Delta - ���������� ���������� ��������,�/���] type=tune*/
psfloat MDelta; /* name=[MDelta - ���������� ���������� ��������,�/���] type=tune*/
psfloat p; /* name=[p - ������� ������������ �������� � ��(��.)] type=tune*/
psfloat pl; /* name=[pl - ����������� ����������� ��� ��������� �������� � ��(��.)] type=tune*/
psint n;  /* name=[n - ����������� ������� ���������� ��������] type=tune*/
psfloat tz; /* name=[tz - ������������ ����������� �������� ��������� sek] type=tune*/
psfloat tnm; /* name=[tnm - ������� ������������ ���������� �� ���������� sek] type=tune*/
psfloat tzZS; /* name=[tzZS - ����� �������� �������� ����� ���������� 0 �������� sek] type=tune*/

psbool ToLeft; /* name=[ToLeft - ��� �����,�����,�����,����.�������] type=out*/
psbool ToRight; /* name=[ToRight - ��� ������,�����,����,��.�������] type=out*/
psfloat Speed; /* name=[Speed - �������� �����������] type=out*/
psbool Shift; /* name=[Shift - ������� ��������] type=out*/
psbool NoMove; /* name=[NoMove - ���������� �� ���������� �����������] type=out*/
psbool Bl; /* name=[Bl - ���������� �� ���������� ��������] type=out*/
psbool MBl; /* name=[MBl - ���������� �� ���������� �������� � ������� �������] type=out*/
psfloat SrcPoint; /* name=[SrcPoint - ��������� ����� �� ������� ��������� �������] type=out*/

psint xptr; /* name=[��������� ������� ������� � ������� ���������] type=internal*/
psfloat *x0; /* name=[x0 - ������ ���������� �������� ���������] type=internal depend=[n]*/
psfloat *tim0; /* name=[tim0 - ������ �������� ������� �����] type=internal depend=[n]*/
psint mcount; /* name=[count - ������� ���������� ������� �������� ���������] type=internal*/
psfloat sumtim; /* name=[sumtim - ����� � ����] type=internal*/
psfloat sumtakt; /* name=[sumtim - ����� � ����] type=internal*/
psfloat StSpeed; /* name=[StSpeed - ��������� �������� - � ������� ���������� ��������� ��������] type=internal*/
psfloat Vz0; /* name=[Vz0 - ���������� �������� ��������] type=internal*/
psint flRazg; /* name=[������� �������/����������] type=internal*/
psfloat DelSp; /* name=[DelSp - ����� ������������ ���������] type=internal*/
psfloat z0; /* name=[z0 - ����� ����������� ��������] type=internal*/
psfloat txZS; /* name=[txZS] type=internal*/
psfloat tx; /* name=[tx] type=internal*/
psfloat txd; /* name=[txd] type=internal*/
psfloat txMBl; /* name=[tx] type=internal*/
psfloat txBl; /* name=[tx] type=internal*/
psfloat Speed0; /* name=[Speed0 - ���������� �������� �������� �����������] type=internal*/
psfloat xz0; /* name=[xz0 - ����� ������� ��] type=internal*/
psfloat tz0; /* name=[tz0 - ����� ������ �� ������ ������� ���] type=internal*/
psbool Shift0; /* name=[Shift0 - ������� ��������] type=internal*/
psbool ShCntlSp0; /* name=[ShCntlSp0 - ������� �������� ������� ����� ���������� 0 ��������] type=internal*/
psbool ShiftControl; /* name=[ShiftControl - ������� ��������] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_fnapb,_S_fnapb;
void fnapb(_lpS_fnapb fnapb_s);
#endif
