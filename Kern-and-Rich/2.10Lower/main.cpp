/*���������� 2.10. �������� ������� lower, �������
��������� ������� ����� � �����, ���������
�������� ��������� (� �� ����������� if-else).*/

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
