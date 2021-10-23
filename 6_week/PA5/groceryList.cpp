#include "Shopping.h"

groceryList::groceryList(int express) {
        first = nullptr;
        last = nullptr;
        
        int numberItems;
        if (express) {
            numberItems = (rand() % 5 + 1);
        }
        else {
            numberItems = (rand() % (8 - 3 + 1) + 3);
        }
        count = numberItems;
        addToList(numberItems);
}

groceryList::~groceryList() {
    Grocery* item = first;
    Grocery* nextItem;
    while (item) {
        nextItem = item->next;
        delete(item);
        item = nextItem;
    }
}

void groceryList::addToList(int numberItems) {
    int itemsAdded = 0;
    string allGroceries[8] = { "eggs", "bananas", "cream", "yogurt", "ice cream", "ribeye", "salmon", "chopsticks"};
    for (int i=1; i <= numberItems; i++) {
        Grocery* newItem = new Grocery(allGroceries[itemsAdded]);
        if (itemsAdded == 0) {
            first = newItem;
            last = newItem;
        }
        else {
            last->next = newItem;
            last = newItem;
        }

        itemsAdded++;
    }
}