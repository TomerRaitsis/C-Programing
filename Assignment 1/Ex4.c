/* Assignment: 1
Author: Tomer Raitsis
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define passed 56
int main() {
	int test, project, w1, w2, w3, w4, w5,fgrade;  //fgrade == final grade
	printf("Enter your grades:\n");  // getting all the grades
	printf("test:"); 
	scanf("%d", &test);
	printf("project:");
	scanf("%d", &project);
	printf("homeworks:\n");
	scanf("%d%d%d%d%d", &w1,&w2,&w3,&w4,&w5);
	if (test < passed) {      // incase the student failed the test
		fgrade = test;
	}
	else {
		fgrade = (0.7 * test) + (0.1 * project) + (0.2 * ((w1 + w2 + w3 + w4 + w5) / 5)); // incase the student passed the test
	}
	printf("The grade is:%d\n",fgrade);
	if (fgrade < passed) {
		printf("failed\n");
	}
	else {
		printf("passed\n");
	}

	return 0;
}