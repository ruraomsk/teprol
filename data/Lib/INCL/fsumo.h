/*Razdel=[������������ �������]*/
/*Name=[������ '��������' ������������ ���������� �� ��� �����]*/
#ifndef _fsumo_H_
#define _fsumo_H_
typedef struct {
psfloat x1; /* name=[x1 - ������ ���������] type=in*/
psfloat x2; /* name=[x2 - ������ ���������] type=in*/
psfloat y; /* name=[y - ����� y=x1+x2] type=out*/
}*_lpS_fsumo,_S_fsumo;
void fsumo(_lpS_fsumo fsumo_s);
#endif
