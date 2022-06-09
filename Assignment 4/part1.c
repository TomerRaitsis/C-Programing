/* Assignment: 4
Author: Tomer Raitsis
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define size 51
void str_statistics(char str[], int* big, int* small, int* nums);

void main() {
	char ch[size];
	int numbers , bigL, smallL ;
	printf("Enter a string:\n");  // getting the string from the user
	gets(ch);
	str_statistics(ch, &bigL, &smallL, &numbers ); // using the function
	printf("%d small letters\n", smallL); // printing the amount of lowercase letters
	printf("%d capital letters\n", bigL); // printing the amount of capital letters
	printf("%d digits\n", numbers);  // // printing the amount of numbers
}

void str_statistics(char str[], int* big, int* small, int* nums) {
	int i, cbig = 0, csmall = 0, cnums = 0, len = strlen(str);
	for (i = 0; i <= len; i++) {
		if (str[i] >= '0' && str[i] <= '9') // counting the amount of numbers
			cnums++;
		if (str[i] >= 'A' && str[i] <= 'Z') // counting the amount of capital letters 
			cbig++;
		if (str[i] >= 'a' && str[i] <= 'z') // counting the amount of lowercase letters
			csmall++;
	}
	*big = cbig; //changing the number of capital letters
	*small = csmall;  //changing the number of lowercase letters
	*nums = cnums;  //changing the number of numbers
}