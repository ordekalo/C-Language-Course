#ifndef __STUDENT__
#define __STUDENT__

#include <stdio.h>

typedef struct
{
	char	name[10];
	int		id;
	float	avg;
}Student;

int writeStudentToBFile(FILE* fp, Student* st);
int readStudentFromBFile(FILE* fp, Student* st);
int writeStudentArrToBFile(const char* fileName, Student* st, int count);
void addStudentToEndOfFile(const char* fileName);


void showStudent(Student* st);
void initStudent(Student* st);
Student* readStudentArrFromBFile(const char* fileName, int* pCount);
void showStudentArr(Student* st,int count);
void freeStudentArr(Student* st, int count);


#endif