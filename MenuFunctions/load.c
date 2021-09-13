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
    printf("%s\n", (*PlaylistPointer).head->data.artist);
    
    return 0;
}