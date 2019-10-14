#include <cs50.h>
#include <stdio.h>

void print_half_pyramide(int numb){
    for(int i = 0; i < numb; i++){
        for (int k = i; k <= numb+i; k++)
            if ( (k+2-numb) > 0 ) putchar('#');
            else putchar(' ');
        printf("\n");
    }
}

//почти идентична обрезанной версии, добавляется ветвление в строке 18
void print_pyramide(int numb) {
	for (int i = 0; i < numb; i++) {
		for (int k = i; k <= ((numb * 2) + i); k++)
			if ((k + 2 - numb) > 0)
				if (k - i > (numb + i)) putchar(' '); //добавлено это ветвление
				else putchar('#');
			else putchar(' ');
		printf("\n");
	}
}

int main(){
    char str[10];
    int block;
    printf("write number blocks half-pyramide, time to block has to more than 0 and less than 23\n");
    while ( ((block = get_int("%s",str)) > 23) || (block < 0) ) printf("wrong number\n");
    printf("Print half piramide:\n");
    print_half_pyramide(block);
    printf("\nPrint Full piramide:\n");
    print_pyramide(block);
}


/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent int; if text does not represent an int in [-2^31, 2^31 - 1)
 * or would cause underflow or overflow, user is prompted to retry. If line
 * can't be read, returns INT_MAX.
 */
// int get_int(const string format, ...) __attribute__((format(printf, 1, 2)));
