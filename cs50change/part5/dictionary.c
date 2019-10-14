/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

//some big word - "pneumonoultramicroscopicsilicovolcanoconiosis" contain 46 symbol + '\0' on the end
#define LENGHTWORD 47
#define HASHLENGHT 150000

struct hash_table {
	char word[LENGHTWORD];
	struct hash_table *next;
}*hash_dict[HASHLENGHT], hash_di;

int size_dict = 0;

unsigned int get_hash(const char * word);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char buf_word[LENGHTWORD];
    int i = 0;

    for(i = 0; i < strlen(word); i++)
        buf_word[i] = tolower(word[i]);
    buf_word[i] = '\0';

    int hash = get_hash(buf_word);
    struct hash_table *ptr = hash_dict[hash];
    while(ptr != 0){
        if(!strcmp(ptr->word, buf_word))
            return true;
        ptr = ptr->next;
    }
     // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    FILE * dictFile = fopen(dictionary, "r");
    if(!dictFile){
        printf("do not open file!\n");
        return false;
    }

    char word[LENGHTWORD];
    int hash = 0;
    struct hash_table *ptr;
    size_dict = 0;

    while(fgets(word, LENGHTWORD, dictFile) != NULL){       //take word on dictionary while there are words
        int len = strlen(word);

        word[len-1] = '\0';                                 //on the end word get char '\0'

        hash = get_hash(word);                              //calc hash value
        size_dict++;

        if(hash_dict[hash] == NULL){                        //if this word first on the value hash on the array
            hash_dict[hash] = malloc(sizeof(hash_di));      //allocate memory
            strcpy(hash_dict[hash]->word, word);            //copy on the allocate memory word
        }
        else{                                               //else, if this word is not first
            ptr = hash_dict[hash];

            while(ptr->next != NULL)                        //move on linked list, until do not meet NULL
                ptr = ptr->next;

            ptr->next = malloc(sizeof(hash_di));            //allocate memory
            ptr = ptr->next;
            strcpy(ptr->word, word);                        //copy on the allocate memory word
        }
    }

    if(fclose(dictFile)){
        unload();
        return false;
    }

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return size_dict - 1;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    struct hash_table *cur, *next;
    for(int i = 0; i <= HASHLENGHT; i++){
        cur = hash_dict[i];
        while (cur != NULL){
            next = cur->next;
            cur = next;
            free(cur);
        }
    }
    cur = next = NULL;
    return true;
}



unsigned int get_hash(const char * word) {
	/*unsigned int hash = 0;
	for (int i = 1; i <= strlen(word); i++) {
		hash += word[i - 1] * i;                      //если еще ввести независимый коэффициент k. C каждой след буквой, умножающий hash*k??
	}*/
	//hash function is copied from some site (this hash function economy us ~10ms)
	unsigned hash = word[0];
    for (unsigned i = 1; word[i]; hash = hash * 37 + word[i], i++) {}
    return hash % HASHLENGHT;
	return hash;
}
