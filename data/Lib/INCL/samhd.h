/*Razdel=[��������� �����������]*/
/*Name=[������ ���������� ����������� � ���������� ]*/
#ifndef _samhd_H_
#define _samhd_H_
typedef struct {
psbool KvitSam; /* name=[KvitSam - ������������ ��������] type=in*/
psbool BLDv; /* name=[BlDv - ���������� �������� �����] type=in*/
psbool BLVz; /* name=[BlVz - ���������� �������� �����] type=in*/
psbool DvUp; /* name=[DvUp - ���� ������� �� �������� �����] type=in*/
psbool DvDw; /* name=[DvDw - ���� ������� �� �������� �����] type=in*/
psbool FDvUp; /* name=[FDvUp - ����. �������� �����] type=in*/
psbool FDvDw; /* name=[FvDw - ����. �������� �����] type=in*/
psbool Pkv; /* name=[Pkv - �������� �������� �����������] type=in*/
psbool Pkav; /* name=[Pkav - �������� �������� ��������� �����������] type=in*/
psbool Zkv; /* name=[Zkv - ������ �������� �����������] type=in*/
psbool Zkav; /* name=[Zkav - ������ �������� ��������� �����������] type=in*/
pschar TypeDev; /* name=[TypeDev - ��� ��������� 0-���������, 1-������������, 2-����. � ����������� ] type=tune*/
psfloat tzNm; /* name=[tzNm - ����� �������� ������������ ����������(���.��)] type=tune*/
psfloat tzSm; /* name=[tzSm - ����� �������� ������������ �������� (���.��)] type=tune*/
psfloat tzLd; /* name=[tzLd - ����� �������� ������������ ���������� ������� �������� (���.��)] type=tune*/
psbool Shift; /* name=[Shift - ������� ��������] type=out*/
psbool NoMove; /* name=[NoMove - ���������� �� ���������� �����������] type=out*/
psbool BadMove; /* name=[BadMove - ������� ������ � ����������� �����������] type=out*/
psbool LongMove; /* name=[LongMove - ������� ���������� ������� �����������] type=out*/
psbool UpMove; /* name=[UpMove - ������ ����������� �����,������,�������] type=out*/ 
psbool DwMove; /* name=[DwMove - ������ ����������� ����,�����,�������] type=out*/ 
psbool FUpMove; /* name=[FUpMove - ���� ����������� �����,������,�������] type=out*/ 
psbool FDwMove; /* name=[FDwMove - ���� ����������� ����,�����,�������] type=out*/ 
psint Ready; /* name=[Ready - ���������� � ����������(0-��������,1-��������, 2-��� �������,3-������)] type=out*/ 
psbool FinMove; /* name=[FoutMove - ������� ���������� �����������] type=out*/ 
psbool CanMove; /* name=[CanMove - ������� ���������� �����������] type=out*/ 
pschar DvUp0; /* name=[- ���� ������� �� �������� �����] type=internal*/
pschar DvDw0; /* name=[- ���� ������� �� �������� �����] type=internal*/
pschar FDvUp0; /* name=[- ���� ������� �� �������� �����] type=internal*/
pschar FDvDw0; /* name=[- ���� ������� �� �������� �����] type=internal*/
pschar BlDv0; /* name=[- ���� ����������] type=internal*/
pschar Pkv0; /* name=[Pkv - �������� �������� �����������] type=internal*/
pschar Pkav0; /* name=[Pkav - �������� �������� ��������� �����������] type=internal*/
pschar Zkv0; /* name=[Zkv - ������ �������� �����������] type=internal*/
pschar Zkav0; /* name=[Zkav - ������ �������� ��������� �����������] type=internal*/
psfloat txNm; /* name=[txNm - ������� �������� ������������ ����������] type=internal*/
psfloat txSm; /* name=[txSm - ������� �������� ������������ ��������] type=internal*/
psfloat txHr; /* name=[txHr - ������� �������� ������������ ������ ����������� �����������] type=internal*/
psfloat txLd; /* name=[txLd - ������� �������� ������������ ���������� ������� �����������] type=internal*/
pschar fef; /* name=[fef] type=internal*/
psbool FirstEnterFlag; /* name=[FirstEnterFlag] type=internal*/
}*_lpS_samhd,_S_samhd;
void samhd(_lpS_samhd samhd_s);
#endif

