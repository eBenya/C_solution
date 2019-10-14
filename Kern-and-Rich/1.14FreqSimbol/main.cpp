#include <cstdlib>
#include <iostream>


main () {
     
     int NumbDiffChar = 127, s = 0;
     char c, n, nameSimbol[255];
     int simbol_numb[255];
     for (int a = 0; a < NumbDiffChar; a++){         
         nameSimbol[a]=a;
         simbol_numb[a]=0;    
         }
     for (int a = 0; a < NumbDiffChar; a++){         
         printf("%c",nameSimbol[a]);     
         }
     putchar('\n');
     while ( (c = getchar()) != EOF ){
           for (int a = 0; a < NumbDiffChar; a++){
               if ( c == nameSimbol[a] ) simbol_numb[a]++;
               }
           }
     for (int a = 0; a < NumbDiffChar; a++){
         if (simbol_numb[a]!=0){
            if (nameSimbol[a]=='\n') printf("\nSimbol  \\n occours %3d times;", simbol_numb[a]);
               else if (nameSimbol[a]=='\t') printf("\nSimbol  \\t occours %3d times;", simbol_numb[a]);
                       else printf("\nSimbol  %2c occours %3d times;", nameSimbol[a], simbol_numb[a]);
            }         
         }
     
    printf("\n\nPress to enter for exit.");     
    getchar();
    return EXIT_SUCCESS;
}
