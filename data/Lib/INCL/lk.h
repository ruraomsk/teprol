/*Razdel=[���������� ������]*/
/*Name=[������ '���������� ������' ��� ������������� ���������]*/
#ifndef _lk_H_
#define _lk_H_
typedef struct {
psfloat x; /* name=[x - ������� ��������] type=in*/
psbool s; /* name=[s - ����������� ��������] type=in*/
psfloat y; /* name=[y - �������� ��������] type=out*/
}*_lpS_lk,_S_lk;
void lk(_lpS_lk lk_s);
#endif
