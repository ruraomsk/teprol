/*Razdel=[���������� ������]*/
/*Name=[������ '���������� ������� � �� 4 �����']*/
#ifndef _and4_H_
#define _and4_H_
typedef struct {
psbool x1; /* name=[x1 - ���� 1] type=in */
psbool x2; /* name=[x2 - ���� 2] type=in */
psbool x3; /* name=[x3 - ���� 3] type=in */
psbool x4; /* name=[x4 - ���� 4] type=in */
psbool y; /* name=[y - �������� ��������] type=out*/
}*_lpS_and4,_S_and4;
void and4(_lpS_and4 and4_s);
#endif