/*Razdel=[���������� ������]*/
/*Name=[������ '������������� ����������' ��� ������������ ����������]*/
#ifndef _ml_H_
#define _ml_H_
typedef struct {
psfloat x1; /* name=[x1 - ������ ������� ��������] type=in*/
psfloat x2; /* name=[x2 - ������ ������� ��������] type=in*/
psbool s; /* name=[s - ����������� ��������] type=in*/
psfloat y; /* name=[y - �������� ��������] type=out*/
}*_lpS_ml,_S_ml;
void ml(_lpS_ml ml_s);
#endif
