#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "student.h"


int writeStudentToBFile(FILE* fp, Student* st)
{

	return 0;
}

int readStudentFromBFile(FILE* fp, Student* st)
{

	return 0;
}

int writeStudentArrToBFile(const char* fileName, Student* stArr, int count)
{
	
	return 0;
}


void addStudentToEndOfFile(const char* fileName)
{
	

}


Student* readStudentArrFromBFile(const char* fileName, int* pCount)
{
	Student* arr=NULL;
	FILE* fp = fopen(fileName, "rb");
	if (!fp)
		return NULL;







	fclose(fp);
	return arr;

}

void showStudent(Student* st)
{

	printf("%s   %d  %.2f\n", st->name, st->id, st->avg);

}

void showStudentArr(Student* st, int count)
{
	int i;
	for (i = 0; i < count; i++)
		showStudent(&st[i]);
}

void freeStudentArr(Student* st, int count)
{
	

}


void initStudent(Student* st)
{
	printf("Please enter student id, avg and name\n");
	scanf("%d %f %s", &st->id, &st->avg, st->name);


}