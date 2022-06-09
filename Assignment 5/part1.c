/* Assignment: 5
Author: Tomer Raitsis
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int SumEvenDigits(long num);
long CreateNumber(long number);
int CheckArithmeticSeries(long Number, int Diff);
int* odd_negative(int arr[], int size, int *res);
int growing_array(float arr[], int size);
int Symmetric(char* begin, char* end);
void Reducing(char* str);

void main() {
	long num = 123789;  // an input for the function
	printf("%d\n", SumEvenDigits(num));  // using the function and printing its output

	long number = 123456789;  // an input for the function
	printf("%ld\n", CreateNumber(number));    // using the function and printing its output

	long Number = 1357;   // an input for the function
	int Diff = 2;    // an input for the function
	printf("%d\n", CheckArithmeticSeries(Number, Diff));    // using the function and printing its output

	int arr[8] = { 1,4,24,-88,75,70,-35,42 };    // an input for the function
	int size = 8;    // an input for the function
	int res[2] = { 0 };  // an input for the function
	int* temp = NULL;  // a pointer to recieve the array that the function returns
	temp = odd_negative(arr, size, res); // temp gets the returned array from the function
	printf("%d %d\n", temp[0], temp[1]); // printing the amount of negative and odd numbers 

	float arr1[8] = { 1,3,15,20,33,65,84,94 };    // an input for the function
	int size1 = 8;    // an input for the function
	printf("%d\n", growing_array(arr1, size1));    // using the function and printing its output

	char str[10] = "abcdeedcba";    // an input for the function
	printf("%d\n", Symmetric(&str[0], &str[9]));   // using the function and printing its output

	char str1[] = "Th8j23$%2kmn6}3h";    // an input for the function
	Reducing(str1);   // using the function

}

int SumEvenDigits(long num){
	if (num >= 0)
	{
		if (num == 0) //setting the extreme case
			return 0; 
		if ((num % 10) % 2 == 0)  // in case the number is even
			return num % 10 + SumEvenDigits(num / 10); // returning the even digit + returning the function without the last digit
		return SumEvenDigits(num / 10); // returning the function without the last digit
	}
	return SumEvenDigits(num * -1); //in case the number is negative, returning the same number but positive
}

long CreateNumber(long num) {
	if (num == 0) { //setting the extreme case
		return 0;
	}
	if ((num % 10) % 2) { // in case the last digit is odd
		return (num % 10) + 10 * CreateNumber(num / 10);  //returning the last digit + 10 * returning the function without the last digit
	}  
	else {
		return CreateNumber(num / 10); //returning the function without the last digit
	}
}

int CheckArithmeticSeries(long num, int diff) {
	if ((num / 10) == 0) {  //setting the extreme case
		return 1;
	}
	if ((num % 10) - diff != ((num / 10) % 10)) { // in case the last digit - diff is not the digit before it
		return 0;
	}
	else{
		return CheckArithmeticSeries(num / 10, diff); //returning the function without the last digit
	}
}

int* odd_negative(int arr[], int size, int* res) {
	if (!size) {  //setting the extreme case
		return res;
	}
	if (arr[0] < 0) { // incase the number is negative
		res[0]++; // adding 1 to the 'res' array in the 0 place
	}
	if (arr[0] % 2) { // in case the number is odd
		res[1]++;   // adding 1 to the 'res' array in the 1 place
	}
	return odd_negative(arr + 1, size -= 1, res); //returning the function moving to the next adress in the array, subtracting 1 from size and the 'res' array
}

int growing_array(float arr[], int size) {
	if (size < 2) {  //setting the extreme case
		return 1;
	}
	if (arr[0] < arr[1]) { // incase the array is growing
		return growing_array(arr + 1, size - 1); // returning the function and moving to the next adrres of the array and substracting 1 from size
	}
	else {
		return 0; // returning 0 incase the numbers are not growing
	}
}

int Symmetric(char* begin, char* end) {
	if (begin == end || begin > end) {  //setting the extreme case
		return 1;
	}
	if (*begin == *end) { // incase the value of the 2 pointers is the same
		return Symmetric(begin + 1, end - 1); //returning the function and moving begin to the next character and end to the previous character
	}
	else {
		return 0; // returning 0 if the value of the pointers is not the same
	}
}

void Reducing(char* str) {
	if (str[0] != '\0') {   // the extreme case
		Reducing(str + 1); // returning the function and moving to the next character in the string
		if ((str[0] <= '9') && (str[0] >= '0')) { // in case the character is a number
			printf("%c", str[0]); // printing the character (the number)
		}
	}
}