/*Razdel=[���������� ������]*/
/*Name=[������ '���������� ������� �']*/
#ifndef _andn_H_
#define _andn_H_
typedef struct {
psbool *x; /* name=[x - ������ ������� ����������] type=in depend=[n]*/
psint n; /* name=[n - N-����������� ������� ������� ����������] type=tune*/
psbool y; /* name=[y - �������� ��������] type=out*/
}*_lpS_andn,_S_andn;
void andn(_lpS_andn andn_s);
#endif

