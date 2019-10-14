#include <stdio.h>
#define MAXLINE 1000 /* максимальный размер вводимой строки */

void line80(char s[], int len);

/* печать самой длинной строки */
   main(){
         char c, line[MAXLINE], maxline[MAXLINE];
         int lenght=0, maxLenght=0;
         while( (c=getchar())!=EOF ){
               if ( c == '\n' || c == EOF ){
                    line80(line, lenght);   
                  if ( maxLenght < lenght ){
                       maxLenght = lenght;
                       for (int i=0; i<maxLenght; i++) maxline[i] = line[i];
                       }
                  lenght = 0;
                  }
               line[lenght] = c;
               lenght++;
               }
         printf ("Max Line: ");
         for(int i=0; i<maxLenght; i++) putchar(maxline[i]);
         printf("\nMax lenght line = %d.\nPres enter to exit.\n",maxLenght);
         getchar();       
       }

   void line80(char s[], int len){
        if (len > 80){
                printf("\nTheis lineis over 80 simbol: ");
                for(int a=0; a<len; a++) putchar(s[a]);
                putchar('\n');
                }                
        }
