/*Razdel=[���������� ������]*/
/*Name=[������ '������������� ��������������' ��� ������������ ����������]*/
#ifndef _ma_H_
#define _ma_H_
typedef struct {
psfloat *x; /* name=[x - ������ ������� ����������] type=in depend=[n]*/
psint r; /* name=[r - ����������� ��������] type=in*/
psint n; /* name=[n - N-����������� ������� x] type=tune*/
psfloat y; /* name=[y - �������� ��������] type=out*/
}*_lpS_ma,_S_ma;
void ma(_lpS_ma ma_s);
#endif
