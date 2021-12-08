#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using std::string;
using std::to_string;
using std::cout;
using std::endl;
using std::cin;



class Character {
protected:
	sf::RectangleShape sprite; //this can be whatever we want i guess, but its a square for now
	sf::Text hpLabel;
	
	int hp;
	int hpMax;

public:
	Character(int StartHP) {
		hpMax = StartHP;
		hp = StartHP;
		
		hpLabel.setString(to_string(StartHP));
		cout << hpLabel << endl;
	
		sprite.setSize(sf::Vector2f(200, 200));
		sprite.setFillColor(sf::Color::Red);
	}
	sf::RectangleShape display(int x, int y);
	sf::Text displayHP();
};
