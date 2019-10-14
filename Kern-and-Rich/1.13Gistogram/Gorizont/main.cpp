#include <cstdlib>
#include <iostream>

using namespace std;

#define WORLDLEN 100

int main(int argc, char *argv[])
{
    char c;
    //int lenght[WORLDLEN];					//хз зачем я его ввел
    int word=0, flag=0, maxLenght = 0;
    
    while ( (c=getchar()) != EOF ){
        if ( (c==' ') || (c=='\n') || (c=='\t')){
              printf("lenght = %d\n",word);
              word=0;
              }
        else {                    
              word++;
              putchar('|');
              }             
        }
}
