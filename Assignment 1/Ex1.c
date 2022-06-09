/* Assignment: 1
Author: Tomer Raitsis
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define price 10.2
#define km_p 1.3
#define suitcase_p 2

int main() {
	int suitcase;
	float km, total;
	printf("Enter number of kilometers:\n");
	scanf("%f", &km);
	printf("Enter number of suitcases:\n");
	scanf("%d", &suitcase);
	total = price + (km * km_p) + (suitcase * suitcase_p);

	printf("The total price is %0.2f:\n", total);
	return 0;
}