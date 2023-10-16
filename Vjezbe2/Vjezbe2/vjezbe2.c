#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE (50)


struct _PERSON;
typedef struct _PERSON* POSITION; // objansnjenje

typedef struct _PERSON
{
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int birthyear;
	POSITION NEXT;

}person;

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
int main() {

	person Head = { .name = {0},.surname = {0},.birthyear = 0; NEXT = NULL };
	Head.n = { 0 };





}