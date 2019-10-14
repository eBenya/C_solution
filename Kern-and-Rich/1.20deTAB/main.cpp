#include <cstdlib>
#include <iostream>

#define itTAB 5 //Number TAB


void deTAB(int a);
         
 main(){
        char c;
        int count = itTAB;
        while( (c=getchar()) != EOF ){
                if ( (c != '\t') & (c != '\n') ) {
                     putchar(c);
                     count--;
                     if ( count == 0 ) count=itTAB;
                     }  
                   else {
                        if (c == '\t'){
                            deTAB(count);
                            count=itTAB;
                            }
                        if (c == '\n'){
                              count=itTAB;
                              putchar('\n');
                              }

                        } 
                }          
   }
       
void deTAB(int a){
         for(int i=0; i<a; i++)putchar(' ');
         }
