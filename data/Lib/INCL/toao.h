/*Razdel=[����� ������������� ������� ����������]*/
/*Name=[�������������� � ��� Fas4]*/
#ifndef _toao_H_
#define _toao_H_
typedef struct {
psfloat x; /* name=[x   - ������� ������] type=in*/
psfloat a; /* name=[a   -  ����������� �������� �������, ������� ���� ������ �� ���] type=tune*/
psfloat b; /* name=[b   -  ������������ �������� �������, ������� ���� ������ �� ���] type=tune*/
psfloat c; /* name=[c   - ���. �������� ���� ���] type=tune*/
psfloat d; /* name=[d - ����.  �������� ���� ���] type=tune*/
psint Ter; /* name=[Ter (psint)  - ��� �������������] type=tune*/
psint min; /* name=[min - ����������� ��������� �������� ��������� �������] type=tune*/
psint max; /* name=[max - ������������ ��������� �������� ��������� �������] type=tune*/
psfloat dis; /* name=[dis - ��������� "����"] type=tune*/
psint v; /* name=[y   - �������� ������ ] type=out*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_toao,_S_toao;
void toao(_lpS_toao toao_s);
#endif
