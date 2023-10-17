#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

Position createPerson();
int addPersonToFront();

int main() {

	person Head;
	Head.name = { 0 };
	Head.surname = { 0 };
	Head.birthyear = 0;
	Head.next = NULL;

	return 0;
}


Position createPerson() {
	Position newPerson = NULL;
	char name[MAX_SIZE] = { 0 };
	char surname[MAX_SIZE] = { 0 };
	int birthyear = 0;

	newPerson = (Position)malloc(sizeof(person));

	if (newperson == NULL) {
		printf("Failure creating newPerson");
	}

	printf("\nEnter students name: ");
	scanf("%s", name);

	printf("\nEnter students surname: ");
	scanf("%s", surname);

	printf("\nEnter students year of birth: ");
	printf("%d", &birthyear);

	strcpy(newperson->name, name);
	strcpy(newperson->surname, surname);
	newperson->birthyear = birthyear;

	return newPerson;
}

int addPersonToFront(Position P) {

	Position newPerson = NULL;
	newPerson = createPerson();
	if (newPerson) {
		newPerson->next = head->next;
		head->next = newPerson;
		return EXIT_SUCCESS;

	}



	return 0;
}

/*
funkcija addtofront(position head)(pointer na prvu strukturu u listi){
	position newperson=null;
	new person= createperson();
	if(newperson){
		newperson->next=head->next;
		head->next=newperson;
		return exit success;

		DZ prvi zadatak i dodavanje na pocetak liste drugi zadatak

*/


/*funkcijazastvaranjenovog clana
POSITION createPerson(){
	POSITION newPerson= NULL;
	char name[50]=0;
	char surname[50]0;
	int birthyear=0;

	newPerson=(POSITION)malloc(sizeof(person));
	provjeriti da li smo allocirali!
	printf("unesi ime");
	scanf("%s",name);
	isto za prezime i godine

	newperson.ime=ime[0] nece funkcionirati, koristiti strcpy
	strcpy(newperson->ime(nacin kako doc od pokazivaca do vrijednosti unutar strukture),ime);
	isto za prezime
	newperson->birthyear=birthyear;
	return NEWPERSON;
*/