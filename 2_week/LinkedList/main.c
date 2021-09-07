#include "LinkedList.h"



int main(int argc, char *argv[]) {
    List movieCollection = {NULL};
    Data d1 = {"Fight Club", 1999};
    int success = 0;
    
    initList(&movieCollection);
    
    success = insertFront(&movieCollection, &d1);
    
    printf("Data: Title: %s, Year: %d\n",
        movieCollection.pHead->movie.movieTitle, 
        movieCollection.phead->movie.year)
    
    return 0;
}
