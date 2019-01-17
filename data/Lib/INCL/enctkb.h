/*Razdel=[������ ���� �-1000]*/
/*Name=[������ �������������� ��������� �������� � ����������]*/
#ifndef _enctkb_H_
#define _enctkb_H_
typedef struct {
psbool  Regim; /* name=[Regim - ����� ������-��������� ��������/�������������� ���������] type=in*/
psfloat Kt; /* name=[Kt - �������, ���������(�����������) ��������� ���������, ��] type=in*/
pslong  Nk; /* name=[Nk - ������� ��������� ��������, � �����] type=in*/
pslong  LeftBound; /* name=[LB - ������ ������� ���.���� ��������, � �����] type=tune*/
pslong  RightBound; /* name=[RB - ������� ������� ���.���� ��������, � �����] type=tune*/
psfloat C;   /* name=[C - ����������� ��� �������������� ����� � ��] type=tune*/
psfloat KtSt; /* name=[KtSt - ��������� ��������� ���������, ��] type=tune*/
pslong  Nsm;  /* name=[Nsm - �������� �������� ���������� ������������ 0 ��������] type=tune*/
psfloat Ytek; /* name=[Ytek - ������� ��������� ��������� � ������ ��������, �� (��.)] type=out*/
psbool  Sam;  /* name=[Sam- ������� ��������� ��������] type=out*/
psbool  bErr;  /* name=[bErr- ������� ������� ������ ��������] type=out*/
pslong  Nk0;  /* name=[Nk0 - ���������� ��������� ��������, � �����] type=internal*/
psbool  SetFlag; /* name=[SetFlag - ������� ������ �������� � ������] type=internal*/
psbool  FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_enctkb,_S_enctkb;
void enctkb(_lpS_enctkb enctkb_s);
#endif
