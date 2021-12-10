#include "Characters/Character.h"
#include "Blocks.h"

void Blocks::displayWindow() {
    window.clear();
                
    for(int i=0; i<4; i++) {
        RectangleShape sprite = playerCharacters[i]->display(300 + (400 * i), 1000);
        window.draw(sprite);
        
        if(playerClickedIndex!=-1) {
            cout << "display attack" << endl;
            cout << playerClickedIndex << endl;
           
            Sprite attackButton = playerCharacters[playerClickedIndex]->showAttacks();
            window.draw(attackButton);
        }
        cout << "display" << endl;
        
        Text hpLabel = playerCharacters[i]->displayHP();
        window.draw(hpLabel);
    }
    
    
    for(int i=0; i<4; i++) {
        RectangleShape sprite = enemyCharacters[i]->display(300 + (400 * i), 100);
        window.draw(sprite);
        Text hpLabel = enemyCharacters[i]->displayHP();
        window.draw(hpLabel);
    }
            
    window.display();
}

bool Blocks::playerClicked(int p) {
    cout << "Player clicked" << endl;
    playerClickedIndex=p;
    displayWindow();
    return false;
}

void Blocks::playerTurn() {
    bool usedAttack[] = {false, false, false, false};
    Event event;
    
    int hovered=-1;

    while(!usedAttack[0] && !usedAttack[1] && !usedAttack[2] && !usedAttack[3]) {
        Vector2i pos = Mouse::getPosition(window);  
        
        if((pos.x >= 300 && pos.x <= 500) && (pos.y >= 1000 && pos.y <= 1200)) {
            hovered=0;
            playerCharacters[0]->hover();
            displayWindow();
            if (window.waitEvent(event)) {
                switch (event.type) {
                    case sf::Event::MouseButtonPressed:
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            usedAttack[0] = playerClicked(0);
                        }
                        break;
                    default:
                        break;
                }
            }
        } else if((pos.x >= 700 && pos.x <= 900) && (pos.y >= 1000 && pos.y <= 1200)) {
            hovered=1;
            playerCharacters[1]->hover();
            displayWindow();
        } else if((pos.x >= 1100 && pos.x <= 1300) && (pos.y >= 1000 && pos.y <= 1200)) {
            hovered=2;
            playerCharacters[2]->hover();
            displayWindow();
        } else if((pos.x >= 1500 && pos.x <= 1700) && (pos.y >= 1000 && pos.y <= 1200)) {
            hovered=3;
            playerCharacters[3]->hover();
            displayWindow();
        } else {
            if(hovered!=-1) {
                playerCharacters[hovered]->removeHover();
                displayWindow();
            }
            hovered=-1;
        }
        
    }
}

void Blocks::runApp() {
    window.create(VideoMode(2000, 1300), "Blocks");   
    
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            cout << "Event Loop" << endl;
            switch(event.type) {
                case Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
        
        displayWindow();
        
        playerTurn();
        
    }
}

int main()
{
    Blocks* app = new Blocks;
    app->runApp();
    return 0;
}