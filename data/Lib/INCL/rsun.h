/*Razdel=[���������� ������]*/
/*Name=[������ 'rsun-�������' � ����������� ������]*/
#ifndef _rsun_H_
#define _rsun_H_
typedef struct {
psbool r; /* name=[r - ������ ������ R] type=in*/
pslong s; /* name=[s - ������� ������ S] type=in*/
pslong q; /* name=[q - �������� ��������] type=out*/
psint qi; /* name=[qi - �������� ��������] type=out*/
pslong q0; /* name=[q0 - ���������� ��������] type=internal*/
}*_lpS_rsun,_S_rsun;
void rsun(_lpS_rsun rsun_s);
#endif
