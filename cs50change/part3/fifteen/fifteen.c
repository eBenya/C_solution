/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#include "helper.h"

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

//Tile
struct Tile{
    unsigned short y; //column
    unsigned short x; //row
};
struct Tile theTile;

//helper
void swap(int *a, int *b);
void random_board(int *a, int size);

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);


int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void){
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void){
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void){
	// TODO
	//add possibility ranrom filling
	int first_el = d * d;
	printf("How you want filling the board?\nIf not random, write - Y. Else - N\n");
	//take parametr
	char method_filling;
	/*while ( (((method_filling = getchar()) != 'Y') && (method_filling != 'y')) && ((method_filling != 'N') && (method_filling != 'n')) ) {
		printf("put simbol Y or N\n");
	}*/
    method_filling = 89;
	//Не рандомное заполнение
    if ( (method_filling == 'Y') || (method_filling == 'y') ) {
		if (d != 3) {
			for (int i = 0, k = 1; i < d; i++)
				for (int j = 0; (j < d) && (k < first_el); j++)
					board[i][j] = first_el - k++;
			swap(&board[d - 1][d - 2], &board[d - 1][d - 3]);
		}
		else {
			for (int i = 0, k = 1; i < d; i++)
				for (int j = 0; (j < d) && (k < first_el); j++)
					board[i][j] = first_el - k++;
		}
		//Рассполоюение пустой плитки
		theTile.x = d - 1;
		theTile.y = d - 1;
	}
	//Рандомное
    else{
		random_board( &board[0][0], first_el);
		for (int i = 0; i < d; i++)
			for (int j = 0; j < d; j++)
				if ( 0 == board[i][j]){
					theTile.y = i;
					theTile.x = j;
				}

	}
}

/**
 * Prints the board in its current state.
 */
void draw(void){
    // TODO
    //printf("\n");
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
		    if (board[i][j] != 0)
			    printf(" %2d ", board[i][j]);
			else printf("    ");
		}
		printf("\n\n");
	}
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
 //принимает число которое хотим передвинуть
bool move(int tile){
    // TODO
	//For CS50
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			if (tile == board[i][j]) {
				if ( ((theTile.y == i + 1) && (theTile.x == j)) ||
					 ((theTile.y == i - 1) && (theTile.x == j)) ||
					 ((theTile.y == i) && (theTile.x == j - 1)) ||
					 ((theTile.y == i) && (theTile.x == j + 1)) ) {
					//swap(&board[i][j], &board[theTile.y][theTile.x]);
					board[i][j] ^= board[theTile.y][theTile.x] ^= board[i][j];
					theTile.x = j;
					theTile.y = i;
					return true;
				}
			}
		}
	}

	//My realisation for drive arrows
/*
	int c = _getch();

	//clear();

	switch (c)
	{
			//DOWN
		case 80: {
			if ((theTile.y) > 0) {
				swap(&board[theTile.y - 1][theTile.x], &board[theTile.y][theTile.x]);
				theTile.y -= 1;
				printf("\nDOWN\nx = %d; y = %d; \n", theTile.x, theTile.y);
				return true;
			}
			break;
		}
				 //UP
		case 72: {
			if ((theTile.y) < (d - 1)) {
				swap(&board[theTile.y + 1][theTile.x], &board[theTile.y][theTile.x]);
				theTile.y += 1;
				printf("\nUP\nx = %d; y = %d; \n", theTile.x, theTile.y);
				return true;
			}
			break;
		}
				 //LEFT
		case 75: {
			if (theTile.x < (d - 1)) {
				swap(&board[theTile.y][theTile.x + 1], &board[theTile.y][theTile.x]);
				theTile.x += 1;
				printf("\nLEFT\nx = %d; y = %d; \n", theTile.x, theTile.y);
				return true;
			}
			break;
		}
				 //RIGHT
		case 77: {
			if (theTile.x > 0) {
				//if()
				swap(&board[theTile.y][theTile.x - 1], &board[theTile.y][theTile.x]);
				theTile.x -= 1;
				printf("\nRIGHT\nx = %d; y = %d; \n", theTile.x, theTile.y);
				return true;
			}
			break;
		}

		default: {
			if ((c == 224) || (c == 0)) break;
			//call help menu. Do not realization!
			printf("\ndebug input:\ncode simbol c - %d, char c - %c\n", c, c);
			printf("\nIf you dont know what to do, press to h\n ");
			break;
		}
	}*/
	return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void){
    // TODO
    for (int i = 0, k = 0; i < d; i++)
		for (int j = 0; (j < d) && (k < d*d - 1); j++)
			if (board[i][j] != ++k)
			    return false;


	return true;
}

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

//For init. random initialization board
void random_board(int *a, int size) {
	//*a = rand() % (size);

	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++){

			*(a + (i * DIM_MAX) + j) = rand() % (size);  //reference shaitan costil

			for (int k = 0; k <= i; k++)
				for (int l = 0; (l < d) && ((i*d + j) > (k*d + l)); l++) {

					if (*(a + (i * DIM_MAX) + j) == *(a + (k * DIM_MAX) + l)) {
						*(a + (i * DIM_MAX) + j) = rand() % (size);
						k = 0;
						l = -1;
					}


				}
		}
}