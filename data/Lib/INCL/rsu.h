/*Razdel=[���������� ������]*/
/*Name=[������ 'rsu-�������' � ����������� ������, ��������� ������ �����������]*/
/*  */
#ifndef _rsu_H_
#define _rsu_H_
typedef struct {
psbool r; /* name=[r - ������ ������ R] type=in*/
pslong s; /* name=[s - ������� ������ S] type=in*/
pslong q; /* name=[q - �������� ��������] type=out*/
pslong q0; /* name=[q0 - ���������� ��������] type=internal*/
}*_lpS_rsu,_S_rsu;
void rsu(_lpS_rsu rsu_s);
#endif
