#include <SFML/Graphics.hpp>
using namespace sf;

class Blocks {
    RenderWindow window;   
    Font font;
    Text AttackPrompt;
    Character* playerCharacters[4];
    Character* enemyCharacters[4];

public:
    int playerClickedIndex;
    bool showAttackPrompt;

    Blocks() {
        playerClickedIndex=-1;
        font.loadFromFile("RobotoMono.ttf");
        AttackPrompt.setFont(font);
        AttackPrompt.setString("Click an enemy to attack!");
        AttackPrompt.setPosition(Vector2f(800, 800));
        
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
    bool playerClicked(int p);
    void mouseMoved(int x, int y);
};
