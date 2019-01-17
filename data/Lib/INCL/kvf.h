/*Razdel=[������ ��������� ��������� ����������]*/
/*Name=[�������� ������� float]*/
#ifndef _kvf_H_
#define _kvf_H_
typedef struct {
psbool x1; /* name=[x - ������� ������ 1] type=in*/
psbool x2; /* name=[x - ������� ������ 2] type=in*/
psfloat intrv; /* name=[intrv - ������������ ��������� ������� � ��������] type=in*/
psfloat y; /* name=[y - �������� ����� ��������� �1 � �2 mc] type=out*/
psint imin; /* name=[imin - ������ �� ����� �������] type=out*/
psint isek; /* name=[isek - ������� �� ����� �������] type=out*/
psbool x0; /* name=[��� ������ ������� x1] type=internal*/
psfloat y0; /* name=[�������� ����� ��������� �1 � �2] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_kvf,_S_kvf;
void kvf(_lpS_kvf kvf_s);
#endif
