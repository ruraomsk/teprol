/*Razdel=[���������� ������]*/
/*Name=[������ 'RS-�������' � ����������� ������]*/
#ifndef _rs_H_
#define _rs_H_
typedef struct {
psbool r; /* name=[r - ������ ������ R] type=in*/
psbool s; /* name=[s - ������� ������ S] type=in*/
psbool q; /* name=[q - �������� ��������] type=out*/
psbool nq; /* name=[nq - �������� q] type=out*/
psbool q0; /* name=[q0 - ���������� ��������] type=internal*/
}*_lpS_rs,_S_rs;
void rs(_lpS_rs rs_s);
#endif
