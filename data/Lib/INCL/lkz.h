/*Razdel=[���������� ������]*/
/*Name=[������ '���������� ������' ��� �������������� ���������]*/
#ifndef _lkz_H_
#define _lkz_H_
typedef struct {
psint x; /* name=[� - ������� ��������] type=in*/
psbool s; /* name=[s - ����������� ��������] type=in*/
psint y; /* name=[� - �������� ��������] type=out*/
}*_lpS_lkz,_S_lkz;
void lkz(_lpS_lkz lkz_s);
#endif
