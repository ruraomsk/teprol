/*Razdel=[������ ���� �-1000]*/
/*Name=[������ ����������� ��������� ��������� � ����������� �����������]*/
#ifndef _nocnm_H_
#define _nocnm_H_
typedef struct {
psbool  Pv;/* name=[Pv - ���. ����������� ���������] type=in*/
psbool  Zv;/* name=[Zv - ���. ����������� ���������] type=in*/
psbool Mup;/* name=[ Mup - ����������� �������� �����] type=out*/
psbool Mdw;/* name=[ Mdw - ����������� �������� �����] type=out*/
psint Ready; /* name=[Ready - ���������� � ����������(0-��������,1-��������, 2-��� �������,3-������)] type=out*/ 
psbool Pv0;/* name=[ - ���. ����������� ���������] type=internal*/
psbool Zv0;/* name=[ - ���. ����������� ���������] type=internal*/
psbool MyFirstEnterFlag; /* name=[MyFirstEnterFlag] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_nocnm,_S_nocnm;
void nocnm(_lpS_nocnm nocnm_s);
#endif