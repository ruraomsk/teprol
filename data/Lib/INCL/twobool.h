/*Razdel=[����� ������������� ������� ����������]*/
/*Name=[����������� ����������� ������� �� 2]*/
#ifndef _twobool_H_
#define _twobool_H_
typedef struct {
psbool S; /* name=[S (psbool)  - ������� ������] type=in*/

psint Ter; /* name=[Ter (psint)  - ��� �������������] type=tune*/

psbool Out1; /* name=[Out1 (psbool) - ������ �������� ������] type=out*/
psbool Out2; /* name=[Out2 (psbool) - ������ �������� ������] type=out*/

psbool Out10; /* name=[Out10 (psbool) - ������� �������� ��������� �������] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_twobool,_S_twobool;
void twobool(_lpS_twobool twobool_s);
#endif

