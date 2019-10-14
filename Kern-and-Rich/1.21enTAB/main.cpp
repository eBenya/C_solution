#include <cstdlib>
#include <iostream>

#define itTAB 3 //Number TAB


void deTAB(int a);
         
 main(){
        char c;
        int spaceCount = 0;
        while( (c=getchar()) != EOF ){
               if ( (c != ' ') & ( spaceCount == 0 ) ) putchar(c);
               if ( (c != ' ') & ( spaceCount != 0 ) ){
                    deTAB(spaceCount);
                    putchar(c);
                    spaceCount = 0;
                    }
               if ( (c == ' ') & ( spaceCount < itTAB ) ) spaceCount++;
               if ( (c == ' ') & ( spaceCount == itTAB ) ){
                    deTAB(spaceCount);
                    spaceCount = 0;
                    }
                 
               }          
   }
       
void deTAB(int a){
         for(int i=0; i<a; i++)putchar(' ');
         }
