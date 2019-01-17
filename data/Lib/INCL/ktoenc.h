/*Razdel=[������ ���� �-1000]*/
/*Name=[������ �������������� ���������� � ��������� ��������]*/
#ifndef _ktoenc_H_
#define _ktoenc_H_
typedef struct {
psfloat Xtek; /* name=[Xtek - ������� ��������� ���������, ��] type=in*/
psfloat C; /* name=[C - ����������� ��� �������������� ����� � ��] type=tune*/
psfloat CNsm; /* name=[CNsm - �������� ��������, ��] type=tune*/
psint Ter; /* name=[Ter - ��� �������������] type=tune*/
pslong Ytek; /* name=[Ytek - ������� ��������� ��������� � �����] type=out*/
psbool Mov; /* name=[Mov - ������� ��������] type=out*/
psbool ClkW; /* name=[ClkW - �������� �� ������� ������� ] type=out*/
psbool UnClkW; /* name=[UnClkW - �������� ������ ������� �������] type=out*/
pslong Enc; /* name=[Enc - ������, ������� ������ ���� ������� ��������� vencf] type=out*/
psfloat Xtek0;  /* name=[Xtek0 - ��������� ��������� �� ������� ����, ��] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_ktoenc,_S_ktoenc;
void ktoenc(_lpS_ktoenc ktoenc_s);
#endif
