/*Razdel=[������������ ������]*/
/*Name=[�������� ��������� ������ ���]*/
#ifndef _zpfs_H_
#define _zpfs_H_
typedef struct {
psbool x; /* name=[x - ������� ������] type=in*/
psfloat tz; /* name=[tz - ����� �������� ���] type=tune*/
psbool y; /* name=[y - �������� ������] type=out*/
psfloat tx; /* name=[tx - ����� ����������� ���] type=internal*/
pschar y0; /* name=[y0] type=internal*/
}*_lpS_zpfs,_S_zpfs;
void zpfs(_lpS_zpfs zpfs_s);
#endif

