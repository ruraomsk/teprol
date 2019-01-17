#ifndef SIGNALS_H
#define SIGNALS_H

#include "spatypes.h"

#ifdef SIMUL_MODE
char SwitchTaktFlag = 0;
extern "C" char __declspec(dllexport) __stdcall TaktSwitch();
char __stdcall TaktSwitch()
{ 
  return SwitchTaktFlag; 
}
#endif

#ifndef SIMUL_MODE
#define CheckSFloatSys(/* offset */ base) \
{\
 if (\
      ((unsigned char*)(SignalBuffer)+base)[0] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-1)) ||\
      ((unsigned char*)(SignalBuffer)+base)[1] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-2)) ||\
      ((unsigned char*)(SignalBuffer)+base)[2] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-3)) ||\
      ((unsigned char*)(SignalBuffer)+base)[3] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-4)) ||\
      ((unsigned char*)(SignalBuffer)+base)[4] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-5))\
         ) {\
 ((psfloat)((unsigned char*)(SignalBuffer)+base))->error = 1;\
 InvertionFailureCounter++;\
 }\
}
#define CheckSFloat(/* offset */ base)\
{\
 if (\
      ((unsigned char*)(SignalBuffer)+base)[0] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-1)) ||\
      ((unsigned char*)(SignalBuffer)+base)[1] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-2)) ||\
      ((unsigned char*)(SignalBuffer)+base)[2] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-3)) ||\
      ((unsigned char*)(SignalBuffer)+base)[3] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-4)) ||\
      ((unsigned char*)(SignalBuffer)+base)[4] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-5))\
         ) {\
 ((psfloat)((unsigned char*)(SignalBuffer)+base))->error = 1;\
 InvertionFailureCounter++;\
 }\
}

#define CheckSBlockSys(/* offset */ base) \
{\
 if (\
     ((unsigned char*)(SignalBuffer)+base)[0] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-1)) ||\
     ((unsigned char*)(SignalBuffer)+base)[1] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-2)) ||\
     ((unsigned char*)(SignalBuffer)+base)[2] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-3))\
         )\
 ((psblock)((unsigned char*)(SignalBuffer)+base))->error = 1;\
 for (counter=0;\
      counter<((psblock)((unsigned char*)(SignalBuffer)+base))->i;\
      counter++)\
   {\
    if (\
        ((unsigned char*)(SignalBuffer)+base+3)[counter] !=\
         (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-4-counter))\
            )\
      {\
       ((psblock)((unsigned char*)(SignalBuffer)+base))->error = 1;\
       InvertionFailureCounter++;\
       break;\
      }\
   }\
}
#define CheckSBlock(/* offset */ base) \
{\
 if (\
     ((unsigned char*)(SignalBuffer)+base)[0] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-1)) ||\
     ((unsigned char*)(SignalBuffer)+base)[1] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-2)) ||\
     ((unsigned char*)(SignalBuffer)+base)[2] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-3))\
         )\
 ((psblock)((unsigned char*)(SignalBuffer)+base))->error = 1;\
 for (counter=0;\
      counter<((psblock)((unsigned char*)(SignalBuffer)+base))->i;\
      counter++)\
   {\
    if (\
        ((unsigned char*)(SignalBuffer)+base+3)[counter] !=\
         (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-4-counter))\
            )\
      {\
       ((psblock)((unsigned char*)(SignalBuffer)+base))->error = 1;\
       InvertionFailureCounter++;\
       break;\
      }\
   }\
}

#define CheckSIntSys(/* offset */ base) \
{\
 if (\
     ((unsigned char*)(SignalBuffer)+base)[0] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-1)) ||\
     ((unsigned char*)(SignalBuffer)+base)[1] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-2)) ||\
     ((unsigned char*)(SignalBuffer)+base)[2] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-3))\
         ) {\
 ((psint)((unsigned char*)(SignalBuffer)+base))->error = 1;\
 InvertionFailureCounter++;\
 }\
}

#define CheckSInt(/* offset */ base) \
{\
 if (\
     ((unsigned char*)(SignalBuffer)+base)[0] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-1)) ||\
     ((unsigned char*)(SignalBuffer)+base)[1] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-2)) ||\
     ((unsigned char*)(SignalBuffer)+base)[2] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-3))\
         ) {\
 ((psint)((unsigned char*)(SignalBuffer)+base))->error = 1;\
 InvertionFailureCounter++;\
 }\
}

#define CheckSBoolSys(/* offset */ base) \
{\
 if (\
     ((unsigned char*)(SignalBuffer)+base)[0] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-1)) ||\
     ((unsigned char*)(SignalBuffer)+base)[1] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-2))\
         ) {\
 ((psbool)((unsigned char*)(SignalBuffer)+base))->error = 1;\
 InvertionFailureCounter++;\
 }\
}

#define CheckSBool(/* offset */ base) \
{\
 if (\
     ((unsigned char*)(SignalBuffer)+base)[0] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-1)) ||\
     ((unsigned char*)(SignalBuffer)+base)[1] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-2))\
         ) {\
 ((psbool)((unsigned char*)(SignalBuffer)+base))->error = 1;\
 InvertionFailureCounter++;\
 }\
}

#define CheckSCharSys(/* offset */ base) \
{\
 if (\
      ((unsigned char*)(SignalBuffer)+base)[0] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-1)) ||\
      ((unsigned char*)(SignalBuffer)+base)[1] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-2))\
         ) {\
 ((pschar)((unsigned char*)(SignalBuffer)+base))->error = 1;\
 InvertionFailureCounter++;\
 }\
}

#define CheckSChar(/* offset */ base) \
{\
 if (\
      ((unsigned char*)(SignalBuffer)+base)[0] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-1)) ||\
      ((unsigned char*)(SignalBuffer)+base)[1] !=\
       (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-2))\
         ) {\
 ((pschar)((unsigned char*)(SignalBuffer)+base))->error = 1;\
 InvertionFailureCounter++;\
 }\
}

#define CheckSFractSys(/* offset */ base) \
{\
 if (\
     ((unsigned char*)(SignalBuffer)+base)[0] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-1)) ||\
     ((unsigned char*)(SignalBuffer)+base)[1] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-2)) ||\
     ((unsigned char*)(SignalBuffer)+base)[2] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-3)) ||\
     ((unsigned char*)(SignalBuffer)+base)[3] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-4)) ||\
     ((unsigned char*)(SignalBuffer)+base)[4] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-5))\
         ) {\
 ((psint)((unsigned char*)(SignalBuffer)+base))->error = 1;\
 InvertionFailureCounter++;\
 }\
}

#define CheckSFract(/* offset */ base) \
{\
 if (\
     ((unsigned char*)(SignalBuffer)+base)[0] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-1)) ||\
     ((unsigned char*)(SignalBuffer)+base)[1] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-2)) ||\
     ((unsigned char*)(SignalBuffer)+base)[2] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-3)) ||\
     ((unsigned char*)(SignalBuffer)+base)[3] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-4)) ||\
     ((unsigned char*)(SignalBuffer)+base)[4] !=\
      (unsigned char)~(*((unsigned char*)(SignalBuffer)+PBLENGTH-base-5))\
         ) {\
 ((psint)((unsigned char*)(SignalBuffer)+base))->error = 1;\
 InvertionFailureCounter++;\
 }\
}

#define InvertSFloat(/* offset */ base) \
{\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-1) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[0]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-2) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[1]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-3) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[2]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-4) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[3]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-5) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[4]);\
}

#define InvertSBlock(/* offset */ base) \
{\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-1) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[0]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-2) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[1]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-3) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[2]);\
 for (counter=0;\
      counter<((psblock)((unsigned char*)(SignalBuffer)+base))->i;\
      counter++)\
    *((unsigned char*)(SignalBuffer)+PBLENGTH-base-4-counter) =\
    (unsigned char)~(((unsigned char*)(SignalBuffer)+base+3)[counter]);\
}

#define InvertSInt(/* offset */ base) \
{\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-1) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[0]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-2) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[1]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-3) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[2]);\
}

#define InvertSBool(/* offset */ base) \
{\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-1) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[0]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-2) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[1]);\
}

#define InvertSChar(/* offset */ base) \
{\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-1) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[0]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-2) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[1]);\
}

#define InvertSFract(/* offset */ base) \
{\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-1) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[0]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-2) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[1]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-3) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[2]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-4) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[3]);\
 *((unsigned char*)(SignalBuffer)+PBLENGTH-base-5) =\
   (unsigned char)~(((unsigned char*)(SignalBuffer)+base)[4]);\
}
#endif
#endif
