/*Razdel=[������������ ������]*/
/*Name=[������ ��������� ��������� �������� ������]*/
#ifndef _cntch_H_
#define _cntch_H_
typedef struct {
pslong x; /* name=[x - ������� ��������] type=in*/
psbool y; /* name=[y - �������� ��������] type=out*/
pslong x0; /* name=[x0 - �������� �������� ��������� �� ���������� ����] type=internal*/
}*_lpS_cntch,_S_cntch;
void cntch(_lpS_cntch cntch_s);
#endif
