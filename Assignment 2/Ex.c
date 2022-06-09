/* Assignment: 2
Author: Tomer Raitsis
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int IsEven(int);
int IsPositive(int);
int CountDigits(int);
void Info();
void PrintFloatMax();
long ReverseDigits(long);
long GetLongNumber(long);
void PrintMaxCountDivisors(int, int);
void MaxCountDivisors();
int PrintSpecialNumbers();
void CountSpecialNumbers();
void Triangle(int);
void Square(int);
void Rectangle(int, int);
void AllShapes();


void main() {
	int choice = 0;
	long long1;
	while (choice != 7) {
		printf("Please choose an option:\n");
		printf("1- Info\n");
		printf("2- Print the number with the max float\n");
		printf("3- Reverse the digits and add 5\n");
		printf("4- Pick the number that has the max amount of divisors\n");
		printf("5- Print the special numbers\n");
		printf("6- Print shapes\n");
		printf("7- Exit\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			Info();
			break;
		case 2:
			PrintFloatMax();
			break;
		case 3:
			printf("Enter number:");
			scanf("%ld", &long1);
			printf("%ld\n", GetLongNumber(long1));
			break;
		case 4:
			MaxCountDivisors();
			break;
		case 5:
			CountSpecialNumbers();
			break;
		case 6:
			AllShapes();
			break;
		case 7:
			break;
		default:
			printf("Wrong number\n");

		}
	}
	printf("Have a nice day!");
}

int IsEven(int a) {
	if (a % 2 == 0) {// checking if the number is even
		return 1;
	}
	else {
		return 0;  // the fanction returns 1 if even 0 if not
	}
}

int IsPositive(int b) {
	if (b >= 0) {   // checking if the number is positive
		return 1;
	}
	else {
		return 0;  // the fanction returns 1 if positive 0 if not
	}
}

int CountDigits(int c) {
	int count;
	if (c == 0) {
		return 1; //if the number is 0 fanction returns 1 (1 digit)
	}
	for (count = 0; c != 0; count++) { //a loop to count the number of digits
		c /= 10;
	}
	return count; // fanction returns the amount of digits
}

void Info() {
	int d;
	printf("Enter a number ");
	scanf("%d", &d);   // getting a number from the user
	if (IsEven(d)) {  // cheking if its even or odd
		printf("%d is even\n", d);
	}
	else {
		printf("%d is odd\n", d);
	}
	if (IsPositive(d)) {  // checking if its positive or negative
		printf("%d is positive\n", d);
	}
	else {
		printf("%d is negative\n", d);
	}
	int digits = CountDigits(d);  // printing the amount of digits this number has
	printf("has %d digits\n", digits);
}

void PrintFloatMax() {
	float num = 1, max = 0, num1, highest = 0;
	int fullnum, count = 0, serial = 0;
	printf("Enter numbers:");
	while (num > 0) {  // collecting numbers from the user
		scanf("%f", &num);
		count++;  // counting thier position
		num1 = num;
		fullnum = num1;
		num1 -= fullnum;
		if (num1 > max) {  // cheking which number is the highest and whats its place in the line
			max = num1;
			serial = count;
			highest = num;
		}
	}
	if (serial != 0 && highest != 0) {  // printing the highest number and its place
		printf("%f\n%d\n", highest, serial);
	}
	else if (count == 1) {  // in case the first number is zero
		printf("Zero is the first number\n");
	}
	else {  //in case there are no floats numbers
		printf("There are no float numbers\n");
	}
}
long ReverseDigits(long a) {
	int count = 0, ex;
	long num = 0, temp, temp1;
	if (a > 0) {
		temp = a;
		temp1 = a;
		while (a != 0) {  // counting the amount of digits
			count++;
			a /= 10;
		}
		for (ex = 1; count > 1; count--) {   //  setting the exponent (amount of zeros)
			ex *= 10;
		}
		while (ex > 0) { //setting the new number
			temp = temp1;
			temp %= 10;
			temp *= ex;
			num += temp;
			ex /= 10;
			temp1 /= 10;
		}
	}
	return num;
}


long GetLongNumber(long b) {
	long num = ReverseDigits(b); // using the previous fanction 
	num += 5;  // adding 5 to the new number
	return num;
}


void PrintMaxCountDivisors(int low, int high) {
	int x = low, y, max = 0, count = 0, bigest = 0, count1 = 0;

	for (x = low; x <= high; x++) { //a loop to find the number/s with the most divisors
		for (y = 1; y <= x; y++) {  //counting the number of divisors
			if (x % y == 0) {
				count++;
			}
		}
		if (count > max) { // checking which number has the maximum amount of divisors
			max = count;
			bigest = x;
		}
		count = 0;
	}
	for (y = 1; y < bigest; y++) { // "saving" the amount of divisors for the next loop
		if (x % y == 0) {
			count1++;
		}
	}

	for (x = low; x <= high; x++) { // this loop is printing all the numbers that as the same amout of divisors as we "saved"
		for (y = 1; y <= x; y++) {
			if (x % y == 0) {
				count++;
			}
		}
		if (count == max) {
			printf("%d, %d divisors and it divides by :\n", x, max);
			for (y = 1; y <= x; y++) {                  // a loop to print all the number 
				if (x % y == 0) {
					printf(" %d\n", y);
				}
			}
		}
		count = 0;
	}
}

void MaxCountDivisors() {
	int low = 1, high = 1;
	do {    // a loop that will continue to the fanction only if the two numbers are positive as required
		if (low > high || low <= 0 || high <= 0) {
			printf("You've entered not positive numbers or in the wrong order\n\n");
		}
		printf("Enter 2 positive number\n");
		printf("The smaller number is :  ");
		scanf("%d", &low);
		printf("The bigger number is :  ");
		scanf("%d", &high);
	} while (low > high || low <= 0 || high <= 0);

	PrintMaxCountDivisors(low, high);
}

int PrintSpecialNumbers() {
	int a, b, c, d, e, count = 0;
	for (a = 9999; a > 999; a--) { //a loop to check all the 4 digit numbers (1000-9999)
		b = a % 10;
		c = (a % 100) / 10;
		d = (a % 1000) / 100;
		e = a / 1000;
		if (b != c && b != d && b != e) {  // checking if all the digits are different as requaired
			if (c != d && c != e) {
				if (d != e) {
					printf("%d\n", a);
					count++;
				}
			}
		}
	}
	return count;
}

void CountSpecialNumbers() {
	printf("There are %d numbers\n", PrintSpecialNumbers()); // printing the amount of the special numbers
}

void Triangle(int size) {
	int i, j;
	for (i = 1; i <= size; i++) {  // a loop to create a tringle with '*'
		for (j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void Square(int size) {
	int i, j;
	for (i = 1; i <= size; i++) { // a loop to create a square with '*'
		for (j = 1; j <= size; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void Rectangle(int raw, int col) { // a function to create a rectangle with '*' and '$'
	int i, j, d;
	for (i = 1; i <= 1; i++) {  // a loop for the first raw of the rectangle
		for (j = 1; j <= col; j++) {
			printf("#");
		}
	}
	printf("\n");
	for (i = 1; i <= (raw - 2); i++) { // a loop for the middle of the rectangle
		for (j = 1; j <= 1; j++) {
			printf("#");
			for (d = 1; d <= (col - 2); d++) {
				printf("$");
			}
			printf("#\n");
		}
	}
	if (raw > 1) {
		for (i = 1; i <= 1; i++) {// a loop for the last raw of the rectangle
			for (j = 1; j <= col; j++) {
				printf("#");
			}
		}
	}
	printf("\n");
}

void AllShapes() {
	int shape, size, raw, col;
	printf("Choose a shape:\n1- Triangle\n2- Square\n3- Rectangle\n4- Exit\n"); // user menu
	scanf("%d", &shape); // getting the users choice

	switch (shape) { // this switch menu converts the users choice to one of the functions
	case 1:
		printf("Enter size:\n");  // triangle
		scanf("%d", &size);
		Triangle(size);
		break;
	case 2:
		printf("Enter size:\n"); // square
		scanf("%d", &size);
		Square(size);
		break;
	case 3:
		printf("Enter height and width:\n"); // rectangle
		scanf("%d%d", &raw, &col);
		Rectangle(raw, col);
		break;
	case 4:
		break;
	default:
		printf("Wrong number\n");
	}
}
