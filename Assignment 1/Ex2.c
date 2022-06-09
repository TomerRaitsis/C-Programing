/* Assignment: 1
Author: Tomer Raitsis
*/
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592
#include<stdio.h>

int main() {
	float base, height, area,radius;
	int choice;
	printf("Choose shape:\n1 Triangle\n2 rectangle\n3 square\n4 cycle\n"); //User Chooses the shape
	scanf("%d", &choice);
	if (choice == 1) {          // Incase the shape is a Triangle
		printf("Enter base: ");
		scanf("%f", &base);
		printf("Enter height: ");
		scanf("%f", &height);
		area = (base * height) / 2;
			printf("Area is: %f\n", area);
	}
	else if (choice == 2) {       // Incase the shape is a rectangle
		printf("Enter base: ");
		scanf("%f", &base);
		printf("Enter height: ");
		scanf("%f", &height);
		area = height * base;
		printf("Area is: %f\n", area);
	}
	else if (choice == 3) {        // Incase the shape is a square
		printf("Enter base: ");
		scanf("%f", &base);
		area = base * base;
		printf("Area is: %f\n", area);
	}
	else if (choice == 4) {          // Incase the shape is a cycle
		printf("Enter radius: ");
		scanf("%f", &radius);
		area = radius*radius*PI;
		printf("Area is: %f\n", area);
	}
	else {                            // Incase the number doesn't suits the given options
		printf("You have selected a wrong number!");
	}
	return 0;
}