#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int position;
    struct node* next;
    Record data;
    struct node* prev;
} Node;

typedef struct list
{
	Node* head;
} List;

List* pPlaylist;

int load();
int store();
void display();
void edit();

int insertFront(const Record* recordPointer);
void printList();
void clearList();
int printArtistSearch(char* artist);
void printSongSearch(int songNumber);
