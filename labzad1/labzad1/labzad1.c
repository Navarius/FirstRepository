#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_SIZE (128)
#define MAX_LINE (1024)
#define EXIT_SUCCESS (0)
#define FILE_NOT_OPENED (-1)


typedef struct _STUDENT {
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	double points;
}student;


int readFile() {
	FILE *f;
	f = fopen("students.txt", "r");
	fgets()

}


int main() {

	student s














	return EXIT_SUCCESS;
}