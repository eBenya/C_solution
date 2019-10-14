/*���������� 4.13. �������� 
����������� ������ ������� 
reverse(s), �������������� 
�������� ������ � �� �� 
������ � �������� �������.*/

#include <cstdlib>
#include <iostream>

#include <string.h>

using namespace std;

void reverse(char s[]);

int main(){
    
    char test[] = "Test String";

    printf("String - %s\n", test); 
    reverse(test);      
    printf("Reverse string - %s\n", test);
         
    system("PAUSE");
    return EXIT_SUCCESS;
}

void reverse(char s[]){
     
     static int i = 0, j = -1, c;
     if (j == -1) j = strlen(s) - 1;
     
     c = s[i];
     s[i++] = s[j];
     s[j--] = c;
     
     if ( i < j )
        reverse (s);
}

/* reverse: �������������� ������ s (��������� � s)
void reverse(char s[])
{
    int c, i = strlen(s);
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
*/
