#include "contacts.h"

int main(int argc, char *argv[])
{
	List contactList = {NULL};
	Contact firstContact = {"Elle", "2189347427", "ebrns@gmail.com", ""};
	Contact secondContact = {"Emma", "2189347427", "unicorn@gmail.com", ""};
	Contact thirdContact = {"Bryan", "6289649427", "llamaContact@gmail.com", ""};
	
	initList(&contactList);
	insertFront(&contactList, &firstContact);
	insertFront(&contactList, &secondContact);
	insertFront(&contactList, &thirdContact);
	
	printf("~~~~ \n");
	printf("Insert Front (new head email): \n");
	printf("%s\n", contactList.headPointer->contact.email);
	
	printf("~~~~ \n");
	printf("Print List: \n");
	printList(&contactList);
	
	return 0;
}