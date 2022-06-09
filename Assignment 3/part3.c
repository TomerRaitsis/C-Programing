/* Assignment: 3
Author: Tomer Raitsis
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define size 80
void rotate_left(char str1[]);
void rotate_right(char str1[]);
int intersection(char str1[], char str2[]);


void main() {
	char str1[size], str2[size];
	printf("Enter first string:"); // getting first string
	gets(str1);
	printf("Enter second string:"); // geting second string
	gets(str2);
	rotate_right(str1); // using rotate right 2 times
	rotate_right(str1);
	rotate_left(str2);  // using rotate left 3 times
	rotate_left(str2);
	rotate_left(str2);
	printf("First string after 2 rotations right: ");  // first srting after the function
	puts(str1);
	printf("Second string after 3 rotations left: ");  // second string after the function
	puts(str2);
	printf("Intersection of the last 2 strings: %d\n",intersection(str1, str2)); // printing the number of intersections
}


void rotate_left(char str1[]) {
	int i, j, length = 0;
	char first[size] = { 0 };  // a string for the first word
	char rest[size] = { 0 };  // a string for the rest of the sentence
	for (i = 0; i < size; i++) {// a loop to copy the first word to 'first' string
		if (str1[i] != ' ') { 
			length++;
			first[i] = str1[i];
		}
		if (str1[i] == ' ') {
			break;
		}
	}
	j = 0;
	for (i = length + 1 ; i < size; i++) { // a loop to copy the rest of the sentence to 'rest' string
		rest[j] = str1[i];
		j++;
	}
	strcpy(str1, rest);   // building the sentence 
	strcat(str1, " ");    // building the sentence
	strcat(str1, first);  // building the sentence
}

void rotate_right(char str1[]) {
	int i, j, length = 0, spacei;
	char last[size] = { 0 };  // a string for the last word
	char rest[size] = { 0 };  // a string for the rest of the sentence

	for (i = 0; i < size; i++) {
		if (str1[i] == ' ') { // a loop to find the first letter of the last word
			spacei = i;
		}
	}
	j = 0;
	for (i = spacei + 1; i < size; i++) { // a loop to copy the last word to 'last' string
		last[j] = str1[i];
		j++;
	}
	for (i = spacei, i >= 0; i--;) {  // a loop to copy the rest of the sentence to 'rest' string
		rest[i] = str1[i];
	}

	strcpy(str1, last);    // building the sentence 
	strcat(str1, " ");     // building the sentence 
	strcat(str1, rest);    // building the sentence 
}

int intersection(char str1[], char str2[]) {
	int i, j, len1, len2, index = 0;
	j = 0;
	len1 = strlen(str1); // geting the number of digits
	len2 = strlen(str2); // geting the number of digits
	if (len1 <= len2) {                // in case the first string is longer than the second
		for (i = 0; i < len1; i++) {  
			if (str2[j] == str1[i]) {  // checking if the digits are the same
				index++;
			}
			if (str2[j] == str1[i] + 32 && str1[i] + 32 >= 'a' && str1[i] + 32 <= 'z') {  // in case of letters, checking if they are the same ('A' == 'a')
				index++;
			}
			if (str2[j] == str1[i] - 32 && str1[i] - 32 >= 'A' && str1[i] - 32 <= 'Z') {  // in case of letters, checking if they are the same ('A' == 'a')
				index++;
			}
			j++;
		}
	}
	else {
		for (i = 0; i < len2; i++) {  // in case the second string is longer than the first
			if (str2[i] == str1[j]) {  // checking if the digits are the same
				index++;
			}
			if (str2[i] == str1[j] + 32 && str1[j] + 32 >= 'a' && str1[j] + 32 <= 'z') { // in case of letters, checking if they are the same ('A' == 'a')
				index++;
			}
			if (str2[i] == str1[j] - 32 && str1[j] - 32 >= 'A' && str1[j] - 32 <= 'Z') { // in case of letters, checking if they are the same ('A' == 'a')
				index++;
			}
			j++;
		}
	}
	return index;
}