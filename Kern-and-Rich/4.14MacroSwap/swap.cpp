#include <cstdlib>
#include <iostream>

#define  c1234swap(t, x, y) {\
         t = x;\
         x = y;\
         y = t;\         
         }

int main(){
    
    int a = 12, b = 77, c;
    printf("a - %d\nb - %d\n\n", a, b);
    
    c1234swap(c, a, b);
	printf("a - %d\nb - %d\n\n", a, b);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
