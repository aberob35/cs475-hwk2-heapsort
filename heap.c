/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"
/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	// TODO - BuildHeap on the heap
	buildHeap(A, n);
	// TODO - while n > 0:
	while(n > 0){
	// TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
		swap(&A[n-1], &A[0]);
	// TODO - A[n-1] now sorted in place, so decrement n
		n--;
		for(int i = 0; i < n; i++){
		heapify(&A[0], n - 1, MAX_EMPLOYEES);
	}
	}
	// TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
	
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	// TODO - heapify() every element from A[n/2] down-to A[0]
	int start = (n/2) - 1;
	for(int i = start; i >= 0; i--){
		heapify(A, i, n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	int smallest = i;
	// TODO - get index of left child of element i
	int left = i;
	// TODO - get index of right child of element i
	int right = i + 1;
	// TODO - determine which child has a smaller salary. We'll call the index of this
	//		element: "smaller"
	// TODO - recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//			Then recursively heapify A[smaller].
	if(left < n &&  A[left].salary < A[smallest].salary){
		smallest = left; 
	} 
	if(right < n && A[right].salary < A[smallest].salary){
		smallest = right; 
	}
	 if(smallest != i){
		swap(&A[i], &A[smallest]);
		heapify(A, smallest, n);
	}
	
	// TODO - Continue recursion as long as i is within range AND either right_child and left_child are still within range.
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	// TODO
	Employee temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
//Printing greatest to least going down. Greatest to Least sideways looked weird to me.
void printList(Employee *A, int n)
{
	// TODO
	for(int i = 4; i >=0 ; i--){
		printf("[id = %s sal = %d]\n", A[i].name, A[i].salary);
	}
}
void unsortPrint(Employee *A, int n){
	for(int i = 4; i >=0 ; i--){
		printf("Name: %s \n Salary: %d \n", A[i].name, A[i].salary);
	}
}
