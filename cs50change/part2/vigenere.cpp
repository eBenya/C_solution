/*Шифр виженера*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string vigenereChipher(char *text, char *key, int lenChipher/* = 26*/);
//text - the text you want to chipher;
//key = the key you want to encrypt
//lenChipher  - len variable simbol of key

//char encodeSimb(char c, int times);

int main(int argc, char *argv[]){

    if (argc != 2){
        printf("ERRRRRRROR!");
        return 1;
    }
    for(int i = 0, len = strlen(argv[1]); i < len ; i++)
        if( ! isalpha(argv[1][i]) ) return 1;

    printf("Write the string you want to encrypt:\n");
    string text = get_string("You entered - ");

    printf("ciphertext: %s\n", vigenereChipher(text, argv[1], 26)/*зашифрованая строка*/);
}

//encode the write text with key "key"
string vigenereChipher(char *text, char *key, int lenChipher/* = 26*/){
    for(int i = 0, j = 0, lenKey = strlen(key); i < strlen(text); i++){
        if(j == lenKey) j = 0;
        if((text[i] >= 'a') && (text[i] <= 'z') ) text[i] = (( text[i] - 'a' + tolower(key[j++]) - 'a' ) % lenChipher ) + 'a';
        if((text[i] >= 'A') && (text[i] <= 'Z') ) text[i] = (( text[i] - 'A' + tolower(key[j++]) - 'a' ) % lenChipher ) + 'A';
    }
    return text;
}
//return encode simbol "c"
/*char encodeSimb(char c, int times){
	return (c + times) % 26;
}*/