/*���������� 2.5. �������� ������� any(s1, s2), 
������� ���������� ���� �� ������� � s1, ��� �����
������ ������, ��������� � ����� �� �������� � s2, 
���� -1 (���� �� ���� ������ �� s1 �� ��������� �
��������� �� s2). (����������� ������������ ������� strpbrk ������ �� �� �����, 
�� ������ �� ����� ������� �������, � ��������� �� ������.)*/

#include <cstdlib>
#include <iostream>

#define MAXLEN 100

int any(char s1[MAXLEN], char s2[MAXLEN]);

int main(){
    
    int c=0;
    char s1[MAXLEN], s2[MAXLEN];
    
    while ( (s1[c++]=getchar()) != '\n' ) if (s2[c]=='\n') s2[c]='\0';
    
    c = 0;
    while ( (s2[c++]=getchar()) != '\n' ) if (s2[c]=='\n') s2[c]='\n';
    
    c = any(s1,s2);
    if (c!=-1) printf("\"ANYsimbol\" meet on %d positions\n", c+1);
       else printf("\"ANYsimbol\" dont meet in line\n");
    
    system("PAUSE");
    return EXIT_SUCCESS;
}


int any(char s1[MAXLEN], char s2[MAXLEN]){
     
     for (int i = 0; s1[i] != '\0'; i++)   //Blyadski return at condition s[i]=='\0' is dont working. Why?!!!!!!!
         for (int a = 0; s2[a] != '\n'; a++)
             if (s1[i] == s2[a]) return i;
     return -1;
     }
