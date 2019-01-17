// $Header: /cvs/LowLevel/Teprol3/Lib/INCL/spatypes.h,v 1.7 2011/01/13 03:30:26 vlad Exp $

#ifndef SPATYPES_H
#define SPATYPES_H

#pragma pack (push,1)

/************************************************************************/
/*      Описание базовых структур СПА-ПС                                */
/************************************************************************/

enum VarType{_REAL=1,_INT,_LOGIC,_PACKET,_BIT,_BYTE,_LONG,_STRING,_DATETIME,
_BLOCK, _REAL_C,_INT_C,_BYTE_C,_LONG_C,_STRING_C,_DATETIME_C};

typedef unsigned char uspaint8;
typedef signed char spaint8;

#if !defined(SIMUL_MODE) & !defined(VLR_EMULATOR) & !defined(WIN32)
  typedef int __int16;
#endif

#ifdef _Z80_            /* Definitions for Z80-compiler */

struct sfloat
{
 char f[4];
 uspaint8 error;
};
typedef struct sfloat ssfloat;
typedef struct sfloat * psfloat;

#else                   /* Definitions for normal compilers */
 struct sfloat
 {
  float f;
  uspaint8 error;
 };
 typedef struct sfloat ssfloat;
 typedef struct sfloat * psfloat;
  struct sbit
 {
  unsigned int bit0 : 1;
  unsigned int bit1 : 1;
  unsigned int bit2 : 1;
  unsigned int bit3 : 1;
  unsigned int bit4 : 1;
  unsigned int bit5 : 1;
  unsigned int bit6 : 1;
  unsigned int bit7 : 1;
 };
 typedef struct sbit ssbit;
 typedef struct sbit * psbit;

#endif

struct sblock
{
 __int16 i;
 uspaint8 error;
 uspaint8 ptr;
};

typedef struct sblock ssblock;
typedef struct sblock * psblock;

struct smessage
{
 __int16 i;
 __int16 n;
 uspaint8 t;
 uspaint8 ptr;
};

typedef struct smessage ssmessage;
typedef struct smessage * psmessage;

struct smessaget       
{                      
 __int16 i;            
 __int16 n;            
 uspaint8 t;           
 __int16 typedev;     
 uspaint8 modtype;     
 uspaint8 Sost_FP;     
 __int16 Notinv;       
 __int16 Sostdev;
};                                          
                                            
typedef struct smessaget ssmessaget;        
typedef struct smessaget * psmessaget;      

struct sint
{
 __int16 i;
 uspaint8 error;
};
typedef struct sint ssint;
typedef struct sint * psint;

struct slong
{
 long l;
 uspaint8 error;
};
typedef struct slong sslong;
typedef struct slong * pslong;


struct schar
{
#ifdef SIMUL_MODE
  union
  { 
     uspaint8 c;
     uspaint8 b;
  };
#else
  uspaint8 c;
#endif
  uspaint8 error;
};
typedef struct schar sschar;
typedef struct schar * pschar;

struct sbool
{
#ifdef SIMUL_MODE
  union
  {  uspaint8 c;
     uspaint8 b;
  };
#else
  uspaint8 b;
#endif
  uspaint8 error;
};


typedef struct sbool ssbool;
typedef struct sbool *psbool;

struct sDateTimeFC
{
  unsigned long Frac;
  unsigned long Sec;
};

typedef struct sDateTimeFC ssDateTimeFC;
typedef struct sDateTimeFC *psDateTimeFC;

struct sfract
{
 __int16 num;
 __int16 denom;
 uspaint8 error;
};
typedef struct sfract ssfract;
typedef struct sfract * psfract;

struct sDateTime
{
 long Date;
 long Time; 
};
typedef struct sDateTime ssDateTime;
typedef struct sDateTime * psDateTime;

#pragma pack (pop)

#endif                 /* Definitions for normal compilers */







