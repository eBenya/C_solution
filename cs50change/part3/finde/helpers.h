/**
 * helpers.h
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n);

/**
 * Sorts array of n values.
 */
void sort(int values[], int n);

/*
*Metods sorts:
*/
/*void select_sort(int arr[], int n);		//OK выбором
void buble_sort(int arr[], int n);		//OK пузырьком(из-за ветвления ооооооочень долгий)
void ins_sort(int arr[], int n);		//OK вставками (too slow)
void merge_sort(int arr[], int start, int end);	//OK, it worked!!!
void merge(int arr[], int start, int mid, int end); //merge array*/

/*
*my helpers
*/
//print array, for see what is happens
/*void printArr(int arr[], int fist, int last, int val);//for see how it work.
//change elements
void swap(int *a, int *b);*/