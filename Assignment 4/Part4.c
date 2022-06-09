/* Assignment: 4
Author: Tomer Raitsis
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 51
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char** init_arr(int* psize);  //declaring the functions
char** add(char** arr, int* psize, char* str);
void twice(char** arr, int size, int index);
int find(char** arr, int size, char* str);
void print(char** arr, int size);
int equality(char* arr, char* str);

void main() {
	int choice = 0, size, size1,index ,i;
	char** arr = NULL, str[MAX] = { 0 }, tempstr[MAX] = { 0 };
	
	printf("Enter the size of your array\n"); // getting the number of the word from the user
	scanf("%d", &size);
	getchar();

	printf("Enter the words\n"); // getting all the word from the user
	arr = init_arr(&size);


	while (choice != 5) {
		
		printf("1 - Add\n2 - Twice\n3 - Find\n4 - Print\n5 - End\n"); // the user's menu
		scanf("%d", &choice); // getting the users's choice;
		getchar(); 

		switch (choice) {
		case 1:
			printf("Enter a word\n");
			gets(str); // getting a word from the user
			size1 = size;
			arr = add(arr, &size, str); //using the function to add the new word
			if (size > size1) {
				printf("The word was added succesfully\n");
			}
			else {
				printf("The word was not added \n"); // incase the word is already in the array
			}
			break;

		case 2:
			printf("Enter the wanted index:\n");
			scanf("%d", &index);  // getting a index from the user
			twice(arr, size, index); // using the function to duplicate the word at the user's index
			break;
		case 3:
			printf("Enter a word\n");
			gets(str);  // getting a word from the user
			index = find(arr, size, str); // using the function to find the word in the array
			if (index == -1) {
				printf("The word is not in the array\n"); // incase the word is not in the array
			}
			else if (index >= 0 && index <= size) {
				printf("The index is : %d\n", index); // printing the index of the word
			}
			else {
				printf("Wrong index\n"); // incase there is no such index
			}
			
			break;
		case 4:
			printf("The array is:\n");
			print(arr, size); // printing the array
			break;
		case 5:
			for (i = 0; i < size; i++) {    // freeing the array 
				free(arr[i]);
			}
			free(arr);
			printf("Good bye\n");
			break;
		default:
			printf("Wrong number, please choose one of the options! \n"); // the number is not from the menu
		}
	}

}

char** init_arr(int* psize) {
	char** str = NULL;
	int i, j, len;
	char string[MAX];

	str = (char**)malloc(*psize * sizeof(char*)); // making the array ( with the number of words)
	if (str == NULL) { // checking if malloc worked
		return NULL;
	}
	for (i = 0; i < *psize; i++) {
		gets(string);  // getting a word from the user
		str[i] = (char*)malloc(MAX * sizeof(char)); // making the array ( with the number of digits)
		if (str[i] == NULL) {// checking if malloc worked
			return NULL;
		}
		strcpy(str[i], string); // copying the word to it's place in the array
	}

	return str; // returning the new string
}

char** add(char** arr, int* psize, char* str) {
	int i, j, count = 0, notsame = 0;
	char** newstr = NULL;

	for (i = 0; i < *psize; i++) {
		if (strlen(arr[i]) < strlen(str)) { // checking if the strings are not in the same size
			count++;
		}
		else if (strlen(arr[i]) > strlen(str)) {// checking if the strings are not in the same size 
			count++;
		}
		else {
			for (j = 0; j < strlen(str); j++) { // incase there are in the same size
				if (arr[i][j] != str[j]) { // cheking if they are simillar
					count++;
				}
			}
		}
		if (!count) {
			return arr; // if the word is already in the array, it will return the same string
		}
		else {
			notsame++;
		}
		count = 0;
	}

	if (notsame == *psize) { // incase the word is not in the array
		newstr = (char**)realloc(arr, sizeof(char*) * (*psize + 1)); //making an array with space for the word
		if (newstr == NULL) { // checking if malloc worked
			return NULL;
		}
		newstr[*psize] = (char*)malloc(MAX * sizeof(char)); //making a new array with space for the word
		if (newstr[*psize] == NULL) { // checking if malloc worked
			return NULL;
		}
		strcpy(newstr[*psize], str); // copying the word into the new array
		*psize += 1; // updating the number of words in the array

		return newstr; // returning the new string
	}
	
}
void twice(char** arr, int size, int index) {
	char temp[MAX] = { 0 };
	int i;
	if (index >= 0 && index < size) { // checking that the index is in the array
		for (i = 0; i < (strlen(arr[index])); i++) {
			temp[i] = arr[index][i]; //duplicating the word 
		}
		strcat(arr[index], temp); // duplicating the word
		printf("The word has been successfully duplicated\n");
	}
	else {
		printf("Wrong index\n"); // incase there is a wrong index
	}
}
int find(char** arr, int size, char* str) {
	int len1, len2;
	int count = 0, i;
	for (i = 0; i < size; i++) {
		len1 = strlen(arr[i]); // getting the size of a string
		len2 = strlen(str); // getting the size of a string
		if (len1 == len2) {
			if (equality(arr[i], str)) { // checking if the string are equal
				return i; // if they are it will return the index
			}
			count++;
		}
		else {
			count++;
		}
		if (count == size) {
			return -1; // incase they are no such word in the array it will return -1
		}
	}
	

}
int equality(char* arr, char* str) { // a functoin that check if two strings are equal
	int i, len1 = strlen(str);
	int count = 0;
	for (i = 0; i < len1; i++) {
		if (arr[i] != str[i]) { // checking if the strings have same digits
			count++;
		}
		if (!count) { // if they are equal it will return a 1
			return 1;
		}
		else {
			return 0; // if they are not equal it will return a 0
		}
	}

}
void print(char** arr, int size) {
	int i;
	for (i = 0; i < size; i++) { // printing all the words in the array
		puts(arr[i]);
	}
}