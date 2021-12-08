#include "Character.h"


sf::RectangleShape Character::display(int x, int y)
{
	sprite.setPosition(sf::Vector2f(x, y));
	return sprite;
}