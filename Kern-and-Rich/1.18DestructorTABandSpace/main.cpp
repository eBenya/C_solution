//Не стал заморачиваться с отдельно пробеллом и табом, скомпоновал их вместе

#include <cstdlib>
#include <iostream>

#define MAXLINE 1000

   main(){
         char c;
         int flag=0;                                //0 - flagOFF; 1-one character; >1 - flagON
         while( (c=getchar())!=EOF ){
               if ( (c=='\t') || (c==' ') ){
                    flag++;
                    if ( flag < 2 ) putchar(c);
                    }
                 else {
                      putchar(c);
                      flag=0;
                      }   
               }
               
         getchar();       
       }
