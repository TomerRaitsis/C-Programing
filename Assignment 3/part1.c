/* Assignment: 3
Author: Tomer Raitsis
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define sizes 5 //small size
#define sizeb 10 // big size
#define sizesta 10 // statistics size

int contain(int big[], int size_b, int small[], int size_s);  //function declaration
void digits(int arr[], int size, int statistics[]);  //function declaration

void main() {
	int small[sizes], big[sizeb], i, statistics[10] = { 0 }; 
	printf("Enter the numbers for array 'small' :\n"); 
	for (i = 0; i < sizes; i++) {  // a loop that asks the user for number for array 'small'
		scanf("%d", &small[i]);
	}
	printf("Enter the numbers for array 'big' :\n");
	for (i = 0; i < sizeb; i++) {  // a loop that asks the user for number for array 'big'
		scanf("%d", &big[i]);
	}
	if ((contain(big, sizeb, small, sizes)) == -1) { // using the function to check if the arrays have numbers in common
		printf("The arrays have no common numbers\n");
	}
	else {
		printf("The arrays are the same from index %d\n", contain(big, sizeb, small, sizes)); 
	}    // the small array is in the big array, the begining index will be printed on the screen

	digits(small, sizes, statistics);
	printf("Small array:\n");   // using the digits function on 'small' and printing the statistics array
	for (i = 0; i < sizesta; i++) {
		printf("%d\n", statistics[i]);
	}
	for (i = 0; i < sizesta; i++) {  // a loop to zero the statistics array 
		statistics[i] = 0;
	}
	digits(big, sizeb, statistics);
	printf("Big array:\n");     // using the digits function on 'big' and printing the statistics array
	for (i = 0; i < sizesta; i++) {
		printf("%d\n", statistics[i]);
	}
}


int contain(int big[], int size_b, int small[], int size_s) {
	int i = 0, j = 0, count = 0, index = 0;
	while (i < size_b) {  // the loop goes over the big loop
		if (big[i] == small[j]) { // if the number in the big array is the same as the number in the small array
			count++;
			if (count == 1) {
				index = i;  // saving the index from the begining of the small loop in the big one
			}
			i++;
			j++;
			if (count == size_s) // thist means all the small loop is in the big ome and there is no need to continue
				break;
		}
		else {       // if the i number is different from the j: 
			count = 0;
			index = 0;
			j = 0;       // count is back to zero, the small loop starts all over the i number of the big array 
			i++;           // and  the i number of the big array noves to the next one
		}
	}
	if (count == size_s) { // when the count is as size_s the whole small aray is in the big one
		return index;
	}
	else {           // the small arry is not in the big array
		return -1;
	}
}

void digits(int arr[], int size, int statistics[]) {
	int i, num, num1;
	for (i = 0; i < size; i++) { // a loop to go over all the numbers in the array
		num = arr[i]; 
		if (num == 0) { // if the number is zero, it will add 1 to index 0 in statistics
			statistics[0]++;
		}
		while (num) { 
			num1 = num % 10; // separating the number to digits to check each one
			if (num1 < 0) {
				num1 *= -1; // in case the number is negative
			}
			statistics[num1]++; //adding 1 to the index 'num1' in statistics array
			num /= 10;
		}
	}
}