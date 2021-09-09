/*
	This example illustrates how to implement a singly linked
	list in C.

	History: 9/3 - Implemented makeNode (), insertFront (),
	               and started discussing insertOrder ().
			 9/1 - Defined the required structs for the example
			       including struct Data, Node, and List. We
				   also implemented initList ()
*/

#include "LinkedList.h"

int main(int argc, char *argv[])
{
	List movieCollection = {NULL};
	Data d1 = {"Fight Club", 1999};
	int success = 0;

	initList(&movieCollection);

	success = insertFront(&movieCollection, &d1);
	printf("Data: Title: %s, Year: %d\n",
		movieCollection.pHead->movie.movieTitle,
		movieCollection.pHead->movie.year);

	return 0;
}