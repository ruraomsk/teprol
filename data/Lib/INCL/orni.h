/*Razdel=[���������� ������]*/
/*Name=[���������� ������ "���" � ���������� ��������� ������]*/
#ifndef _orni_H_
#define _orni_H_
typedef struct {
psbool *x; /* name=[x - ������ ������� ��������] type=in depend=[n]*/
psint n; /* name=[n - ����������� ������� ������� ��������] type=tune*/
psbool y; /* name=[y - �������� ������] type=out*/
pslong SetInd; /* name=[SetInd - ��������� ��������� ������] type=out*/
}*_lpS_orni,_S_orni;
void orni(_lpS_orni orni_s);
#endif
