#include "Character.h"


sf::RectangleShape Character::display(int x, int y)
{
	sprite.setPosition(sf::Vector2f(x, y));
	return sprite;
}

sf::Text Character::displayHP()
{
	sf::Vector2f spritePos = sprite.getPosition();
	hpLabel.setPosition(sf::Vector2f(spritePos.x+50, spritePos.y+50));
	hpLabel.setFillColor(sf::Color::Blue); // need to get font
	return hpLabel;
}