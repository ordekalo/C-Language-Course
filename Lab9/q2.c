#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "q2.h"

#define NAME 0
#define ID 1
#define AVG 2

void Q2()
{
	printf("\n----------- Base list ---------------\n");
	readArrShowFree();

	printf("\n----------- sort Name list ---------------\n");

	Q_SortStudents(NAME);
	readArrShowFree();
	Q_BinarySearch(NAME);
	
	Q_AddStudentToFile();
	
	printf("\n----------- sort id list ---------------\n");

	Q_SortStudents(ID);
	readArrShowFree();
	Q_BinarySearch(ID);

	printf("\n----------- sort avg list ---------------\n");

	Q_SortStudents(AVG);
	readArrShowFree();
	Q_BinarySearch(AVG);
}

void Q_MaxStudent()
{
	


}

void Q_SortStudents(int sortType)
{
	
}

void Q_BinarySearch(int sortType)
{
	
}


void Q_AddStudentToFile()
{
	printf("\n----------- Q_AddStudentToFile  -------------\n");

	addStudentToEndOfFile(FILE_NAME);
}

void readArrShowFree()
{
	Student* arr;
	int count;

	arr = readStudentArrFromBFile(FILE_NAME, &count);
	if (!arr)
	{
		printf("Error reading file\n");
		return;
	}

	showStudentArr(arr, count);
	freeStudentArr(arr, count);
}