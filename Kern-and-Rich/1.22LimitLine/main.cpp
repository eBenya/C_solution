#include <cstdlib>
#include <iostream>

#define limitInLine 20

 main()
{
    char c, word[20];
    int lenline=0, lenword=0;
    
    while ( (c=getchar()) != EOF){          
          word[lenword]=c;
          if ( (lenword+lenline)>limitInLine ){
               putchar('\n');
               lenline=0;               
               }
          if ( (c==' ')||(c=='\t') ){
               if (c==' ') lenline=lenline+lenword+1;
                  else lenline=lenline+lenword+8;
               //printf(" word-%d len-%d",lenword,lenline);
               for(int i=0; i<lenword; i++) putchar(word[i]);
               putchar(c);              
               lenword=-1;
               }
          if (c=='\n'){
               lenline = lenword-1;
               for(int i=0; i<lenword; i++) putchar(word[i]);
               putchar(c);               
               lenword=-1;       
               }
          lenword++;
         // putchar(c);
         // putchar('\n');
          }
    system("PAUSE");
    return EXIT_SUCCESS;
}
