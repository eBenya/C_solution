#include <string.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <ctime>


void clear(void);
void swap(int *a, int *b);
void draw(void);
void init(void);
bool move(int tile);
bool won(void);

void random_matrix(int *a, int n1, int n2, int sizeArray_string);

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

//coord tile
struct Tile {
	unsigned short y; //column
	unsigned short x; //row
} theTile;

#include <conio.h>

int main() {
	srand(time(0));

	do {
		clear();
		std::cout << "Write how many(from "<< DIM_MIN <<" to " << DIM_MAX <<") size board you have see. " << std::endl;
		std::cin >> d;
		clear();
	} while ((DIM_MIN > d) || (DIM_MAX < d));
	
	init();
	
	//int tile;
	 do{
		clear();
		printf("Coordinate void tile is:\n board[%d][%d] = %d\n\n", theTile.y + 1, theTile.x + 1, board[theTile.y][theTile.x]);
		draw();
		//tile = 99;//getchar();
		move(99);
	 } while (!won());

	printf("won");
 }


void init(void) {
	// TODO
	//add possibility ranrom filling
	int first_el = d * d;
	printf("How you want filling the board?\nIf not random, write - Y. Else - N\n");
	
	char method_filling;
	while ( (((method_filling = getchar()) != 'Y') && (method_filling != 'y')) && ((method_filling != 'N') && (method_filling != 'n')) ) {
		printf("put simbol Y or N\n");
	}

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
	else { 
		//random( &board[0][0], first_el);

		random_matrix( &board[0][0], d, d, DIM_MAX);

		for (int i = 0; i < d; i++)
			for (int j = 0; j < d; j++)
				if ( 0 == board[i][j]){
					theTile.y = i;
					theTile.x = j;
				}
			
	}
}

void draw(void) {
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
	printf("\nIf you dont know what to do, press to h\n");
	printf("\"Help menu is not realization\"\n");
	printf("\nIn order to finish game, sort tile on board or tap to x in top left angle.\n\n");
}

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

bool move(int tile) {
	// TODO
	//Дурацкое решение от CS50
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
	}
	return false;
}

bool won(void) {
	// TODO
	for (int i = 0, k = 0; i < d; i++)
		for (int j = 0; (j < d) && (k < d*d - 1); j++)
			if (board[i][j] != ++k)
				return false;


	return true;
}


void clear(void) {
	/*printf("\033[2J");
	printf("\033[%d;%dH", 0, 0);*/

	system("cls");
}

//n1 = y(столбец(column)), n2 = x(строка(string))
void random_matrix(int *a, int n1, int n2, int sizeArray_string) {

	int size = n1 * n2;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++) {

			*(a + (i * sizeArray_string) + j) = rand() % (size);

			for (int k = 0; k <= i; k++)
				for (int l = 0; (l < n2) && ((i*sizeArray_string + j) > (k*sizeArray_string + l)); l++) {

					if (*(a + (i * sizeArray_string) + j) == *(a + (k * sizeArray_string) + l)) {
						*(a + (i * sizeArray_string) + j) = rand() % (size);
						k = 0;
						l = -1;
					}
				}
		}
}

/*void random(int *a, int size) {

	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++){

			*(a + (i * DIM_MAX) + j) = rand() % (size);

			for (int k = 0; k <= i; k++)
				for (int l = 0; (l < d) && ((i*d + j) > (k*d + l)); l++) {

					if (*(a + (i * DIM_MAX) + j) == *(a + (k * DIM_MAX) + l)) {
						*(a + (i * DIM_MAX) + j) = rand() % (size);
						k = 0;
						l = -1;
					}


				}
		}
}*/