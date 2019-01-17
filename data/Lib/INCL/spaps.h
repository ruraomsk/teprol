// $Header: /cvs/Lowlevel/Teprol3/Lib/INCL/spaps.h,v 1.16 2011/08/29 07:04:07 npn Exp $
#ifndef SPAPS_H
#define SPAPS_H
#ifdef LINUXMODE
  #include "typedef.h"
  #define __int16 short
#else
  #include <spatypes.h>
#endif
#ifndef max
 #define max(__a,__b)    (((__a) > (__b)) ? (__a) : (__b))
#endif
#ifndef min
 #define min(__a,__b)    (((__a) < (__b)) ? (__a) : (__b))
#endif


/************************************************************************/
/*      Описание функций для работы с числами с плавающей точкой        */
/************************************************************************/

#define     fpabs(x)   ( ((unsigned char*)(x))[3] &= 0x7F )
#define     fpneg(x)   ( ((unsigned char*)(x))[3] ^= 0x80 )
#define     fpconst(y,a1,a2,a3,a4)\
  {\
        ((unsigned char*)y)[0] = a1;\
        ((unsigned char*)y)[1] = a2;\
        ((unsigned char*)y)[2] = a3;\
        ((unsigned char*)y)[3] = a4;\
  }
#define     ANDO(a,b) ( a && b )
#define     ORO(a,b) ( a || b )
#define     NOTO(a) ( !a )

#ifndef LINUXMODE
   #ifdef USE_COPROCESSOR
    #include <stdlib.h>
    #include <math.h>
    
    #ifdef SIMUL_MODE
       extern int _8087;
    #else
      #include <dos.h>
    #endif
   #endif
#endif

__int16  fpcomp(float *, float *);
char* TwoName(char* par1,char* par2);

void  fplet(float*, float*);
void  fpadd(float *,float *,float *);
void  fpsub(float *,float *,float *);
void  fpdiv(float *,float *,float *);
void  fpmult(float *, float *, float *);
void  ftoi(float *, __int16 *);
void  itof(__int16 , float *);
void  utof(long int , float *);
void  ftou(float *,long*);



#ifdef NEW_TEPROL

#define zmin(a){if(((a)->y)->i < ((a)->x)->i) ((a)->z)->i = ((a)->y)->i; else ((a)->z)->i = ((a)->x)->i;\
((a)->z)->error = ((a)->x)->error | ((a)->y)->error;}

#define binbyte(a)  {((a)->y)->c = ((a)->x)->b; ((a)->y)->error = ((a)->x)->error;}
#define binint(a)   {((a)->y)->i = ((a)->x)->b; ((a)->y)->error = ((a)->x)->error;}
#define binlong(a)  {((a)->y)->l = ((a)->x)->b; ((a)->y)->error = ((a)->x)->error;}

#define bytebin(a)  {((a)->y)->b = ((a)->x)->c; ((a)->y)->error = ((a)->x)->error;}
#define byteint(a)  {((a)->y)->i = ((a)->x)->c; ((a)->y)->error = ((a)->x)->error;}
#define bytelong(a) {((a)->y)->l = ((a)->x)->c; ((a)->y)->error = ((a)->x)->error;}

#define intbin(a)   {((a)->y)->b = ( ((a)->x)->i?1:0 ); ((a)->y)->error = ((a)->x)->error;}
#define intbyte(a)  {((a)->y)->c = ((a)->x)->i; ((a)->y)->error = ((a)->x)->error;}
#define intlong(a)  {((a)->y)->l = ((a)->x)->i; ((a)->y)->error = ((a)->x)->error;}
#define intdec(a)   {itof(((a)->x)->i,&(((a)->y)->f)); ((a)->y)->error = ((a)->x)->error;}

#define longbin(a)  {((a)->y)->b = ( ((a)->x)->l?1:0 ); ((a)->y)->error = ((a)->x)->error;}
#define longbyte(a) {((a)->y)->c = ((a)->x)->l; ((a)->y)->error = ((a)->x)->error;}
#define longint(a)  {((a)->y)->i = ((a)->x)->l; ((a)->y)->error = ((a)->x)->error;}
#define longdec(a)  {utof(((a)->x)->l,&(((a)->y)->f)); ((a)->y)->error = ((a)->x)->error;}

#define decint(a)   {ftoi(&(((a)->x)->f),&(((a)->y)->i)); ((a)->y)->error = ((a)->x)->error;}
#define declong(a)  {ftou(&(((a)->x)->f),&(((a)->y)->l)); ((a)->y)->error = ((a)->x)->error;}
#define charint(a){((a)->y)->i = ((a)->x)->c; ((a)->y)->error = ((a)->x)->error;}
#else

#define zmin(x,y,z){if((y)->i < (x)->i) (z)->i = (y)->i; else (z)->i = (x)->i;\
(z)->error = (x)->error | (y)->error;}
#define intdec(x,y){itof((x)->i,&((y)->f)); (y)->error = (x)->error;}
#define decint(x,y){ftoi(&((x)->f),&((y)->i)); (y)->error = (x)->error;}
#define zmax(x,y,z){if((y)->i > (x)->i) (z)->i = (y)->i; else (z)->i = (x)->i;\
(z)->error = (x)->error | (y)->error;}
#ifndef LINUXMODE
#define charint(x,y){(y)->i = (x)->c; (y)->error = (x)->error;}
#endif
#define intbyte(x,y){(y)->c = (x)->i; (y)->error = (x)->error;}
#define binbyte(x,y){(y)->c = (x)->b; (y)->error = (x)->error;}
#define bytebin(x,y){(y)->b = (x)->c; (y)->error = (x)->error;}
#define binint(x,y){(y)->i = (x)->b; (y)->error = (x)->error;}
#define intbin(x,y){(y)->b = (x)->i; (y)->error = (x)->error;}
#endif

#define workend(/*psint*/x, /*psint*/m){if(!(x)->error && (x)->i >= (m)->i) return;}

void sqroot(float *x, float *y);
void sldexp(char* x, __int16 n, char* y);
void sfrexp(float* x, __int16* m, float* y);

extern float takt;
extern unsigned long sys_time;
extern unsigned short f_time;
extern short itakt, dtakt;

#endif



