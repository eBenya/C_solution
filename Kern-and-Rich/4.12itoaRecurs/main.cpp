/*���������� 4.12. ��������� ����, 
������� �� ������������ � �rintd, 
������������ ����������� ������
������� itoa; ����� ������, 
������������ ����� ����� � ������ 
���� � ������� ����������� ���������.*/

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



/* itoa: �������������� n � ������ s */
void itoa (int n, char s[]){
     
    static int i = 0;
    
    if (n < 0){ /* ��������� ���� */
       n = -n;
       s[i++] = '-';/* ������ n ������������� */       
    }
    
    if (n/10)
       itoa(n/10, s);
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}
