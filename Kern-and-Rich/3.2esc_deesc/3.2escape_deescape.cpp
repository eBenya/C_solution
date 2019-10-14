/* Упражнение 3.2. Напишите функцию 
escape(s, t), которая при копировании 
текста из t в s преобразует 
такие символы, как новая строка и
табуляция в "видимые последовательности 
символов" (вроде \n и \t).
Используйте инструкцию switch. 
Напишите функцию, выполняющую обратное 
преобразование эскейп-последовательностей 
в настоящие символы.*/

#include <iostream>
#include <stdio.h>

#define MAXLEN 100

void escape(char s[MAXLEN], t[MAXLEN]);
void deescape(char s[MAXLEN], t[MAXLEN]);

 //Compiler version g++ 6.3.0

 int main(){
 	
 	char c, origin[MAXLEN], newlen[MAXLEN];
 	
 	for (int i = 0; origin[i] != EOF; origin[i] = getchar() ) i++;
 	
 	escape(newlen, origin);
 	//deescape(newlen, origin);
 	
 	system("pause");
 }

void escape(char s[MAXLEN], t[MAXLEN]){
	
	int i = 0;
	
	while ( t[i] != EOF ){
		
		swith (t[i]){
			
			case '\t' : printf("\\t")
			
			case '\n' : printf("\\n");
			
			default : putchar(origin[i]);
			
		}
		i++;
	}
	
}

void deescape(char s[MAXLEN], t[MAXLEN]){
	
	 	int i = 0;
	
	while ( t[i] != EOF ){
		
		swith (t[i]){
			
			case '\t' : printf("\\t")
			
			case '\n' : printf("\\n");
			
			default : putchar(origin[i]);
			
		}
		i++;
	}
	
}