#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <stdio.h>


int main(){
    int u_min_int, u_max_int, s_min_int, s_max_int;
    float u_min_f, u_max_f, s_min_f, s_max_f;
    //Библиотечные типы
    printf("\nINTEGER TYPE\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    
    printf("\nUnsigned type:\n\n");    
    printf("int range x:\t 0 < x < %u\n", UINT_MAX);
    printf("long range x:\t 0 < x < %lu\n", ULONG_MAX);
    printf("int char x:\t 0 < x < %d\n", UCHAR_MAX);
    printf("int short x:\t 0 < x < %d\n", USHRT_MAX);
    
    printf("\nSigned type:\n\n");
    printf("int range x:\t %d < x < %d\n", INT_MIN, INT_MAX);
    printf("long range x:\t %d < x < %d\n", LONG_MIN, LONG_MAX);
    printf("int char x:\t %d < x < %d\n", CHAR_MIN, CHAR_MAX);
    printf("int short x:\t %d < x < %d\n", SHRT_MIN, SHRT_MAX);
    
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
    
    printf("FLOAT TYPE\n");
    
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    
    printf("\nSigned type:\n\n");    
    printf("float range x:\t %e < x < %e\n", FLT_MIN, FLT_MAX);
    printf("double range x:\t %e < x < %e\n", DBL_MIN, DBL_MAX);
    
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    
    //Лабораторный рассчет
    
    system("pause");
    
    }
