/* Assignment: 5
Author: Tomer Raitsis
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
	int DayNumber;
	int WorkHours;
} WorkDay;
typedef struct {
	long ID;
	int HourlySal;
	int workdays;
	WorkDay* wd;
	double salary;
} Worker;
void InputWorkDay(WorkDay* pWD);
void PrintWorkDay(WorkDay pWD);
void InputWorker(Worker* pW);
void PrintWorker(Worker w);
Worker* InitFactory(int* pSize);
void PrintFactory(Worker* pWorker, int size);
void  CalculateSalary(Worker* pWorker, int size);

int main() {
	Worker* pFactory = NULL;
	int size,i;
	pFactory = InitFactory(&size); // setting the factory
	CalculateSalary(pFactory, size); // calculating the salary of all the workers
	PrintFactory(pFactory, size); // printing all the data
	for (i = 0; i < size; i++) {
		free(pFactory[i].wd); // freeing the workdays(wd) arrays of every worker
	}
	free(pFactory); // freeing the array of the factory
		return 0;
}



void InputWorkDay(WorkDay* pWD) { 
	printf("day: ");
	scanf("%d", &pWD->DayNumber); // getting the number of the day from the user
	printf("hours: ");
	scanf("%d", &pWD->WorkHours);  // getting the amount of hours from the user
}

void PrintWorkDay(WorkDay pWD) {
	printf("Day %d: %d hours\n", pWD.DayNumber, pWD.WorkHours); // printing the day number and the amount of the hours 
}

void InputWorker(Worker* pW) {
	int i;
	printf("Enter ID: \n");
	scanf("%ld", &pW->ID);  // getting an id from the user
	printf("Enter Hourly Salary: \n");
	scanf("%d", &pW->HourlySal);    // getting the hourly salary from the user
	printf("Enter work days: \n");
	scanf("%d", &pW->workdays);    // getting the amount of workdays from the user
	pW->wd = (WorkDay*)malloc(pW->workdays * sizeof(WorkDay));  // setting the array with the amount of work days
	if (!pW->wd) {
		printf("Error! Can not allocate memory."); // checking if malloc worked
		return ;
	}
	for (i = 0; i < pW->workdays; i++) {
		InputWorkDay(&pW->wd[i]); // getting the workday data for every day of working
	}
}

void PrintWorker(Worker w) {
	int i;
	printf("ID: %ld\n", w.ID); // printing the id
	printf("Hourly Salary: %d\n", w.HourlySal);  // printing the hourly salary
	printf("%d workdays \n", w.workdays);  // printing the workdays
	for (i = 0; i < w.workdays; i++) {
		PrintWorkDay(w.wd[i]); //printing the workday data for every day of working
	}
	printf("Salary: %lf\n", w.salary); // printing the salary
}

Worker* InitFactory(int* pSize){
	Worker* W = NULL;
	int i, size;
	printf("Enter the number of workers: ");
	scanf("%d", pSize ); // getting the amount of workers
	W = (Worker*)malloc(*pSize * sizeof(Worker));  // setting the array with the amount of workers
	if (!W) {
		printf("Error! Can not allocate memory."); // checking if malloc worked
		return;
	}
	for (i = 0; i < *pSize; i++) {
		InputWorker(&W[i]); // getting the data of every worker
	}
	return W; // returning the array with all the workers data
}

void PrintFactory(Worker* pWorker, int size) {
	int i;
	for (i = 0; i < size; i++) {
		PrintWorker(pWorker[i]); // printing the data of every worker 
	}
}

void  CalculateSalary(Worker* pWorker, int size) {
	int i, j;
	double salary ;
	for ( i = 0; i < size; i++) // a loop that goes over all the workers
	{
		salary = 0; // zeroing the salary for every new worker
		for ( j = 0; j < pWorker[i].workdays; j++) // a loop the goes over all the workdays of one worker
		{
			salary = salary + pWorker[i].HourlySal * pWorker[i].wd[j].WorkHours; // suming all the salarys per a day of the same worker
		}
		pWorker[i].salary = salary; // updating the salary in the struct
		
	}
}