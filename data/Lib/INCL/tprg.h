/*Razdel=[���������� ��������]*/
/*Name=[��������������� ���� � ������������]*/
#ifndef _tprg_H_
#define _tprg_H_
typedef struct {
psfloat x; /* name=[X] type=in*/
psfloat e; /* name=[E-������� ������� ���������������] type=tune*/
psfloat f; /* name=[F-������� ������� ���������������] type=tune*/
psfloat c; /* name=[C-������� ������� ���������������] type=tune*/
psfloat d; /* name=[D-������� ������� ���������������] type=tune*/
psbool  y; /* name=[Y  f <= x <= c  --> y = 1] type=out*/
psbool y0; /* name=[state] type=internal*/
}*_lpS_tprg,_S_tprg;
void tprg(_lpS_tprg tprg_s);
#endif
