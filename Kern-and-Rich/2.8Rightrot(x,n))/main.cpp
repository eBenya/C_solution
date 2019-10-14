/*Упражнение 2.8. Напишите функцию rightrot(х, n),
 которая циклически сдвигает x вправо на n разрядов.*/

#include <cstdlib>
#include <iostream>

#define BITNESS 15  // digit capacity is (number of bits - 1)

unsigned int rightrot(unsigned int x, int n);

int main(int argc, char *argv[]){
    
    unsigned int bin = 15;
    int count = 4;
    
    
    printf("%d\n",rightrot(bin, count) );
    system("PAUSE");
    return EXIT_SUCCESS;
}

unsigned int rightrot(unsigned int x, int n){
         
    unsigned int save;
         
        for(int i = 0; i<n; i++){
                             
            save = (1 & x) << BITNESS; //Получили х000 0000
            x >>= 1;
            x|=save;                   
        }
                       
    return x;
                  
}
