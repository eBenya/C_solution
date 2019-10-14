/*Упражнение 2.2. Напишите цикл,
 эквивалентный приведенному выше fоr-циклу,
 не пользуясь операторами && и ||.
 Приведенный цикл: for (i = 0; i < lim-1 && (с = getchar()) != EOF && с != '\n'; ++i)
    s[i] = c;
 */

#include <stdio.h>
#include <cstdlib>

#define MAXLINE 1000


int main(){
    
    char s[MAXLINE];
    int i;
    
    for(i=0; i<MAXLINE-1; ++i){
        
        s[i]=getchar();
                
        if(s[i]=='\n') break;           
        if(s[i]==EOF) break;
        
        }
    
    s[i]='\0';
    printf("%s\n",s);
    
    system("pause");    
    
    }
