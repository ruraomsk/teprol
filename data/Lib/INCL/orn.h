/*Razdel=[���������� ������]*/
/*Name=[������ '���������� ������� ���']*/
#ifndef _orn_H_
#define _orn_H_
typedef struct {
psbool *x; /* name=[x - ������ ������� ����������] type=in depend=[n]*/
psint n; /* name=[n - N-����������� ������� x] type=tune*/
psbool y; /* name=[y - �������� ��������] type=out*/
}*_lpS_orn,_S_orn;
void orn(_lpS_orn orn_s);
#endif
