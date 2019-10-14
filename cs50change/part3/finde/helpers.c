/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"



/**
*Metods sorts:
**/
void select_sort(int arr[], int n);		//OK выбором
void buble_sort(int arr[], int n);		//OK пузырьком(из-за ветвления ооооооочень долгий)
void ins_sort(int arr[], int n);		//OK вставками (too slow)
void merge_sort(int arr[], int start, int end);	//OK, it worked!!!
void merge(int arr[], int start, int mid, int end); //merge array



/**
*my helpers
**/
//print array, for see what is happens
void printArr(int arr[], int fist, int last, int val);//for see how it work.
//change elements
void swap(int *a, int *b);


/**
 * Returns true if value is in array of n values, else false.
 */
 //Что ищу, среди чего ищу, размер
bool search(int value, int values[], int n){
    // TODO: implement a searching algorithm

	//линейный поиск
	/*for (int i = 0; i < n; i++) {
		if (values[i] == value) return true;
	}
	return false;*/

	//бинарный поиск
	int correct;

	if (values[n-1] == value) return true;
	else
		if (values[0] == value) return true;
	
	correct = n = n / 2;
	do {
		correct /= 2;
		if (values[n] == value) return true;
		else 
			if (values[n] > value) n -= correct;
			else n += correct;
	}while (correct > 0);
	return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n){
    // TODO: implement an O(n^2) sorting algorithm
    int min;

	for (int i = 0; i < (n - 1); i++) {
		for (int j = min = i; j < n; j++) {
			if (values[min] > values[j]) {
				min = j;
			}
		}
		if (min != i)
			swap(&values[min], &values[i]);
	}
    return;
}



/*Solution algorithm*/
//OK
void select_sort(int arr[], int n) {
	int min;
	//int iter = 1;

	for (int i = 0; i < (n - 1); i++) {
		for (int j = min = i; j < n; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (min != i)
			swap(&arr[min], &arr[i]);
		//printArr(arr, 0, n, iter++);
	}
}

//OK
void buble_sort(int arr[], int n) {
	int count;
	int max = 0;
	//int iter = 1;
	do
	{
		count = 0;

		for (int i = 0; i < (n - max - 1); i++)
			if (arr[i] > arr[i + 1]) { //very many "if". mb possible app algoritm?
				swap(&arr[i], &arr[i + 1]);
				count = 1;
				//printArr(arr, 0, n, iter++);
			}
		max++;
	} while (count == 1);
}

//OK
void ins_sort(int arr[], int n) { //most liked the logic of algorithm
	int sort = 1;
	//int iter = 1;

	while (sort < n) {
		if (arr[sort - 1] > arr[sort])
			for (int i = sort; arr[i] < arr[i - 1]; i--) {
				swap(&arr[i], &arr[i - 1]);
				//printArr(arr, 0, n, iter++);
			}
		sort++;
	}
}

int buff[500] = { 0 };
//OK
void merge_sort(int arr[], int start, int end) {

	if (end > start) {
		int mid = (start + end) / 2;

		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);

		merge(arr, start, mid, end);
	}
}

void merge(int arr[], int start, int mid, int end) {
	//int iter = 1;
	//int *buffer = new int[end-start+1];
	int once = start;
	int last = mid + 1;

	for (int i = start; i <= end; i++){
		//if left < right. if last do not exceed end or mid point exceeded last value
		if ( ((last <= end) && (arr[once] < arr[last])) || (last > end) )
			buff[i] = arr[once++];
		else
			buff[i] = arr[last++];

		//printArr(buff, 1, end + 1, iter++);
	}

	for (int i = start; i <= end; i++) arr[i] = buff[i];

	//delete []buffer;
	//buffer = nullptr;
}



void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void printArr(int arr[], int first, int last, int val) {
	printf("Sort %d step:\n", val);
	//for (int i = 0; i < n; i++)
	//printf(" %d: ", i);

	printf("\n ");

	for (int i = first; i < last; i++)
		printf("[%d] ", arr[i]);
	printf("\n");
}



