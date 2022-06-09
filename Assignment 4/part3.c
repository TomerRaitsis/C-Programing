/* Assignment: 4
Author: Tomer Raitsis
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
long long** shrink(int** a, int size);
long long connectnums(int a, int b, int c, int d);

void main() {
	unsigned int** a;
	int size, i, j;
	long long **arr = NULL;
	printf("Enter size of the array: ");  // getting the size of the array from the user
	scanf("%d", &size);
	a = (unsigned int**)malloc(size * sizeof(unsigned int*)); // setting the array 
	if (a == 0) {    
		printf("Error! can't allocate memory"); // checking if malloc worked
		return NULL;
	}
	for (i = 0; i < size; i++) { 
		a[i] = (unsigned int*)malloc(size * sizeof(unsigned int)); // finishing the array 
		if (a[i] == NULL) {    //checking if malloc worked for every array
			printf("Error! can't allocate memory");
			return NULL;
		}
	}
	printf("Enter your array: \n");  // getting the array from the user
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++){
			scanf("%u", &a[i][j]);
		}
	}
	 arr = shrink(a, size); // saving the array that returns from the functions
	for (i = 0; i < (size / 2); i++) {  // a loop to print the new array
		for (j = 0; j < (size / 2); j++) {
			printf("%lld  ",arr[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < size; i++) { // a loop to free all the arrays
		free(a[i]);
	}
	for (i = 0; i < (size/2); i++) {// a loop to free all the arrays
		free(arr[i]);
	}
	free(a); // freeing the main array
	free(arr);  // freeing the main array
}


long long** shrink(unsigned int** a, int size) {
	long long** arr;
	int i, j,z,y;
	if ((size % 2) != 0) {  // returning NULL if the size is an odd number
		return NULL;
	}
	arr = (long long**)malloc((size / 2) * sizeof(long long));  // setting the array 
	if (arr == 0) {
		printf("Error! can't allocate memory"); // checking if malloc worked
		return NULL;
	}
	for (i = 0; i < (size / 2); i++) {
		arr[i]=(long long*)malloc((size / 2) * sizeof(long long)); // finishing the array
		if (arr[i] == NULL) {    //checking if malloc worked for every array
			printf("Error! can't allocate memory");
			return NULL;
		}
	}
	z = 0;
	y = 0;
	for (i = 0; i < (size); i+=2) {  // a loop that builds the new array
		for (j = 0; j < (size); j+=2) {
			arr[z][y] = connectnums(a[i][j + 1], a[i][j], a[i + 1][j + 1],a[i+1][j]); // using another function to build the needed number
			y++;
		}
		y = 0;
		z++;
	}

	return arr;  // returning the new array 
}


long long connectnums(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
	long long num;     // this functiong gets 4 'uints' and turns them into one 'long long' number
	long long  sizec = 0, sizeb = 0, sizea = 0, i;
	long long aa = a, bb = b, cc = c, dd = d;
	long long multiA = a, multiB = b, multiC = c , multiD = d;
	while (dd != 0) {  //geting the amount of zeroes for 'c'
		dd /= 10;
		sizec++;
	}
	while (cc != 0) {  //geting the amount of zeroes for 'b'
		cc /= 10;
		sizeb++;
	}
	while (bb != 0) {  //geting the amount of zeroes for 'a'
		bb /= 10;
		sizea++;
	}
	for (i = 0; i < sizec; i++)  //setting the number 'c' with the needed amount of zeroes
		multiC *= 10;

	for (i = 0; i < (sizeb + sizec); i++)  //setting the number 'b' with the needed amount of zeroes
		multiB *= 10;

	for (i = 0; i < (sizea + sizeb + sizec); i++)  //setting the number 'a' with the needed amount of zeroes
		multiA *= 10;

	num = multiA + multiB + multiC + multiD;  // sum of all the numbers (long long numbers) needed

	return num;  // returning num
}