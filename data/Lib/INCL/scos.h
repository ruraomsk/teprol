/*Razdel=[������������ �������]*/
/*Name=[������ ���������� ��������]*/
#ifndef _scos_H_
#define _scos_H_
typedef struct {
psfloat x; /* name=[x - ������� ��������] type=in*/
psfloat y; /* name=[y - �������� ��������] type=out*/
psbool berr; /* name=[berr - ������� ��������������� ��������� ���������] type=out*/
}*_lpS_scos,_S_scos;
void scos(_lpS_scos scos_s);
#endif
