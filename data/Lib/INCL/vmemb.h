/*Razdel=[������������ ������]*/
/*Name=[������ ������ ��� ����������� ���������]*/
#ifndef _vmemb_H_
#define _vmemb_H_
typedef struct {
psbool x; /* name=[x - ������� ��������] type=in*/
psbool y; /* name=[y - �������� ��������] type=out*/
psbool x0; /* name=[x0 - �������� �������� ��������� �� ���������� ����] type=internal*/
}*_lpS_vmemb,_S_vmemb;
void vmemb(_lpS_vmemb vmemb_s);
#endif
