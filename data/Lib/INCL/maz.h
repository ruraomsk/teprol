/*Razdel=[���������� ������]*/
/*Name=[������������� �������������� �������������]*/
#ifndef _maz_H_
#define _maz_H_
typedef struct {
psint *x; /* name=[x - ������ ������� ��������] type=in depend=[n]*/
psint r; /* name=[r - ����������� ������] type=in*/
psint n; /* name=[n - ����������� �������� �������] type=tune*/
psint y; /* name=[y - �������� ������] type=out*/
}*_lpS_maz,_S_maz;
void maz(_lpS_maz maz_s);
#endif
