/*Razdel=[��������������� �����������]*/
/*Name=[������ ������� 10 ���]*/
#ifndef _decatron_H_
#define _decatron_H_
typedef struct {
psbool pusk; /* name=[pusk - ���������� ���������� ���������] type=in*/
psint Sek;  /* name=[Sek - �� ����� ��������� (������)] type=out*/
pslong TimS; /* name=[����� ������] type=internal*/
}*_lpS_decatron,_S_decatron;
void decatron(_lpS_decatron decatron_s);
#endif