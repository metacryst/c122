


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
    Node* next;
    Record data;
    Node* prev;
} Node;