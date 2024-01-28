#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE (128)
#define MAX_LINE (1024)
#define FILE_NOT_OPEN (-1)

typedef struct _student
{
    char name[MAX_SIZE];
    char surname[MAX_SIZE];
    double points;
} Student;

int readNoRowsInFile();
Student* allocateMemoryAndReadStudents(int noStudents);
int showStudents(int noStudents, Student* students);

int main() {

    int noRows = 0;
    Student* students = NULL;
    noRows = readNoRowsInFile();

    printf("%d", noRows);

    if (noRows > 0)
    {
        students = allocateMemoryAndReadStudents(noRows);
        showStudents(noRows, students);

        free(students);
    }

    return 0;
}

int readNoRowsInFile()
{
    int counter = 0;
    FILE* filePointer = NULL;
    char buffer[MAX_LINE] = { 0 };

    filePointer = fopen("students.txt", "r");
    if (!filePointer)
    {
        printf("File failed to open\n");
        return FILE_NOT_OPEN;
    }
    while (fgets(buffer, MAX_LINE, filePointer) != NULL)
    {
        counter++;
    }
    fclose(filePointer);

    return counter;
}

Student* allocateMemoryAndReadStudents(int noStudents)
{
    int counter = 0;
    FILE* filePointer = NULL;
    Student* students = NULL;

    students = (Student*)malloc(noStudents * sizeof(Student));
    if (!students)
    {
        printf("Neuspjesna alokacija memorije!\n");
        return NULL;
    }
    filePointer = fopen("students.txt", "r");
    if (!filePointer)
    {
        printf("File failed to open\n");
        return FILE_NOT_OPEN;
    }
    while (fscanf(filePointer, "%s %s %lf", students[counter].name, students[counter].surname, &students[counter].points) == 3)
    {
        counter++;
    }
    fclose(filePointer);

    return students;
}

int showStudents(int noStudents, Student* students)
{
    int counter = 0;
    for (counter = 0; counter < noStudents; counter++)
    {
        double maxPoints = 15.0; // Assuming the maximum points is 15 as per your example
        double relativePoints = (students[counter].points / maxPoints) * 100;

        printf("\n%s %s %.2lf %.2lf", students[counter].name, students[counter].surname, students[counter].points, relativePoints);
    }
}
