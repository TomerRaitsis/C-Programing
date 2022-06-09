/* Assignment: 3
Author: Tomer Raitsis
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define size 5
int bigestraw(int arr[size][size]);
int bigestcol(int arr[size][size]);
int neighbors(int arr[size][size]);


void main() {
	int arr1[size][size], i, j;
	printf("Please enter a 5*5 array: ");
	for (i = 0; i < size; i++) {   // gets a 5*5 array from the user
		for (j = 0; j < size; j++) {
			scanf("%d", &arr1[i][j]);
		}
	}
	printf("Sum of maximums of lines: %d\n", bigestraw(arr1));
	printf("Sum of maximums of cols: %d\n", bigestcol(arr1));
	printf("Number of equal pairs of neighbors : %d\n", neighbors(arr1));
}

int bigestraw(int arr[size][size]) { 
	int i, j, sum = 0, max = 0;
	for (i = 0; i < size; i++) {   // a loop that lookes for the bigest sum of a raw and returns it
		for (j = 0; j < size; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
		sum += max;
		max = 0;
	}
	return sum;
}

int bigestcol(int arr[size][size]) {
	int i, j, sum = 0, max = 0;
	for (j = 0; j < size; j++) {     // a loop that lookes for the bigest sum of a column and returns it
		for (i = 0; i < size; i++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
		sum += max;
		max = 0;
	}
	return sum;
}

int neighbors(int arr[size][size]) {
	int i, j, neighbors = 0;
	for (i = 0; i < size; i++) {   // the loop goes over all the columns in each raw (all the numbers)
		for (j = 0; j < size; j++) {
			                                  // those terms check if its not out of the limits of the 5*5 array
			if (arr[i][j] == arr[i - 1][j]) { 
				if ((i - 1) >= 0) {  // check if it is not below the raw index
					neighbors++;
				}
			}
			if (arr[i][j] == arr[i][j - 1]) { 
				if ((j - 1) >= 0) {  // check if it is not below the column index
					neighbors++;
				}
			}
			if (arr[i][j] == arr[i - 1][j + 1]) { 
				if ((j + 1) <= size && (i - 1) >= 0) { // check if it is not below the raw index and and above the column index
					neighbors++;
				}
			}
			if (arr[i][j] == arr[i - 1][j - 1]) {
				if ((j - 1) >= 0 && (i - 1) >= 0) { // check if it is not below the raw index and and below the column index
					neighbors++;
				}
			}
		}  // the function counts only whats it already "passed" ( whats behind her) So that there will be no duplications
	}
	
	return neighbors;
}