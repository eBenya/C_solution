    
/*Сколько нужно тебе воды что бы помыться n минут*/
#include <stdio.h>
#include <cs50.h>

int watetminutes(int minutes){
    const int BOTTLE = 12;
    return minutes*BOTTLE;
}

int main(){
    char str[100];
    printf("write number minetes in time thet we be wosh\n");
    int minutes = get_int("%s", str);
    printf( "Minutes: %d\n", minutes );
    printf( "Bottles: %d\n", watetminutes(minutes) );
}







/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent int; if text does not represent an int in [-2^31, 2^31 - 1)
 * or would cause underflow or overflow, user is prompted to retry. If line
 * can't be read, returns INT_MAX.
 */
// int get_int(const string format, ...) __attribute__((format(printf, 1, 2)));