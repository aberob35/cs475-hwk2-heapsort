#include <stdio.h>
#include "employee.h"
#include "heap.h"
#include <string.h>
int main(int argc, char *argv[])
{
	//TODO - while loop to fill in all 5 names and salaries
	printf("Input 5 Employees with the corresponding salary \n");
	printf("Example input can be EMPLOYEE SALARY or \nEMPLOYEE \nSALARY \n");

	Employee buildHeapArray[10];
	char names[10];
	int whileCond = 0;
	int userSalary = 0;
	while(whileCond < MAX_EMPLOYEES){
		scanf("%s", names);
		strcpy(buildHeapArray[whileCond].name, names);
		scanf("%d", &userSalary);
		buildHeapArray[whileCond].salary = userSalary;
		whileCond++;
	}
	// print the array (unsorted)
	printf("\nList of Employees and salary before sort\n");
	//printList(buildHeapArray,MAX_EMPLOYEES);
	unsortPrint(buildHeapArray,MAX_EMPLOYEES);
	//Sort using Heap Sort Algorithm
	heapSort(buildHeapArray, MAX_EMPLOYEES);
	// print the array (sorted)
	printf("\n Employees salary from greatest to least \n");
	printList(buildHeapArray,MAX_EMPLOYEES);

	return 0;
}
