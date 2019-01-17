/*Razdel=[��������������� �����������]*/
/*Name=[������ ���������� ��������� ��������]*/
#ifndef _provsbr_H_
#define _provsbr_H_
typedef struct {
psbool pusk; /* name=[pusk - ���������� ���������� ���������] type=in*/
psbool kvit;  /* name=[kvit - ���� ������� ��������� � ������] type=in*/
psbool rzINI; /* name=[sbINI - ��������� �������� ���] type=in*/
psbool rzVuIS; /* name=[sbVuIS - ��������� �������� ������ �� �� ��] type=in*/
psbool rz2UR; /* name=[sb2UR - ��������� �������� ������ �� 2��] type=in*/
psbool rzNupIS; /* name=[sbNupIS - ��������� �������� ������ �� ��� ��] type=in*/
psbool rzVuRB; /* name=[sbVuRB - ��������� �������� ������ �� �� ��] type=in*/
psbool zvINI; /* name=[sbINI - ���������� �������� ���] type=in*/
psbool zvVuIS; /* name=[sbVuIS - ���������� �������� ������ �� �� ��] type=in*/
psbool zv2UR; /* name=[sb2UR - ���������� �������� ������ �� 2��] type=in*/
psbool zvNupIS; /* name=[sbNupIS - ���������� �������� ������ �� ��� ��] type=in*/
psbool zvVuRB; /* name=[sbVuRB - ���������� �������� ������ �� �� ��] type=in*/
psint np; /* name=[np - ������ ������� �������� ���������� ���������] type=tune*/
psfloat *Tpr; /* name=[Tpr - ����� ������ �������� �� �� ������ ���������] type=tune depend=[np]*/
pschar *type; /* name=[type - ��� �������� 1-���,2-�� ��,3-2��,4-��� ��,5-�� ��, 6-�����] type=tune depend=[np]*/
psbool FinPr; /* name=[FinPr - ����� ���������] type=out*/
psint Min; /* name=[Min - �� ����� ��������� (�����)] type=out*/
psint Sek;  /* name=[Sek - �� ����� ��������� (������)] type=out*/
psbool ErrPr; /* name=[ErrPr - ������������ ��������� �� ������] type=out*/
psbool sbINI; /* name=[sbINI - ������ �������� ���] type=out*/
psbool sbVuIS; /* name=[sbVuIS - ������ �������� ������ �� �� ��] type=out*/
psbool sb2UR; /* name=[sb2UR - ������ �������� ������ �� 2��] type=out*/
psbool sbNupIS; /* name=[sbNupIS - ������ �������� ������ �� ��� ��] type=out*/
psbool sbVuRB; /* name=[sbVuRB - ������ �������� ������ �� �� ��] type=out*/
psint  Step; /* name=[ - ������� ��� ���������] type=internal*/
pschar *rz; /* name=[- ��������� �������� 0-�� �����������, 1-��������, 2-��������������, 3-������� ���������, 4-������] type=internal depend=[np]*/
psfloat TimS; /* name=[����� �� ������ ���������] type=internal*/
psbool FinPr0; /* name=[FinPr - ����� ���������] type=internal*/
psbool ErrPr0; /* name=[ErrPr - ������������ ��������� �� ������] type=internal*/
psbool sbINI0; /* name=[sbINI - ������ �������� ���] type=internal*/
psbool sbVuIS0; /* name=[sbVuIS - ������ �������� ������ �� �� ��] type=internal*/
psbool sb2UR0; /* name=[sb2UR - ������ �������� ������ �� 2��] type=internal*/
psbool sbNupIS0; /* name=[sbNupIS - ������ �������� ������ �� ��� ��] type=internal*/
psbool sbVuRB0; /* name=[sbVuRB - ������ �������� ������ �� �� ��] type=internal*/
psbool MyFirstEnterFlag; /* name=[ ] type=internal*/
}*_lpS_provsbr,_S_provsbr;
void provsbr(_lpS_provsbr provsbr_s);
#endif