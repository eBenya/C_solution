/*
    Task cs50 course.
    Name: Time to get of delivery
    purpose: output to console - how many coins to give
    Why save? string 48,49. useless solution, that i want to save. 
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>


void greedyAlg(int money){

    int cent_25 = 0;
    int cent_10 = 0;
    int cent_5 = 0;
    int cent_1 = 0;

    while(money > 0){

        if(money >= 25){
            money -= 25;
            cent_25++;
        }
        else if(money >= 10){
                money -= 10;
                cent_10++;
             }
             else if(money >= 5){
                    money -= 5;
                    cent_5++;
                  }
                  else if(money > 0){
                        money -= 1;
                        cent_1++;
                        }
    }
    if (cent_25 > 0) printf("25cent coin - %d\n", cent_25);
    if (cent_10 > 0) printf("10cent coin - %d\n", cent_10);
    if (cent_5 > 0) printf("5cent coin - %d\n", cent_5);
    if (cent_1 > 0) printf("1cent coin - %d\n", cent_1);
}

int main(){
    float money;
    do
    money = round( (get_float("how many money?\n")*100) );	//вычисление центов
    while ((money < 0) || ( fmod(money*100, 100) > 0) );	//и проверка на верность ввода!
    greedyAlg(money);
   // printf("end\n");
}
