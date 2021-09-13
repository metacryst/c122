#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct duration {
    int minutes;
    int seconds;
} Duration;

typedef struct record {
    char artist[150];
    char albumTitle[150];
    char songTitle[150];
    char genre[20];
    Duration songLength;
    unsigned int timesPlayed;
    unsigned int rating;
} Record;

typedef struct node {
    struct node* next;
    Record data;
    struct node* prev;
} Node;

typedef struct list
{
	Node* head;
} List;

List* PlaylistPointer;

int load();

int insertFront(const Record* recordPointer);