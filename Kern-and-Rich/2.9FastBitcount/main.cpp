/*Упражнение 2.9. Применительно к числам, в
представлении которых использован дополнительный код,
выражение х &= (х-1) уничтожает самую правую 1 в х. 
Объясните, почему. Используйте это наблюдение
при написании более быстрого варианта функции bitcount.*/

#include <cstdlib>
#include <iostream>

int bitcount (unsigned x);

int main(){
    
    unsigned int bit = 127;
    
    printf("once bits in number - %d\n", bitcount(bit) );
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

int bitcount (unsigned x){
    
    int i;

    for (i = 0; x != 0; i++)
        x &= (x-1);
    return i;
}
