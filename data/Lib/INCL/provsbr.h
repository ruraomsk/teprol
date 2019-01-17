/*Razdel=[Метрологическое обеспечение]*/
/*Name=[Модуль выполнения программы проверок]*/
#ifndef _provsbr_H_
#define _provsbr_H_
typedef struct {
psbool pusk; /* name=[pusk - разрешение выполнения программы] type=in*/
psbool kvit;  /* name=[kvit - флаг запуска программы с начала] type=in*/
psbool rzINI; /* name=[sbINI - результат проверки ИНИ] type=in*/
psbool rzVuIS; /* name=[sbVuIS - результат проверки сброса от ВУ ИС] type=in*/
psbool rz2UR; /* name=[sb2UR - результат проверки сброса от 2УР] type=in*/
psbool rzNupIS; /* name=[sbNupIS - результат проверки сброса от НУП ИС] type=in*/
psbool rzVuRB; /* name=[sbVuRB - результат проверки сброса от ВУ РБ] type=in*/
psbool zvINI; /* name=[sbINI - завершение проверки ИНИ] type=in*/
psbool zvVuIS; /* name=[sbVuIS - завершение проверки сброса от ВУ ИС] type=in*/
psbool zv2UR; /* name=[sb2UR - завершение проверки сброса от 2УР] type=in*/
psbool zvNupIS; /* name=[sbNupIS - завершение проверки сброса от НУП ИС] type=in*/
psbool zvVuRB; /* name=[sbVuRB - завершение проверки сброса от ВУ РБ] type=in*/
psint np; /* name=[np - размер массива значений параметров программы] type=tune*/
psfloat *Tpr; /* name=[Tpr - время начала проверки мс от старта программы] type=tune depend=[np]*/
pschar *type; /* name=[type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец] type=tune depend=[np]*/
psbool FinPr; /* name=[FinPr - конец программы] type=out*/
psint Min; /* name=[Min - до конца программы (минут)] type=out*/
psint Sek;  /* name=[Sek - до конца программы (секунд)] type=out*/
psbool ErrPr; /* name=[ErrPr - Приостановка программы по ошибке] type=out*/
psbool sbINI; /* name=[sbINI - запуск проверки ИНИ] type=out*/
psbool sbVuIS; /* name=[sbVuIS - запуск проверки сброса от ВУ ИС] type=out*/
psbool sb2UR; /* name=[sb2UR - запуск проверки сброса от 2УР] type=out*/
psbool sbNupIS; /* name=[sbNupIS - запуск проверки сброса от НУП ИС] type=out*/
psbool sbVuRB; /* name=[sbVuRB - запуск проверки сброса от ВУ РБ] type=out*/
psint  Step; /* name=[ - текущий шаг программы] type=internal*/
pschar *rz; /* name=[- результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка] type=internal depend=[np]*/
psfloat TimS; /* name=[Время от старта программы] type=internal*/
psbool FinPr0; /* name=[FinPr - конец программы] type=internal*/
psbool ErrPr0; /* name=[ErrPr - Приостановка программы по ошибке] type=internal*/
psbool sbINI0; /* name=[sbINI - запуск проверки ИНИ] type=internal*/
psbool sbVuIS0; /* name=[sbVuIS - запуск проверки сброса от ВУ ИС] type=internal*/
psbool sb2UR0; /* name=[sb2UR - запуск проверки сброса от 2УР] type=internal*/
psbool sbNupIS0; /* name=[sbNupIS - запуск проверки сброса от НУП ИС] type=internal*/
psbool sbVuRB0; /* name=[sbVuRB - запуск проверки сброса от ВУ РБ] type=internal*/
psbool MyFirstEnterFlag; /* name=[ ] type=internal*/
}*_lpS_provsbr,_S_provsbr;
void provsbr(_lpS_provsbr provsbr_s);
#endif