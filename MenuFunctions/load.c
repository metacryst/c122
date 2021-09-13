#include "../Playlist.h"

int load() {
    printf("loading!\n");
    
    Duration firstDuration = {3, 4};
    Record firstRecord = {
        "Kanye West", 
        "Donda", 
        "Heaven and Hell", 
        "Rap", 
        firstDuration};
    
    insertFront(&firstRecord);
    
    printf("%s\n", (*pPlaylist).head->data.artist);
    
    return 0;
}