/*Razdel=[���������� ��������]*/
/*Name=[������ ������������ ���������� �������]*/
#ifndef _inf_H_
#define _inf_H_
typedef struct {
psfloat x; /* name=[X] type=in*/
psfloat *a; /* name=[Ai, i=1..N -�������� ������� �����] type=tune depend=[n]*/
psfloat *b; /* name=[Bi, i=1..N -�������� ������� �����] type=tune depend=[n]*/
psint n; /* name=[N] type=tune*/
psfloat y; /* name=[Y] type=out*/
psint ind; /* name=[IND] type=out*/
}*_lpS_inf,_S_inf;
void inf(_lpS_inf inf_s);
#endif
