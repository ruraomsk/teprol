/*Razdel=[���������� ��������]*/
/*Name=[������ ������������ ���������� �����]*/
#ifndef _newstage_H_
#define _newstage_H_
typedef struct {
psbool caz1; /* name=[�az1-��������� ���������� ���������� ��1] type=in*/
psbool caz2; /* name=[�az2-��������� ���������� ���������� ��2] type=in*/
psbool fin1; /* name=[fin1-��������� �������� ��������� ��1] type=in*/
psbool fin2; /* name=[fin2-��������� �������� ��������� ��2] type=in*/
psbool Let; /* name=[Let-��������� ����� ����] type=out*/
}*_lpS_newstage,_S_newstage;
void newstage(_lpS_newstage newstage_s);
#endif