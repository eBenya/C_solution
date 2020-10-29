#include <iostream>
#include <cstdlib>
//#include <ctime>

int random(int *a, int size);

int main(int argc, char** argv) {
	int x = 10;
	while (x --> 0) {
		printf("%d ", x);
	}
/*srand(time(0));
	int a[4][4];
	
	random(*a, 15);
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			printf("random num = %d\n", a[i][j]);
		printf("\n");*/	
		return 0;
}



int random(int *a, int size) {
	
	for (int i = 0; i < size; i++){
		
		a[i] = rand() % (size);
		
		for(int j = 0; j < i; j++){
			
			if(a[j] == a[i]) {
				
				a[i] = rand() % (size);
				
				j = 0;
			}
		}
	}	
}

