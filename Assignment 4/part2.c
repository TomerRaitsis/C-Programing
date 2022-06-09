/* Assignment: 4
Author: Tomer Raitsis
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int* divide(int a[], int size_a, int b[], int size_b);

void main() {
	int size_a, size_b, i;
	int* a = NULL, * b = NULL, * c = NULL;
	printf("Enter size of a: ");  // getting the size of the first string
	scanf("%d", &size_a);
	a = (int*)malloc(size_a * sizeof(int));  // preparing the array
	if (a == NULL) {    // checking if malloc worked ( there is enough space for the array)
		printf("Error! can't allocate memory"); // letting the user knoe that malloc didn't worked
		return NULL;
	}
	printf("Enter elements of a: \n"); // getting numbers for the array from the user
	for (i = 0; i < size_a; i++) {
		scanf("%d", &a[i]);
	}
	
	printf("Enter size of b: "); // getting the size of the second string
	scanf("%d", &size_b);
	b = (int*)malloc(size_b * sizeof(int));  // preparing the array
	if (b == NULL) {    // checking if malloc worked ( there is enough space for the array)
		printf("Error! can't allocate memory"); // letting the user knoe that malloc didn't worked
		return NULL;
	}
	printf("Enter elements of b: \n"); // getting numbers for the array from the user
	for (i = 0; i < size_b; i++) {
		scanf("%d", &b[i]);
	}

	for (i = 0; i < size_b; i++) {  // turning 0 into 1 in the second array
		if (b[i] == 0) 
			b[i] = 1;
	}

	c = divide(a, size_a, b, size_b);  //calling the function and saving what it returns in 'c'

	for (i = 0; i < size_b; i++) {  // a loop to print array 'c'
		printf("%d ", c[i]);
	}
	free(a); // setting free the dynamic memories
	free(b); // setting free the dynamic memories
	free(c); // setting free the dynamic memories
}



int* divide(int a[], int size_a, int b[], int size_b) {
	int i, count = 0, j;
	int* c = NULL;
	c = (int*)malloc(size_b * sizeof(int));  // preparing the array
	if (c == 0) {    // checking if malloc worked ( there is enough space for the array)
		printf("Error! can't allocate memory"); // letting the user knoe that malloc didn't worked
		return NULL;
	}
	
	for (i = 0; i < size_b; i++) {  // A loop to check how many numbers from array 'a' are dividable by each number from array 'b'
		for (j = 0; j < size_a; j++) {
			if ((a[j] % b[i]) == 0) {
				count++;
			}
			c[i] = count; // saving the amount of the numbers in array 'c'
		}
		count = 0;
	}
	return c; // returning the adrres of array 'c'
}