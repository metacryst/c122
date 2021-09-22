#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
void insert();
void delete();
void edit();
void sort();
void rate();
void play();
void shuffle();

int countNodes();
int insertFront(const Record* recordPointer);
void printRecord(Node* node);
int printList();
int deleteNode();
void clearList();
int printArtistSearch(char* artist);
Node* songSearch(int songNumber);
Node* songTitleSearch(char* songTitle);
