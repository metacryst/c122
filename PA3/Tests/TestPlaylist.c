#include "TestPlaylist.h"

int testInsert() {
    Duration testSongLength = {4, 36};
    Record bogusTestRecord = {
        "Perry, Katy", 
        "Witness", 
        "Chained To The Rhythm", 
        "pop", 
        testSongLength, 
        -1, 
        6
    };
    
    int insertSuccess = insertFront(&bogusTestRecord);
    
    if(insertSuccess) {
        return 0;
    } else {
        return 1;
    }
}

int testDelete() {
    Duration testSongLength = {4, 36};
    Record recordToDelete = {
        "Perry, Katy", 
        "Witness", 
        "Chained To The Rhythm", 
        "pop", 
        testSongLength, 
        3, 
        5
    };
    
    int insertSuccess = insertFront(&recordToDelete);
    if(!insertSuccess) {
        printf("Insert failed\n");
        return 0;
    } 
    
    int deleteSuccess = deleteNode(pPlaylist->head);
    if(!deleteSuccess) {
        printf("Delete failed\n");
        return 0;
    }
    
    if(!(pPlaylist->head == NULL)) {
        printf("Head not null\n");
        return 0;
    }
    
    return 1;
}

int testShuffle() {
    Duration lengthOne = {4, 36};
    Record recordOne = {
        "Perry, Katy", 
        "Witness", 
        "Chained To The Rhythm", 
        "pop", 
        lengthOne, 
        3, 
        5
    };
    insertFront(&recordOne);
    
    Duration lengthTwo = {5, 24};
    Record recordTwo = {
        "West, Kanye", 
        "Donda", 
        "Come To Life", 
        "Rap", 
        lengthTwo, 
        27, 
        5
    };
    insertFront(&recordTwo);

    Duration lengthThree = {3, 12};
    Record recordThree = {
        "21 Savage", 
        "Savage Mode", 
        "No Heart", 
        "Rap", 
        lengthThree, 
        14, 
        3
    };
    insertFront(&recordThree);
    
    int songsToPlay[3] = {3, 1, 2};
    
    shufflePlay(songsToPlay);
    
    if(songsToPlay[0] || songsToPlay[1] || songsToPlay[2]) {
        printf("Not all songs Played!\n");
        return 0;
    }
    
    return 1;
}

int main() {
    List Playlist = {NULL};
    pPlaylist = &Playlist;
        
    int successes=0;
    int failures=0;
    
    printf("\nTesting Insert... ");
    testInsert() ? 
    printf("Success"), successes++ : printf("TEST FAILED"), failures++;
    clearList(pPlaylist);
    
    printf("\nTesting Delete... ");
    testDelete() ? 
    printf("Success"), successes++ : printf("TEST FAILED"), failures++;
    clearList(pPlaylist);
    
    printf("\nTesting Shuffle... ");
    testShuffle() ? 
    printf("Success"), successes++ : printf("TEST FAILED"), failures++;
    clearList(pPlaylist);
    
    printf("\n\n");
}