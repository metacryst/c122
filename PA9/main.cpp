#include <SFML/Graphics.hpp>
#include "Characters/Character.h"
using namespace sf;


int main()
{
    RenderWindow window(VideoMode(2000, 1300), "Blocks");   
    Character* playerCharacters[4] = {new Character(100), new Character(100), new Character(100), new Character(100)};
    Character* enemyCharacters[4] = {new Character(100), new Character(100), new Character(100), new Character(100)}; 
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
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
        
        
        window.display();
    }

    return 0;
}