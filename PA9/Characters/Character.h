#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;



class Character {
protected:
	sf::RectangleShape sprite; //this can be whatever we want i guess, but its a square for now
	
	int hp;
	int hpMax;

public:
	Character(int StartHP) {
		hpMax = StartHP;
		hp = StartHP;

	
		sprite.setSize(sf::Vector2f(200, 200));
		sprite.setFillColor(sf::Color::Red);
	}
	sf::RectangleShape display(int x, int y);
};
