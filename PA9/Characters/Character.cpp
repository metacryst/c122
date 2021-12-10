#include "Character.h"


sf::RectangleShape Character::display(int x, int y)
{
	sprite.setPosition(sf::Vector2f(x, y));
	return sprite;
}

sf::Text Character::displayHP()
{
	sf::Vector2f spritePos = sprite.getPosition();
	hpLabel.setPosition(sf::Vector2f(spritePos.x+75, spritePos.y+75));
	return hpLabel;
}

void Character::hover()
{
	sprite.setFillColor(sf::Color::White);
	hpLabel.setFillColor(sf::Color::Black);
}

void Character::removeHover()
{
	sprite.setFillColor(sf::Color::Red);
	hpLabel.setFillColor(sf::Color::White);
}

sf::Sprite Character::showAttacks() {
	AttackButton.setScale(sf::Vector2f(0.05f, 0.05f));
	sf::Vector2f spritePos = sprite.getPosition();
	AttackButton.setPosition(sf::Vector2f(spritePos.x, spritePos.y-100));
	return AttackButton;
}

void Character::BaseAttack(Character* target) //what a base attack function will look like
{
	int critroll = rand() % 100;
	if (critroll <= crit)
	{
		target->whatHappened(15 * 2);
	}
	else
	{
		target->whatHappened(15);
	}
}

void Character::whatHappened(int damageNum)
{
	hp -= (damageNum * (1 + damageModifier));
	if (hp <= 0)
	{
		hp = 0;
		alive = false;
	}
	hpLabel.setString(to_string(hp));
}