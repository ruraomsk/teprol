/*Razdel=[���������� ������]*/
/*Name=[���������� ������ "���" � ���������� ������]*/
#ifndef _ornc_H_
#define _ornc_H_
typedef struct {
psbool *x; /* name=[X-����] type=in depend=[n]*/
psint n; /* name=[N-����� ������] type=tune*/
psbool y; /* name=[Y(���)] type=out*/
pschar SetInd; /* name=[SetInd - ��������� ��������� ������] type=out*/
}*_lpS_ornc,_S_ornc;
void ornc(_lpS_ornc ornc_s);
#endif
