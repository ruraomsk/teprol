/*Razdel=[������������ ������]*/
/*Name=[�������� ������� ������ ���]*/
#ifndef _zzfs_H_
#define _zzfs_H_
typedef struct {
psbool x; /* name=[x - ������� ������] type=in*/
psfloat tz; /* name=[tz - ����� �������� ���] type=tune*/
psbool y; /* name=[y - �������� ������] type=out*/
psfloat tx; /* name=[tx - ����� ����������� ���] type=internal*/
pschar y0; /* name=[y0] type=internal*/
}*_lpS_zzfs,_S_zzfs;
void zzfs(_lpS_zzfs zzfs_s);
#endif

