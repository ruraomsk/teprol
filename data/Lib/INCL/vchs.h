/*Razdel=[����� ������������� ������� ����������]*/
/*Name=[������ ������������� ������]              */
#ifndef _vchs_H_
#define _vchs_H_
typedef struct {
psfloat N1;   /* name=[N1 - ����� ��������� �� ��1 (�����/�)] type=in*/
psfloat N2;   /* name=[N2 - ����� ��������� �� ��2 (�����/�)] type=in*/
psfloat XAz1; /* name=[XAz1 - x-���������� ��1 c�] type=tune*/
psfloat YAz1; /* name=[YAz1 - y-���������� ��1 c�] type=tune*/
psfloat YAz2; /* name=[YAz2 - y-���������� ��2 c�] type=tune*/
psfloat XCm; /* name=[XCm - x-���������� ������ c�] type=tune*/
psfloat YCm; /* name=[YCm - y-���������� ������ ��] type=tune*/
pschar  type; /* name=[type - ��� ������] type=tune*/
psfloat Ak; /* name=[Ak - ������������� �����������-1 �������������� �����/� - ���/�] type=tune*/
psfloat Bk; /* name=[Bk - ������������� �����������-2 �������������� �����/� - ���/�] type=tune*/
psfloat Fk; /* name=[Fk - �����. �������������� �������->�����/�] type=tune*/
psfloat FMax; /* name=[FMax - ���������� ������� ���������� ������� ��] type=tune*/
psfloat FMin; /* name=[FMin - ����������� ������� ���������� ������� ��] type=tune*/
psfloat Reff; /* name=[Reff -����������� ������ �� (��)] type=tune*/
psfloat Chim; /* name=[Chim - ������� ��������� ������ ��] type=out*/
psfloat Chim0; /* name=[���������� ������� ��������� ������ ��] type=internal*/
}*_lpS_vchs,_S_vchs;
void vchs(_lpS_vchs vchs_s);
#endif
