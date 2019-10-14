/*Упражнение 5.4.
Напишите функцию strend(s, t), которая выдает 1, если строка 
t расположена в конце строки s, и нуль в противном случае.*/

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
    putchar('\n');*/ //на выходе дает tring куда деется 1-ый  символ?!
    printf("Cat - %s\n", a);
    //test strend
    printf("strend return - %d\n", strend(a, b)); 
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
/* strcat: помещает t в конец s; s достаточно велика */
void strcat (char *s, char *t){
	while (*s++ != '\0');/* находим конец s*/
	while ((*s++ = *t++) != '\0'); /* копируем t*/
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

