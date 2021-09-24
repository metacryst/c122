#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

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
int listLength;




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
void shufflePlay(int* songsToPlay);

void printRecord(Node* node);
void printPlayingRecord(Node* node);
int printList();

int insertFront(const Record* recordPointer);
int deleteNode();
void clearList();

int printArtistSearch(char* artist);
Node* songSearch(int songNumber);
Node* songTitleSearch(char* songTitle);
