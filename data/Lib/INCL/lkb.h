/*Razdel=[���������� ������]*/
/*Name=[������ '���������� ������' ��� ����������� ���������]*/
#ifndef _lkb_H_
#define _lkb_H_
typedef struct {
psbool x; /* name=[x - ������� ��������] type=in*/
psbool s; /* name=[s - ����������� ��������] type=in*/
psbool y; /* name=[y - �������� ��������] type=out*/
}*_lpS_lkb,_S_lkb;
void lkb(_lpS_lkb lkb_s);
#endif
