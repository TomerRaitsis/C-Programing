/* Assignment: 1
Author: Tomer Raitsis
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	float value;
	int hexnum,num;  // hexnum = hexadecimal base
	char ch;
	printf("Enter value\n");
	scanf("%f", &value);
	hexnum = value;
	ch = value;
	num = value;
	printf("The value is:%f\n", value);
	printf("The integer value is:%d\n", num);
	printf("The integer in hexadecimal base is:0x%x\n",hexnum);
	printf("The char is:%c", ch);
	return 0;
}