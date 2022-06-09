/* Assignment: 1
Author: Tomer Raitsis
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int num, num1, num2, num3, num4, highest, lowest;

	printf("Enter a number between 0 and 9999: \n");
	scanf("%d", &num);

	if (num >= 0 && num < 10) {     // Incase the number has 1 digit and positive
		num1 = num;
		highest = num1;

		printf("Max digit:%d\n", highest);
	}
	else if (num >= 0 && num < 100) {    // Incase the number has 2 digits and positive
		num1 = num / 10;
		num2 = num % 10;

		if (num1 >= num2) {
			highest = num1;
			lowest = num2;
		}
		else {
			highest = num2;
			lowest = num1;
		}
		printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
	}
	else if (num >= 0 && num < 1000) {    // Incase the number has 3 digits and positive
		num1 = num / 100;
		num2 = num % 100;
		num2 /= 10;
		num3 = num % 10;
		if (num1 >= num2 && num1 >= num3) {
			highest = num1;

			if (num2 <= num3) {
				lowest = num2;

			}
			else {
				lowest = num3;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num2 >= num1 && num2 >= num3) {
			highest = num2;

			if (num1 <= num3) {
				lowest = num1;

			}
			else {
				lowest = num3;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num3 >= num1 && num3 >= num2) {
			highest = num3;

			if (num1 <= num2) {
				lowest = num1;

			}
			else {
				lowest = num2;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
	}
	else if (num >= 0 && num < 10000) {    // Incase the number has 4 digits and positive
		num1 = num / 1000;
		num2 = num % 1000;
		num2 /= 100;
		num3 = num % 100;
		num3 /= 10;
		num4 = num % 10;
		if (num1 >= num2 && num1 >= num3 && num1 >= num4) {
			highest = num1;

			if (num2 <= num3 && num2 <= num4) {
				lowest = num2;

			}
			else if (num3 <= num2 && num3 <= num4) {
				lowest = num3;
			}
			else {
				lowest = num4;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num2 >= num1 && num2 >= num3 && num2 >= num4) {
			highest = num2;

			if (num1 <= num3 && num1 <= num4) {
				lowest = num1;

			}
			else if (num3 <= num1 && num3 <= num4) {
				lowest = num3;
			}
			else {
				lowest = num4;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num3 >= num1 && num3 >= num2 && num3 >= num4) {
			highest = num3;

			if (num1 <= num2 && num1 <= num4) {
				lowest = num1;

			}
			else if (num2 <= num1 && num2 <= num4) {
				lowest = num2;
			}
			else {
				lowest = num4;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num4 >= num1 && num4 >= num2 && num4 >= num3) {
			highest = num4;
			if (num1 <= num3 && num1 <= num2) {
				lowest = num1;

			}
			else if (num2 <= num3 && num2 <= num4) {
				lowest = num2;
			}
			else {
				lowest = num3;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
	}
	else {                       // Incase the number has more than 4 digits or negative
		printf("Error: Worng number!");
	}

	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*if (num > 0 && num < 10000) {
		num1 = num / 1000;
		num2 = num % 1000;
		num2 /= 100;
		num3 = num % 100;
		num3 /= 10;
		num4 = num % 10;
		
		if (num > 0 && num < 1000) {
			num1 = num / 100;
			num2 = num % 100;
			num2 /= 10;
			num3 = num % 10;
			x = 3;
			if (num > 0 && num < 100) {
				num1 = num / 10;
				num2 = num % 10;
				x = 2;
		
				}
				if (num1 >= num2) {
					highest = num1;
					lowest = num2;
				}
				else {
					lowest = num1;
					highest = num2;
				}
			}
			if (num1 >= num2 && num1 >= num3) {
				highest = num1;

				if (num2 <= num3) {
					lowest = num2;

				}
				else {
					lowest = num3;
				}

				printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
			}
			else if (num2 >= num1 && num2 >= num3) {
				highest = num2;

				if (num1 <= num3) {
					lowest = num1;

				}
				else {
					lowest = num3;
				}
				printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
			}
			else if (num3 >= num1 && num3 >= num2) {
				highest = num3;

				if (num1 <= num2) {
					lowest = num1;

				}
				else {
					lowest = num2;
				}
				printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
			}
		}

		if (num1 >= num2 && num1 >= num3 && num1 >= num4) {
			highest = num1;

			if (num2 <= num3 && num2 <= num4) {
				lowest = num2;

			}
			else if (num3 <= num2 && num3 <= num4) {
				lowest = num3;
			}
			else {
				lowest = num4;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num2 >= num1 && num2 >= num3 && num2 >= num4) {
			highest = num2;

			if (num1 <= num3 && num1 <= num4) {
				lowest = num1;

			}
			else if (num3 <= num1 && num3 <= num4) {
				lowest = num3;
			}
			else {
				lowest = num4;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num3 >= num1 && num3 >= num2 && num3 >= num4) {
			highest = num3;

			if (num1 <= num2 && num1 <= num4) {
				lowest = num1;

			}
			else if (num2 <= num1 && num2 <= num4) {
				lowest = num2;
			}
			else {
				lowest = num4;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num4 >= num1 && num4 >= num2 && num4 >= num3) {
			highest = num4;
			if (num1 <= num3 && num1 <= num2) {
				lowest = num1;

			}
			else if (num2 <= num3 && num2 <= num4) {
				lowest = num2;
			}
			else {
				lowest = num3;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
	}
	return 0;
}


	/*switch (x) {
	case 1:
		highest = num1;

		printf("Max digit:%d\n", highest);
		break;


	case 2:
		if (num1 >= num2) {
			highest = num1;
			lowest = num2;
		}
		else {
			lowest = num1;
			highest = num2;
		}
		break;


	case 3:
		if (num1 >= num2 && num1 >= num3) {
			highest = num1;

			if (num2 <= num3) {
				lowest = num2;

			}
			else {
				lowest = num3;
			}

			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num2 >= num1 && num2 >= num3) {
			highest = num2;

			if (num1 <= num3) {
				lowest = num1;

			}
			else {
				lowest = num3;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num3 >= num1 && num3 >= num2) {
			highest = num3;

			if (num1 <= num2) {
				lowest = num1;

			}
			else {
				lowest = num2;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		break;

	case 4:
		if (num1 >= num2 && num1 >= num3 && num1 >= num4) {
			highest = num1;

			if (num2 <= num3 && num2 <= num4) {
				lowest = num2;

			}
			else if (num3 <= num2 && num3 <= num4) {
				lowest = num3;
			}
			else {
				lowest = num4;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num2 >= num1 && num2 >= num3 && num2 >= num4) {
			highest = num2;

			if (num1 <= num3 && num1 <= num4) {
				lowest = num1;

			}
			else if (num3 <= num1 && num3 <= num4) {
				lowest = num3;
			}
			else {
				lowest = num4;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num3 >= num1 && num3 >= num2 && num3 >= num4) {
			highest = num3;

			if (num1 <= num2 && num1 <= num4) {
				lowest = num1;

			}
			else if (num2 <= num1 && num2 <= num4) {
				lowest = num2;
			}
			else {
				lowest = num4;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		else if (num4 >= num1 && num4 >= num2 && num4 >= num3) {
			highest = num4;
			if (num1 <= num3 && num1 <= num2) {
				lowest = num1;

			}
			else if (num2 <= num3 && num2 <= num4) {
				lowest = num2;
			}
			else {
				lowest = num3;
			}
			printf("Min digit:%d\nMax digit:%d\n", lowest, highest);
		}
		break;
	}
	printf("%d", x);

	return 0;
}*/
