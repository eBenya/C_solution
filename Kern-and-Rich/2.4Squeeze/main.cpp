/*Упражнение 2.4. Напишите версию функции squeeze(s1, s2),
которая удаляет из s1 все символы,
встречающиеся в строке s2.*/

#include <cstdlib>
#include <iostream>

#define MAXLEN 100

void squeeze(char s1[MAXLEN], char s2[MAXLEN]);


int main(){
    
    int c=0;
    char s1[MAXLEN], s2[MAXLEN];
    
    while ( (s1[c++]=getchar()) != '\n' ) if (s2[c]=='\n') s2[c]='\0';
    
    c = 0;
    while ( (s2[c++]=getchar()) != '\n' ) if (s2[c]=='\n') s2[c]='\0';
    
    squeeze(s1,s2);
    printf("s1 = %s\n",s1);      
    
    system("pause");
}

void squeeze(char s1[MAXLEN], char s2[MAXLEN]){
     
     for (int i = 0; s1[i] != '\0'; i++){
         for (int a = 0; s2[a] != '\0'; a++)   
                if (s1[i] == s2[a]){
                   for (int b = i; s1[b] != '\0'; b++) s1[b]=s1[b+1];
                   i--;
                   }         
          }     
     
     }
