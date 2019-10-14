#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    char c;
    while ( (c=getchar())!=EOF ){
          
          if ( c == ' ' ) putchar('\n');
             else putchar(c);
          }
    return EXIT_SUCCESS;
}
