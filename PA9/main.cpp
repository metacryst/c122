#include "Characters/Character.h"
#include "Blocks.h"
using namespace sf;


void mouseMoved(int x, int y) {
    cout << x << endl;
    cout << y << endl;
}

void playerTurn() {
    
}



int main()
{
    window.create(VideoMode(2000, 1300), "Blocks");   
    
    for(int i=0; i<4; i++) {
        playerCharacters[i] = new Character(100);
    }
    for(int i=0; i<4; i++) {
        enemyCharacters[i] = new Character(100);
    }
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) {
            switch(event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::MouseMoved:
                    mouseMoved(event.mouseMove.x, event.mouseMove.y);
                    break;
                default:
                    break;
            }
        }
        
        window.clear();
                
        for(int i=0; i<4; i++) {
            RectangleShape sprite = playerCharacters[i]->display(300 + (400 * i), 1000);
            window.draw(sprite);
            Text hpLabel = playerCharacters[i]->displayHP();
            window.draw(hpLabel);
        }
        
        for(int i=0; i<4; i++) {
            RectangleShape sprite = enemyCharacters[i]->display(300 + (400 * i), 100);
            window.draw(sprite);
            Text hpLabel = enemyCharacters[i]->displayHP();
            window.draw(hpLabel);
        }
        
    playerTurn();
                
        window.display();
    }
    

    return 0;
}