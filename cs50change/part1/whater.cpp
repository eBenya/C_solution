/*Сколько нужно тебе воды что бы помыться n минут*/
#include <stdio.h>
#include <cs50.h>

int watetminutes(int minutes){
    const int BOTTLE = 12;
    return minutes*BOTTLE;
}

int main(){
    printf("write number minetes in time thet we be wosh\n");
    int minutes = get_int();
    printf( "Minutes: %d\n", minutes );
    printf( "Bottles: %d\n", watetminutes(minutes) );
}