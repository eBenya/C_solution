/*���������� 2.2. �������� ����,
 ������������� ������������ ���� f�r-�����,
 �� ��������� ����������� && � ||.
 ����������� ����: for (i = 0; i < lim-1 && (� = getchar()) != EOF && � != '\n'; ++i)
    s[i] = c;
 */

#include <stdio.h>
#include <cstdlib>

#define MAXLINE 1000


int main(){
    
    char s[MAXLINE];
    int i;
    
    for(i=0; i<MAXLINE-1; ++i){
        
        s[i]=getchar();
                
        if(s[i]=='\n') break;           
        if(s[i]==EOF) break;
        
        }
    
    s[i]='\0';
    printf("%s\n",s);
    
    system("pause");    
    
    }
