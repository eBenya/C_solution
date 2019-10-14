#include <cstdlib>
#include <iostream>

using namespace std;

#define WORDLEN 100

int main(int argc, char *argv[])
{
    char c;
    int lenght[WORDLEN;
    int word=0, flag=0, maxLenght = 0;
    
    while ( (c=getchar()) != EOF ){
          if ( (c==' ') ||(c=='\n') ||(c=='\t')){
              word++;
              if (maxLenght<flag) maxLenght = flag;
              lenght[word] = flag;
              flag = 0;
              }
          else flag++;                          
    }
        
    printf("max lenght word = %d\n", maxLenght);
    for (int a = 1; a<=word; a++) printf("lenght %d word = %d\n", a, lenght[a]);

    //print vertical gistogram
    for (int a = 0; a <= maxLenght; a++ ){
        for (int b = 1; b <= word; b++){
            if (lenght[b] >= 1) {
                 putchar('_');
            }
            else putchar(' ');
            putchar(' ');
            lenght[b] = lenght[b] - 1;
        }
        putchar('\n');
    }
    
    getchar();
}
