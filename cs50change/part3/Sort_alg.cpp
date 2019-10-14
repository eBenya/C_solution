/*Упражйение 5.8. В функциях day_of_year
и month_day нет никаких проверок правильности 
вводимых дат. Устраните этот недостаток.*/

#include "pch.h"
#include <stdio.h>
#include <string.h>

//#define LENNAME 50

//void initial2(char *name);

#include <iostream>

using namespace std;

//template<typename T>
//void swapp(T &a, T &b) {
//
//	T c = a;
//
//	a = b;
//
//	b = c;
//
//}


bool search(int value, int values[], int n);

void select_sort(int arr[], int n);		//OK выбором
void buble_sort(int arr[], int n);		//OK пузырьком(из-за ветвления ооооооочень долгий)
void ins_sort(int arr[], int n);		//OK вставками (too slow)
void merge_sort(int arr[], int start, int end);	//OK, it worked!!!
void merge(int arr[], int start, int mid, int end); //merge array

void printArr(int arr[], int fist, int last, int val);//for see how it work.
void swap(int *a, int *b);		//change elements


int main() {
	int arr[] = { 0,1,4,9,0,2,5,7,8,3,6 };
	int n = (sizeof(arr) / 4);  //Len arr[]
	int len = n - 1;			//Len for merge_sort
	
	//output array
	for (int i = 0; i < n; i++) {
		printf("arr[%d]=%d\n", i, arr[i]);
	}

	printf("\nSort...\n");

	printArr(arr, 1, n, 0);

	//select_sort(arr, n); //OK
	//buble_sort(arr, n); //OK (Maaaany permutation)(Конченая сортировка)
	//ins_sort(arr, n); //OK too many permutation
	merge_sort(arr, 1, len);//OK. Домучилю Как я туп..

	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	
	if (search(28, arr, n))	{
		printf("\nFound needle in haystack!\n\n");
		return 1;
	}
	else{
		printf("\nDidn't find needle in haystack.\n\n");
		return 0;
	}
}

//OK
void select_sort(int arr[], int n) {
	int min;
	int iter = 1;

	for (int i = 0; i < (n - 1); i++) {
		for (int j = min = i; j < n; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (min != i)
			swap(&arr[min], &arr[i]);
		printArr(arr, 0, n, iter++);
	}
}

//OK
void buble_sort(int arr[], int n) {
	int count;
	int max = 0;
	int iter = 1;
	do
	{
		count = 0;

		for (int i = 0; i < (n - max - 1); i++)
			if (arr[i] > arr[i + 1]) { //very many "if". mb possible app algoritm?
				swap(&arr[i], &arr[i + 1]);
				count = 1;
				printArr(arr, 0, n, iter++);
			}
		max++;
	} while (count == 1);
}

//OK
void ins_sort(int arr[], int n) { //most liked the logic of algorithm
	int sort = 1;
	int iter = 1;

	while (sort < n) {
		if (arr[sort - 1] > arr[sort])
			for (int i = sort; arr[i] < arr[i - 1]; i--) {
				swap(arr[i], arr[i - 1]);
				printArr(arr, 0, n, iter++);
			}
		sort++;
	}
}

int buff[500] = { NULL };
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
	int iter = 1;
	//int *buffer = new int[end-start+1];
	int once = start;
	int last = mid + 1;

	for (int i = start; i <= end; i++){
		//if left < right. if last do not exceed end or mid point exceeded last value
		if ( ((last <= end) && (arr[once] < arr[last])) || (last > end) )
			buff[i] = arr[once++];
		else
			buff[i] = arr[last++];

		printArr(buff, 1, end + 1, iter++);
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

//Returns true if value is in array of n values, else false. 
//Что ищу, среди чего ищу, размер
bool search(int value, int values[], int n) {
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








//void initial2(char *name) {
//
//	int i, n, inWord;
//	i = n = inWord = 0;
//
//	while (name[i] != '\n' && name[i] != EOF && name[i] != '\0') {
//
//		if (name[i] == ' ') inWord = 0;
//		else if (inWord == 1) inWord = 2;
//		else inWord = 1;
//
//		if (inWord == 1) {
//			if ((name[i] >= 'a') && (name[i] <= 'z'))
//				name[i] = name[i] - ('a' - 'A');
//			name[n++] = name[i];
//		}
//		i++;
//	}
//}

//struct Templ1
//{
//	short i = 5;
//	short a = 3;
//	int integ = 257;
//	char c = 'w';
//};
//
//int main() {
//	std::cout << "Hello World!\n";
//	Templ1 newT;
//	int n = 257;
//	if ( newT.integ == n) std::cout << "struct is try\n";
//
//	int a = 1;
//	int b = 7; 
//	int z = (a++, b++);
//	std::cout << "a = " << a << "\nb = " << b << "\nz = " << z << std::endl;
//	printf("%d\n",printf("Function printf() return len string. This string have simbols is "));//прикольно, принт возвращает длинну
//	float c = 0.53;
//	printf("float c = %0.50f\n", round(fmod(c*100, 100)));
//	printf("\nPointerSection:\n");
//	int val = 7;
//	int *pval = &val;
//	std::cout << "pval = " << *pval << std::endl;
//
//	int **ppval = &pval;
//	std::cout << "ppcal = " << **ppval << std::endl;
//}
