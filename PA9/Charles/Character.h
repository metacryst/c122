#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;



class Character
{
public:

	Character(int StartHP, int StartCrit, string cName); //not much setup needed for base class
	~Character();
	sf:: RectangleShape display(int index); //put the sprite at a fixed position based on index in array, Boss special case
	// returning the shape here for active drawing its pretty cool.
	virtual void BaseAttack(Character* target); //what a base attack function will look like
	virtual void specialAbility(Character* target);
	bool turnStatus(); //false if turn is skipped, check for dmg statuses and apply
	void whatHappened(int damageNum);
	void whatHappened(int damageNum, string Status);
	void whatHappened(string Status);
protected:
	sf::RectangleShape sprite; //this can be whatever we want i guess, but its a square for now
	string Name; //we store the type of character class here for displaying i guess?
	//stats
	int hp;
	int hpMax;
	int crit;
	int xp;
	int xpMax;
	double dmgTaken; //this can be positive or negative depending on status/passives or whatever
	//for example. the tank will automatically have this set to -.20, so they would take 80% of total damage in calculation

	//ailments, can add more later
	bool isAlive;
	bool isBleed;
	int bDuration;
	bool isStunned;
	bool isPoisoned;
	int pDuration;
};
