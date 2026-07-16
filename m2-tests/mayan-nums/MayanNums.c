#include "m2lib.h"
#line 1 "MayanNums.mod"
#line 1 "mayan-nums"
struct par_GetNumberFromUser_MayanNums {
    struct {
        unsigned char* adr;
        unsigned high;
    } _InputNumber;
};
struct {
    unsigned _D[024];
    unsigned char _InputNumber[024];
    unsigned _I;
    unsigned _J;
    unsigned _L;
    unsigned _M;
    unsigned _S;
    int _N;
    unsigned char _LS[06][05];
} var_MayanNums;
extern char *m2_testptr();
union {
    short abs_short_int;
    int abs_int;
    long long abs_long_int;
    float abs_short_real;
    float abs_real;
    double abs_long_real;
} abs_union;
struct par_ReadString_InOut {
    struct {
        unsigned char* adr;
        unsigned high;
    } _s;
};
struct par_WriteString_InOut {
    struct {
        unsigned char* adr;
        unsigned high;
    } _s;
};
struct par_WriteCard_InOut {
    unsigned _x;
    unsigned _n;
};
extern void _ReadString_InOut();
extern void _WriteLn_InOut();
extern void _WriteString_InOut();
extern void _WriteCard_InOut();
extern struct {
    unsigned short _Done;
    unsigned char _termCh;
} var_InOut;
struct par_Length_String {
    struct {
        unsigned char* adr;
        unsigned high;
    } _str;
};
extern unsigned _Length_String();
struct par_GetNthArgStr_ShellVars {
    unsigned _n;
    struct {
        unsigned char* adr;
        unsigned high;
    } _str;
};
extern unsigned _GetNArg_ShellVars();
extern void _GetNthArgStr_ShellVars();
static void _GetNumberFromUser_MayanNums();
static char string1[]="Number: ";
static void _GetNumberFromUser_MayanNums(par)register struct par_GetNumberFromUser_MayanNums *par;
{   struct {
        unsigned _ArgCount;
    } var;
    struct par_WriteCard_InOut par_WriteCard_InOut;
    struct par_GetNthArgStr_ShellVars par_GetNthArgStr_ShellVars;
    struct par_WriteString_InOut par_WriteString_InOut;
    struct par_ReadString_InOut par_ReadString_InOut;

#line 25 "MayanNums.mod"

#line 26 "MayanNums.mod"
    (var._ArgCount)=((_GetNArg_ShellVars()));
#line 27 "MayanNums.mod"
    (par_WriteCard_InOut._x=(var._ArgCount),par_WriteCard_InOut._n=(2),_WriteCard_InOut(&par_WriteCard_InOut));
#line 28 "MayanNums.mod"
    (_WriteLn_InOut());
#line 29 "MayanNums.mod"
    if(((var._ArgCount)>(1))) {
#line 30 "MayanNums.mod"
        (par_GetNthArgStr_ShellVars._n=(1),par_GetNthArgStr_ShellVars._str.adr=(par->_InputNumber).adr,par_GetNthArgStr_ShellVars._str.high=(par->_InputNumber).high,_GetNthArgStr_ShellVars(&par_GetNthArgStr_ShellVars));
#line 31 "MayanNums.mod"
        (par_WriteString_InOut._s.adr=(par->_InputNumber).adr,par_WriteString_InOut._s.high=(par->_InputNumber).high,_WriteString_InOut(&par_WriteString_InOut));
#line 32 "MayanNums.mod"
        (_WriteLn_InOut());
    }
    else {
#line 34 "MayanNums.mod"
        (par_WriteString_InOut._s.adr=((unsigned char *)string1),par_WriteString_InOut._s.high=010,_WriteString_InOut(&par_WriteString_InOut));
#line 35 "MayanNums.mod"
        (par_ReadString_InOut._s.adr=(par->_InputNumber).adr,par_ReadString_InOut._s.high=(par->_InputNumber).high,_ReadString_InOut(&par_ReadString_InOut));
    }
label1:
    ;
}
static char string2[]="    ";
static char string3[]=" .  ";
static char string4[]=" .. ";
static char string5[]="... ";
static char string6[]="....";
static char string7[]="----";
static char string8[]="+----";
static char string9[]="+";
static char stringa[]="| @  ";
static char stringb[]="|";
int m2argc;
char **m2argv,**m2envp;
main(argc,argv,envp)int argc;
char **argv,**envp;
{
    struct par_GetNumberFromUser_MayanNums par_GetNumberFromUser_MayanNums;
    struct par_Length_String par_Length_String;
    struct par_WriteString_InOut par_WriteString_InOut;
    m2argc=argc;
    m2argv=argv;
    m2envp=envp;
    _InOut();
    _String();
    _ShellVars();
#line 39 "MayanNums.mod"

#line 40 "MayanNums.mod"
    m2_assarr(((var_MayanNums._LS)[(0)]),((unsigned char *)string2),05);
#line 41 "MayanNums.mod"
    m2_assarr(((var_MayanNums._LS)[(1)]),((unsigned char *)string3),05);
#line 42 "MayanNums.mod"
    m2_assarr(((var_MayanNums._LS)[(2)]),((unsigned char *)string4),05);
#line 43 "MayanNums.mod"
    m2_assarr(((var_MayanNums._LS)[(3)]),((unsigned char *)string5),05);
#line 44 "MayanNums.mod"
    m2_assarr(((var_MayanNums._LS)[(4)]),((unsigned char *)string6),05);
#line 45 "MayanNums.mod"
    m2_assarr(((var_MayanNums._LS)[(5)]),((unsigned char *)string7),05);
#line 47 "MayanNums.mod"
    (par_GetNumberFromUser_MayanNums._InputNumber.adr=(var_MayanNums._InputNumber),par_GetNumberFromUser_MayanNums._InputNumber.high=023,_GetNumberFromUser_MayanNums(&par_GetNumberFromUser_MayanNums));
#line 48 "MayanNums.mod"
    (var_MayanNums._M)=((par_Length_String._str.adr=(var_MayanNums._InputNumber),par_Length_String._str.high=023,_Length_String(&par_Length_String)));
#line 50 "MayanNums.mod"
    if(((var_MayanNums._M)>(20))) {
        (var_MayanNums._M)=(20);
    }
#line 51 "MayanNums.mod"
    for((var_MayanNums._I)=(1); (var_MayanNums._I)<=(var_MayanNums._M); (var_MayanNums._I)++) {
#line 52 "MayanNums.mod"
        ((var_MayanNums._D)[(var_MayanNums._I)-01])=(((int)((var_MayanNums._InputNumber)[(var_MayanNums._I)-01]))-(48));
    }
#line 54 "MayanNums.mod"
    for((var_MayanNums._J)=((var_MayanNums._M)-(1)); (var_MayanNums._J)>=(1); (var_MayanNums._J)--) {
#line 55 "MayanNums.mod"
        for((var_MayanNums._I)=(1); (var_MayanNums._I)<=(var_MayanNums._J); (var_MayanNums._I)++) {
#line 56 "MayanNums.mod"
            ((var_MayanNums._D)[((var_MayanNums._I)+(1))-01])=(((var_MayanNums._D)[((var_MayanNums._I)+(1))-01])+((10)*(((var_MayanNums._D)[(var_MayanNums._I)-01])%(2))));
#line 57 "MayanNums.mod"
            ((var_MayanNums._D)[(var_MayanNums._I)-01])=(((var_MayanNums._D)[(var_MayanNums._I)-01])/(2));
        }
    }
#line 60 "MayanNums.mod"
    (var_MayanNums._S)=(1);
#line 61 "MayanNums.mod"
    while(((((var_MayanNums._D)[(var_MayanNums._S)-01])==(0))&&((var_MayanNums._S)<(var_MayanNums._M)))) {
#line 62 "MayanNums.mod"
        (var_MayanNums._S)=((var_MayanNums._S)+(1));
    }
#line 64 "MayanNums.mod"
    for((var_MayanNums._I)=(var_MayanNums._S); (var_MayanNums._I)<=(var_MayanNums._M); (var_MayanNums._I)++) {
#line 65 "MayanNums.mod"
        (par_WriteString_InOut._s.adr=((unsigned char *)string8),par_WriteString_InOut._s.high=05,_WriteString_InOut(&par_WriteString_InOut));
    }
#line 67 "MayanNums.mod"
    (par_WriteString_InOut._s.adr=((unsigned char *)string9),par_WriteString_InOut._s.high=01,_WriteString_InOut(&par_WriteString_InOut));
#line 68 "MayanNums.mod"
    (_WriteLn_InOut());
#line 69 "MayanNums.mod"
    for((var_MayanNums._L)=(0); (var_MayanNums._L)<=(3); (var_MayanNums._L)++) {
#line 70 "MayanNums.mod"
        for((var_MayanNums._I)=(var_MayanNums._S); (var_MayanNums._I)<=(var_MayanNums._M); (var_MayanNums._I)++) {
#line 71 "MayanNums.mod"
            if(((((var_MayanNums._D)[(var_MayanNums._I)-01])==(0))&&((var_MayanNums._L)==(3)))) {
#line 72 "MayanNums.mod"
                (par_WriteString_InOut._s.adr=((unsigned char *)stringa),par_WriteString_InOut._s.high=05,_WriteString_InOut(&par_WriteString_InOut));
            }
            else {
#line 74 "MayanNums.mod"
                (var_MayanNums._N)=(((var_MayanNums._D)[(var_MayanNums._I)-01])-((5)*((3)-(var_MayanNums._L))));
#line 75 "MayanNums.mod"
                if(((var_MayanNums._N)>(5))) {
#line 76 "MayanNums.mod"
                    (var_MayanNums._N)=(5);
                }
                else if(((var_MayanNums._N)<(0))) {
#line 78 "MayanNums.mod"
                    (var_MayanNums._N)=(0);
                }
#line 80 "MayanNums.mod"
                (par_WriteString_InOut._s.adr=((unsigned char *)stringb),par_WriteString_InOut._s.high=01,_WriteString_InOut(&par_WriteString_InOut));
#line 81 "MayanNums.mod"
                (par_WriteString_InOut._s.adr=((var_MayanNums._LS)[(var_MayanNums._N)]),par_WriteString_InOut._s.high=04,_WriteString_InOut(&par_WriteString_InOut));
            }
        }
#line 84 "MayanNums.mod"
        (par_WriteString_InOut._s.adr=((unsigned char *)stringb),par_WriteString_InOut._s.high=01,_WriteString_InOut(&par_WriteString_InOut));
#line 85 "MayanNums.mod"
        (_WriteLn_InOut());
    }
#line 87 "MayanNums.mod"
    for((var_MayanNums._I)=(var_MayanNums._S); (var_MayanNums._I)<=(var_MayanNums._M); (var_MayanNums._I)++) {
#line 88 "MayanNums.mod"
        (par_WriteString_InOut._s.adr=((unsigned char *)string8),par_WriteString_InOut._s.high=05,_WriteString_InOut(&par_WriteString_InOut));
    }
#line 90 "MayanNums.mod"
    (par_WriteString_InOut._s.adr=((unsigned char *)string9),par_WriteString_InOut._s.high=01,_WriteString_InOut(&par_WriteString_InOut));
#line 91 "MayanNums.mod"
    (_WriteLn_InOut());
label2:
    exit(0);
}
