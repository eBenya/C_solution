/*Шифр цезаря ин. алфавита*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

string caeserChipher(string text, int key);
char encodeSimb(char c, int times);

int main(int argc, char *argv[]){

    if (argc != 2){
        printf("ERRRRRRROR!");
        return 1;
    }
    printf("Write the string you want to encrypt:\n");
    string text = get_string("You entered - ");
    int key = atoi(argv[1]);

    printf("ciphertext: %s\n", caeserChipher(text, key));


    return 0;
}
//encode the write text with key "key"
string caeserChipher(string text, int key){
    for(int i = 0; i < strlen(text); i++){
        if((text[i] >= 'a') && (text[i] <= 'z') ) text[i] = ( text[i] - 97 + key) % 26 + 97;
        if((text[i] >= 'A') && (text[i] <= 'Z') ) text[i] = ( text[i] - 65 + key) % 26 + 65;
    }
    return text;
}
//return encode simbol "c"
/*char encodeSimb(char c, int times){
	return (c + times) % 26;
}*/
/*char encodeSimb(char d1, char d2, char c, int times){
    if (times > 26)
		times = times % 26;//обрезать key
	if (times > (d2 - c))
		return d1 + (times - d2 + c - 1);
	else return c + times;
}*/