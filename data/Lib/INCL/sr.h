/*Razdel=[������������ �������]*/
/*Name=[������ ���������� �������� �������� �� ������� ������������ ����������]*/
#ifndef _sr_H_
#define _sr_H_
typedef struct {
psfloat *x; /* name=[x - ������ ������� ����������] type=in depend=[n]*/
psint n; /* name=[n - N-����������� ������� x] type=tune*/
psfloat y; /* name=[y - ������� �������� ���������� �������� �������] type=out*/
}*_lpS_sr,_S_sr;
void sr(_lpS_sr sr_s);
#endif
