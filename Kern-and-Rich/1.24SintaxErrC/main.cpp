/*Напишите программу, проверяющую Си-программы на элементарные синтаксические
ошибки вроде несбалансированности скобок всех видов.
*/

#include <cstdlib>
#include <iostream>

#define LimitText 10000

int getText(char s[]);
void balans(char s[], int i);

int main(int argc, char *argv[])
{
    char line[LimitText];    
    int size, err;
    size = getText(line);
    balans(line, size);
    
    //printf("%s",line);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

/////////////Functions//////////////////////////////
int getText(char s[]){
     char c;
     int i=0;
     while ( ((c=getchar())!=EOF)&&(i<LimitText) ){
           s[i]=c;
           i++;
           }
     return i;
     }
///////Баланс скобок и ковычек типа ( и {, ' и " //////////////     
void balans(char s[], int i){                
              int inFig=0, outFig=0, inBrace=0, outBrace=0, doublQuotes=0, secQuotes=0;
              
              for(int a=0; a<=i; a++){
                      switch (s[a]){
                             case('{'):inFig++;
                                 break;
                             case('}'):outFig++;
                                 break;
                             case('('):inBrace++;
                                 break;
                             case(')'):outBrace++;
                                 break;
                             case('\"'):secQuotes++;
                                 break;
                             case('\''):doublQuotes++;
                                 break;
                                 }  
                      }
              if (inFig==outFig);
                 else if(inFig>outFig) printf("Not enough closed simbol \"}\"\n");
                         else printf("Not enough open simbol \"{\"\n"); 
              if (inBrace==outBrace);
                 else if(inBrace>outBrace) printf("Not enough closed simbol \")\"\n");
                         else printf("Not enough open simbol \"(\"\n");
              if ( (secQuotes%2)!=0 ) printf("Not enough simbol '\n");
              if ( (doublQuotes%2)!=0 ) printf("Not enough simbol \"\n");
              }

