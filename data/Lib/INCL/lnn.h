/*Razdel=[������������ �������]*/
/*Name=[������ ���������� ������������ ���������]*/
#ifndef _lnn_H_
#define _lnn_H_
typedef struct {
psfloat x; /* name=[x - ��������] type=in*/
psfloat y; /* name=[y - �������� �������� y=ln(x)] type=out*/
}*_lpS_lnn,_S_lnn;
void lnn(_lpS_lnn lnn_s);
#endif
