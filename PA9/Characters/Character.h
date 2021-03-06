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
	sf::Font font;
	
	bool alive;
	
	int hp;
	int hpMax;
	int crit;
	double damageModifier;

public:
	sf::RectangleShape sprite;
	sf::Text hpLabel;
	sf::Texture AttackIcon;
	sf::Sprite AttackButton;
   
	
	Character(int StartHP) {
		hpMax = StartHP;
		hp = StartHP;
		damageModifier = 0;
		crit = 20;
		
		AttackIcon.loadFromFile("Attack.png");
		AttackButton.setTexture(AttackIcon);
		
		font.loadFromFile("RobotoMono.ttf");
		hpLabel.setFont(font);
		hpLabel.setString(to_string(StartHP));
	
		sprite.setSize(sf::Vector2f(200, 200));
		sprite.setFillColor(sf::Color::Red);
	}
	sf::RectangleShape display(int x, int y);
	sf::Text displayHP();
	void BaseAttack(Character* target);
	sf::Sprite showAttacks();
	void whatHappened(int damageNum);
	void hover();
	void removeHover();
};
