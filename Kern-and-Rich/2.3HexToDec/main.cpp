/*Упражнение 2.З. Напишите функцию htol(s), которая преобразует последовательность
шестнадцатеричных цифр, начинающуюся с 0х или 0Х, в соответствующее целое.
Шестнадцатеричными цифрами являются символы 0…9, а…f, А…F.*/

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>

#define TEXTSIZE 1000
#define MAXLEN 10000

const int HEX = 16;

void clear(char s[MAXLEN]);
int htol(char s[MAXLEN]);
int sizeArr(char s[]);


int main(){
    
    setlocale(LC_ALL,"rus");
    
    char c, hexL[MAXLEN];
    int dec;     
    
    while ( (c=getchar()) != EOF ){
          
          printf("write hex number:\n");    
          if (c='0') if ( (c=getchar())=='x' || c=='X' )
          for (int i = 0; i < MAXLEN; i++){
                if ( ((c=getchar())>='0'&&c<='9') || (c>='a'&&c<='f') || (c>='A'&&c<='F') || c=='x' || c=='X' ){
                     hexL[i] = c;
                     }
                  else break;   
               }

          dec = htol(hexL); 
          if (hexL[0]!='\0')printf("\n\thex in dec = %d\n",dec);
          clear(hexL);
                       
            }
    system("PAUSE");
}


void clear(char s[MAXLEN]){
     
     int i = 0;
     while (s[i]!='\0'){
           
           s[i]='\0';
           i++;
           
           }     
     }    
     

int htol(char s[]){
    
    int arr[MAXLEN];
    int size = 0;
    int resault = 0;
    
    while (s[size]!='\0'){
           
           if( s[size]>='0' && s[size]<='9' ) arr[size] = s[size]-48;
           if( s[size]>='A' && s[size]<='F' ) arr[size] = s[size]-55;
           if( s[size]>='a' && s[size]<='f' ) arr[size] = s[size]-87;
           size++;
            
           }
    size--;
    
    for(int i = 0; i<=size; i++){
            
            resault = resault + arr[i]*pow(16,size-i);
            
            }
    
    return resault;
    }
