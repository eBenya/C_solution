#include <cstdlib>
#include <iostream>

#define MAXLINE 1000

   main(){
         char c, line[MAXLINE], revers[MAXLINE];
         int lenght = 0;
         while( (c=getchar()) != EOF ){
                if ( c == '\n' ){
                   printf("\nRevers line is - ");
                   for (int i=1; i<=lenght; i++){
                       revers[i] = line[lenght-i];
                       putchar(revers[i]);
                       }
                   lenght = 0;
                   putchar('\n');
                   }
                line[lenght] = c;
                lenght++;
                }            
       }
