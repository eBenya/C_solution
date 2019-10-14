/*Упражнение 4.12. Примените идеи, 
которые мы использовали в рrintd, 
длянаписания рекурсивной версии
функции itoa; иначе говоря, 
преобразуйте целое число в строку 
цифр с помощью рекурсивной программы.*/

#include <cstdlib>
#include <iostream>

using namespace std;

void itoa (int n, char s[]);

int main(){
    char buffer[20];
    int i = 768;

    printf("Number: %d\n", i);
    itoa(i, buffer); 
    printf("Buffer : %s\n", buffer);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



/* itoa: преобразование n в строку s */
void itoa (int n, char s[]){
     
    static int i = 0;
    
    if (n < 0){ /* сохраняем знак */
       n = -n;
       s[i++] = '-';/* делаем n положительным */       
    }
    
    if (n/10)
       itoa(n/10, s);
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}
