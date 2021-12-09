#pragma once
#include "Character.h"

class Physical : public Character
{
public:
	Physical(int startHP) : Character(startHP, 20, "Physical")
	{
		baseDamage = 15;
		SpecialDamage = 40;
		sprite.setFillColor(sf::Color::Cyan); // this hopefully happens after character constructor and overwrites default red
		sprite.setSize(sf::Vector2f(0, 0)); //zeros are placeholder for UI to figure out
		xp = 0;
		xpMax = 100;
		level = 1;
	}
	void BaseAttack(Character* target);
	void SpecialAttack(Character* target); //just a bigger attack
	bool islevelup();
	void AwardXP(int num);
	void Upgrade(int num);
	sf::RectangleShape display(int index);
	sf::Text UpdateSheet(int index);

private:
	int baseDamage;
	int SpecialDamage;
	int level;
	bool levelup;
	bool passive; //bleeds on attack
};

class Tank : public Character
{
public:
	Tank(int startHP) : Character(startHP, 20, "Tank")
	{
		baseDamage = 15;
		sprite.setFillColor(sf::Color::Blue); // this hopefully happens after character constructor and overwrites default red
		sprite.setSize(sf::Vector2f(0, 0)); //zeros are placeholder for UI to figure out
		xp = 0;
		xpMax = 130;
		dmgTaken = -.20; //20% reduction in damage
		level = 1;
	}
	void BaseAttack(Character* target);
	void SpecialAttack(Character* target1, Character* target2, Character* target3, Character* target4); // a taunt that affects all enemies
	bool islevelup();
	void AwardXP(int num);
	void Upgrade(int num);
	sf::RectangleShape display(int index);
	sf::Text UpdateSheet(int index);

private:
	int baseDamage;
	int SpecialDamage;
	int level;
	bool levelup;
	bool passive; //just more max hp
};


class Magic : public Character
{
public:
	Magic(int startHP) : Character(startHP, 20, "Magic")
	{
		baseDamage = 20;
		SpecialDamage = 8;
		sprite.setFillColor(sf::Color::Magenta); // this hopefully happens after character constructor and overwrites default red
		sprite.setSize(sf::Vector2f(0, 0)); //zeros are placeholder for UI to figure out
		xp = 0;
		xpMax = 80;
		level = 1;
	}
	void BaseAttack(Character* target);
	void SpecialAttack(Character* target1, Character* target2, Character* target3, Character* target4); //8 damage attack targeting all enemies
	void SpecialAttack(Character* target);
	bool islevelup();
	void AwardXP(int num);
	void Upgrade(int num);
	sf::RectangleShape display(int index);
	sf::Text UpdateSheet(int index);
private:
	int baseDamage;
	int SpecialDamage;
	int level;
	bool levelup;
	bool passive; // special ability consolidates into a bigger attack when single target
};

class Healer : public Character
{
public:
	Healer(int startHP) : Character(startHP, 20, "Healer")
	{
		baseDamage = 20;
		SpecialDamage = -30; //in theory when passed this should add to HP
		sprite.setFillColor(sf::Color::Green); // this hopefully happens after character constructor and overwrites default red
		sprite.setSize(sf::Vector2f(0, 0)); //zeros are placeholder for UI to figure out
		xp = 0;
		xpMax = 200; //we had discussed possibly having different xp needs
	}
	void BaseAttack(Character* target);
	void SpecialAttack(Character* target); //single target heal
	bool islevelup();
	void AwardXP(int num);
	void Upgrade(int num);
	sf::RectangleShape display(int index);
	sf::Text UpdateSheet(int index);
private:
	int baseDamage;
	int SpecialDamage;
	int level;
	bool levelup;
	bool passive; //more base attack damage, heal now heals full HP
};
 
