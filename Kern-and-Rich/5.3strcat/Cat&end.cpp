/*���������� 5.4.
�������� ������� strend(s, t), ������� ������ 1, ���� ������ 
t ����������� � ����� ������ s, � ���� � ��������� ������.*/

//#include <cstdlib>
#include <iostream>

using namespace std;
int strend(char *s, char *t);

int main(int argc, char *argv[])
{
    char a[] = "string";
    char b[] = "ing";
    printf("String a - %s\nString b - %s\n",a,b);
    char *d = &a[0];
    strcat(a,b);
    
    /*while (*d++ != '\0') putchar(*d);
    putchar('\n');*/ //�� ������ ���� tring ���� ������ 1-��  ������?!
    printf("Cat - %s\n", a);
    //test strend
    printf("strend return - %d\n", strend(a, b)); 
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
/* strcat: �������� t � ����� s; s ���������� ������ */
void strcat (char *s, char *t){
	while (*s++ != '\0');/* ������� ����� s*/
	while ((*s++ = *t++) != '\0'); /* �������� t*/
}
//It strend is work 
/*int strend(char *s, char *t){
	int flag = 0;
    while (*s++ != '\0'){
    	while(*s++ == *(t+flag)){
    		flag++;
    		if(*(t+flag) == '\0') return 1;
    	}
    	flag = 0;
    }
    return 0;
}*/

int strend(char *s, char *t){
	int flag = 0;
    do{
    	if(*s == *(t+flag)) flag++;
    	else flag = 0;
    } while (*++s != '\0');
    if (flag == 0) return 0;
    else return 1;
}

