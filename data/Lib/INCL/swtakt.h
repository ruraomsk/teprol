/*Razdel=[������������ ������]*/
/*Name=[������ ������������ �������� �� �������� ���]*/
#ifndef _swtakt_H_
#define _swtakt_H_
typedef struct {
psbool x; /* name=[x - ������������ �������� �� �������� ���] type=in*/
psbool y; /* name=[y - �����������] type=out*/
psbool x0; /* name=[x0 - �������� �������� ��������� �� ���������� ����] type=internal*/
}*_lpS_swtakt,_S_swtakt;
void swtakt(_lpS_swtakt swtakt_s);
#endif
