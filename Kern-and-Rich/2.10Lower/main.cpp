/*Упражнение 2.10. Напишите функцию lower, которая
переводит большие буквы в малые, используя
условное выражение (а не конструкцию if-else).*/

#include <cstdlib>
#include <iostream>


void lower(char c);

int main(){
    
    char simb;
    
    while ( ( simb = getchar()) != EOF ){
          
          lower(simb);
          
          }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void lower(char c){
     
     printf("%c",((c >= 65) & (c <= 90)) ? (c + 32) : c);
     
     }
