#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_SIZE (50)

struct _Person;
typedef struct _Person* Position;

typedef struct _Person
{
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int birthYear;
	Position next;

}person;

int menu(Position Head,Position Head2);
Position createPerson();
int addPerson(Position P, char* name, char* surname, int birthYear);
int addPersonToFront(Position P);
int printAll(Position P);
int addPersonToBack(Position P);
Position findPerson(Position P);
int removePerson(Position P);
int addBehindTarget(Position P);
int addInFrontOfTarget(Position P);
int writeListInFile(Position P);
int readListFromFile(Position P);

int main() {

	person Head;
	person Head2;

	Head.next = NULL;
	Head2.next = NULL;
	
	menu(&Head,&Head2);

	return 0;
}

int menu(Position Head,Position Head2) 
{
	int flag = 1;

	while (flag)
	{
		printf("------------------------------------------");
		
		printf("\n1-add new person in front of the list");
		printf("\n2-print out the list");
		printf("\n3-add new person to the end of the list");
		printf("\n4-find a person by surname");
		printf("\n5-remove a person from the list");
		printf("\n6-add new person in front of the specific target");
		printf("\n7-add new person after the specific target");
		printf("\n8-sort the list by surname(WIP)");
		printf("\n9-write list in file");
		printf("\n10-read list from file");
		printf("\n0-exit the program");
		printf("\n------------------------------------------");
		printf("\nChoose an action: ");
		scanf("%d", &flag);

		switch(flag)
			{
		case 1: addPersonToFront(Head); break;
			case 2: printAll(Head->next); break;
			case 3: addPersonToBack(Head); break;
			case 4: findPerson(Head->next); break;
			case 5: removePerson(Head); break;
			case 6: addInFrontOfTarget(Head); break;
			case 7: addBehindTarget(Head); break;
			case 8: break;
			case 9: writeListInFile(Head->next); break;
			case 10: readListFromFile(Head2); break;
			}

	}
	return EXIT_SUCCESS;
}
int addPerson(Position P, char* name, char* surname, int birthYear) 
{
	Position q = NULL;
	q = (Position)malloc(sizeof(person));
	strcpy(q->name, name);
	strcpy(q->surname, surname);
	q->birthYear = birthYear;
	
	if (q == NULL)
		return EXIT_FAILURE;
	
	while (P->next != NULL)
		P = P->next;

	q->next = P->next;
	P->next = q;

	return EXIT_SUCCESS;

}


int readListFromFile(Position P) 
{
	FILE* fp = NULL;
	char name[MAX_SIZE] = "";
	char surname[MAX_SIZE] = "";
	int birthYear = 0;
	fp = fopen("PersonList.txt", "r");
	if (fp == NULL) {
		printf("\nFile not opened");
		return EXIT_FAILURE;
	}
	while (!feof(fp)) {

		fscanf(fp, "%s %s %d", name, surname, &birthYear);
		addPerson(P, name, surname, birthYear);
	}
	printAll(P->next);
	fclose(fp);
	return EXIT_SUCCESS;
}
int writeListInFile(Position P) 
{
	FILE* fp=NULL;
	fp = fopen("PersonList.txt", "w");

	if (fp == NULL) {
		printf("\nFile not opened");
		return EXIT_FAILURE;
	}
	if (P == NULL) {
		printf("\nList is empty");
		return EXIT_FAILURE;
	}
	while (P != NULL) {
		fprintf(fp, "\n%s %s %d", P->name, P->surname, P->birthYear);
	
		P = P->next;
	}

	fclose(fp);

	return EXIT_SUCCESS;
}
int addInFrontOfTarget(Position P) 
{
	char prez[MAX_SIZE];
	printf("\nIn front of which surname would you like to add new person? ");
	scanf("%s", &prez);

	while (P->next != NULL && strcmp(P->next->surname, prez) != 0) {
		P = P->next;
	}
	if (P->next == NULL) {
		printf("\nInserted surname not found");
		return EXIT_FAILURE;
	}
	
	Position q = createPerson();
	q->next = P->next;
	P->next = q;
	return EXIT_SUCCESS;
}


int addBehindTarget(Position P) 
{
	char prez[MAX_SIZE];
	printf("\nAfter which surname would you like to add new person?: ");
	scanf("%s", &prez);

	while (P->next != NULL && strcmp(P->next -> surname, prez) != 0) {
		P = P->next;
	}
	if (P->next == NULL) {
		printf("\nInserted surname not found");
		return EXIT_FAILURE;
	}
	P = P->next;
	Position q = createPerson();
	q->next = P->next;
	P->next = q;
	return EXIT_SUCCESS;
}
Position createPerson() 
{
	Position newPerson = NULL;
	char name[MAX_SIZE] = { 0 };
	char surname[MAX_SIZE] = { 0 };
	int birthyear = 0;

	newPerson = (Position)malloc(sizeof(person));

	if (newPerson == NULL) {
		printf("Failure creating newPerson");
	}

	printf("\nEnter students name: ");
	scanf("%s", name);

	printf("\nEnter students surname: ");
	scanf("%s", surname);

	printf("\nEnter students year of birth: ");
	scanf("%d", &birthyear);

	strcpy(newPerson->name, name);
	strcpy(newPerson->surname, surname);
	newPerson->birthYear = birthyear;

	return newPerson;
}

int removePerson(Position P) 
{
	Position q = NULL;
	char prez[MAX_SIZE];
	printf("Which person do you want to remove(enter surname)? ");
	scanf("%s", &prez);
	
	while (P->next!=NULL && strcmp(P->next->surname, prez) != 0)
	{
		P = P->next;

	}

	if (P->next == NULL) {
		printf("\nEntered surname not found");
		return EXIT_FAILURE;
	}
	
	q = P->next;
	P->next = P->next->next;
	free(q);
	return EXIT_SUCCESS;
	
}

Position findPerson(Position P) 
{

	char prez[MAX_SIZE];
	printf("\nEnter the surname: ");
	scanf("%s", &prez);



	while (strcmp(P->surname, prez)!=0){
		P = P->next;
	}

	if (strcmp(P->surname, prez))
	{
		return NULL;
	}
	else
	{
		printf("\nEntered surname has been found");
		return P;

	}
}
int addPersonToFront(Position P) 
{

	Position newPerson = NULL;
	newPerson = createPerson();
	if (newPerson) {
		newPerson->next = P->next;
		P->next = newPerson;
		return EXIT_SUCCESS;

	}

	return EXIT_FAILURE;


}
int addPersonToBack(Position P) 
{

	Position newPerson = NULL;
	newPerson = createPerson();
	if (newPerson) {
		while (P->next != NULL) {
			P = P->next;
		}
		newPerson->next = P->next;
		P->next = newPerson;
		
		return EXIT_SUCCESS;

	}

	return EXIT_FAILURE;


}

int printAll(Position P) 
{

	printf("\n--------\n");
	while (P != NULL) {
		printf("\n - %d\n", P->birthYear);
		P = P->next;
	}

	return 0;
}


