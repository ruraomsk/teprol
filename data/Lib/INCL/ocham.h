/*Razdel=[��������������� �����������]*/
/*Name=[������ ���������� ����������� ������]*/
#ifndef _ocham_H_
#define _ocham_H_
typedef struct {
psfloat Ch1k; /* name=[Ch1 - ������� ��������� �� ���-11] type=in*/
psfloat Ch2k; /* name=[Ch2 - ������� ��������� �� ���15-1] type=in*/
psfloat Ch3k; /* name=[Ch2 - ������� ��������� �� ���53�] type=in*/
psfloat YAz2; /* name=[YAz2 - y-���������� ��2 ��] type=in*/
psfloat XAz; /* name=[XAz - x-���������� �� c�] type=tune*/
psfloat YAz1; /* name=[YAz1 - y-���������� ��1 c�] type=tune*/
psfloat Reff; /* name=[Reff - ����������� ������ �� c�] type=tune*/
psfloat Ak1; /* name=[Ak1 - ������. �����-1. ��������. ������� ������ ���-11 � �����. �����] type=tune*/
psfloat Bk1; /* name=[Bk1 - ������. �����-2. ��������. ������� ������ ���-11 � �����. �����] type=tune*/
psfloat Ak2; /* name=[Ak2 - ������. �����-1. ��������. ������� ������ ���15-1 � �����. �����] type=tune*/
psfloat Bk2; /* name=[Bk2 - ������. �����-2. ��������. ������� ������ ���15-1 �����. �����] type=tune*/
psfloat Ak3; /* name=[Ak3 - ������. �����-1. ��������. ������� ������ ���53� � �����. �����] type=tune*/
psfloat Bk3; /* name=[Bk3 - ������. �����-2. ��������. ������� ������ ���53� � �����. �����] type=tune*/
psfloat XCm1; /* name=[XCm1 - x-���������� ������ ���-11 ��] type=tune*/
psfloat YCm1; /* name=[YCm1 - y-���������� ������ ���-11 ��] type=tune*/
psfloat XCm2; /* name=[XCm2 - x-���������� ������ ���15-1 ��] type=tune*/
psfloat YCm2; /* name=[YCm2 - y-���������� ������ ���15-1 ��] type=tune*/
psfloat XCm3; /* name=[XCm3 - x-���������� ������ ���53� ��] type=tune*/
psfloat YCm3; /* name=[YCm3 - y-���������� ������ ���53� ��] type=tune*/
pschar  type; /* name=[type - ��� ������ ���-11 1- ��� ��1, 2- ��� ��2, >2 ��� ] type=tune*/
psfloat Kpr1k; /* name=[Kpr1 - �����. �������������� �������->�����/� ���-11 ] type=tune*/
psfloat Kpr2k; /* name=[Kpr2 - �����. �������������� �������->�����/� ���15-1] type=tune*/
psfloat Kpr3k; /* name=[Kpr3 - �����. �������������� �������->�����/� ���53�] type=tune*/
psfloat Kprm; /* name=[Kprm - �����. �������������� �����->��������] type=tune*/
psfloat Np; /* name=[Np - ����� ��������� �� ��  (�����/�)] type=out*/
psfloat Nm; /* name=[Nm - �������� ��] type=out*/
psbool  Flerr;  /* name=[Err - ���� ������������� ������] type=out*/
psfloat Np1; /* name=[Np1 - ����� ��������� �� 1 ������  (�����/�)] type=out*/
psfloat Np2; /* name=[Np2 - ����� ��������� �� 2 ������  (�����/�)] type=out*/
psfloat Np3; /* name=[Np3 - ����� ��������� �� 3 ������  (�����/�)] type=out*/
psint Nkm; /* name=[Nkm - ������� ������ 1-���-11,2-���-15�-1,3-���-53�,0-��� �������] type=out*/
psint  Nk; /* name=[Nk - ������� ������] type=internal*/
}*_lpS_ocham,_S_ocham;
void ocham(_lpS_ocham ocham_s);
#endif
