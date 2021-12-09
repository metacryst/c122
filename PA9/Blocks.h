#include <SFML/Graphics.hpp>
using namespace sf;

class Blocks {
    RenderWindow window;   
    Character* playerCharacters[4];
    Character* enemyCharacters[4];

public:
    Blocks() {
        for(int i=0; i<4; i++) {
            playerCharacters[i] = new Character(100);
        }
        for(int i=0; i<4; i++) {
            enemyCharacters[i] = new Character(100);
        }
    }
    
    void runApp();
    void displayWindow();
    void playerTurn();
    void mouseMoved(int x, int y);
};
