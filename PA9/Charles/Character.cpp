#include "Character.h"


Character::Character(int StartHP, int StartCrit, string cName)
{
	hpMax = StartHP;
	hp = StartHP;
	crit = StartCrit; //this will typically be around 20 for "20% crit" but parametered for a certain class starting with higher crit chance
	Name = cName;
	bDuration = 0;
	pDuration = 0;
	isBleed = false;
	isStunned = false;
	isPoisoned = false;
	isAlive = true;
	sprite.setSize(sf::Vector2f(40, 40)); // interchangable to UI decisions
	sprite.setFillColor(sf::Color::Red); //need to be able to conditionally do this. maybe delete for a virtual function?
	//could just default to red for less enemy character code, make functions for player characters
	// could also just call in constructor too, since both constructors will be called but this will be called first


}
Character::~Character()
{
	// not sure what to put in this yet, or if a defined destructor is even needed
}
sf::RectangleShape Character::display(int index)
{
	switch (index)
	{
	case 0: sprite.setPosition(sf::Vector2f(0, 0)); //conditional on UI demands
		if (Name == "Boss")
		{
			sprite.setSize(sf::Vector2f(100, 100)); //conditional on UI demands
			sprite.setPosition(sf::Vector2f(800, 400)); //conditional on UI demands
		}
		break;
	case 1: sprite.setPosition(sf::Vector2f(0, 0));
		break;
	case 2: sprite.setPosition(sf::Vector2f(0, 0));
		break;
	case 3: sprite.setPosition(sf::Vector2f(0, 0));
		break;
	}
	return sprite;
}

sf::Text Character::UpdateSheet(int index)
{

	string sheet = ""; //im horrid with strings but hopefully this works
	sheet += Name; //Name
	sheet += " "; //Name .
	sheet += std::to_string(hp);// Name 100
	sheet += "/"; //Name 100/
	sheet += std::to_string(hpMax); // Name 100/100
	if (isBleed)
	{
		sheet += " bld"; //Name 100/100 bld
	}
	if (isStunned)
	{
		sheet += " stn"; //Name 100/100 stn
	}
	if (isPoisoned)
	{
		sheet += " psn"; //Name 100/100 psn
	}

	sheetStats.setColor(sf::Color::White);
	sheetStats.setString(sheet);
	sheetStats.setFont(sf::Font::);//figure this out i guess, dont know if there is a default font

	if (Name == "Boss") //boss wont be in an array
	{
		sheetStats.setCharacterSize(14); //conditional on UI demands
		sheetStats.setPosition(sf::Vector2f(800, 400)); //conditional on UI demands
	}
	else
	{

		switch (index)
		{
		case 0: sheetStats.setPosition(sf::Vector2f(0, 0)); //conditional on UI demands
			break;
		case 1: sheetStats.setPosition(sf::Vector2f(0, 0));
			break;
		case 2: sheetStats.setPosition(sf::Vector2f(0, 0));
			break;
		case 3: sheetStats.setPosition(sf::Vector2f(0, 0));
			break;
		}
	}
	return sheetStats;

}
void Character::BaseAttack(Character* target) //what a base attack function will look like
{
	int critroll = rand() % 100; //zero rollable
	if (critroll <= crit)
	{
		target->whatHappened(15 * 2); //multiplier to crits can be debated here if we want
	}
	else
	{
		target->whatHappened(15);
	}
}
void Character::specialAbility(Character* target)
{
	//sample ability to show what happens here, each character will have different code per function
	int critroll = rand() % 100; //srand will have to be setup in the app or main somewhere
	if (critroll <= crit) //roll 1-crit chance = crit lands
	{
		target->whatHappened(20 * 2, "Bleed"); //double damage, derived classes will have a base damage for both attack and ability

	}
	else
	{
		target->whatHappened(20, "Bleed");
	}
	

}
bool Character::turnStatus() //false if turn is skipped, check for dmg statuses and apply
{
	if (!isAlive)
	{
		return false; //dead, no turn

	}
	if (isBleed) //a character can have all ailments so no else ifs here unforch
	{
		hp -= 3; //this wont be affected by dmg modifiers
		bDuration--;
		if (bDuration == 0) //bleed expired
		{
			isBleed = false;
		}
	}
	if (isPoisoned)
	{
		hp -= 3;
		pDuration--;
		if (pDuration == 0)
		{
			isPoisoned = false;
		}
	}
	if (isStunned)
	{
		isStunned = false; //stunned gets removed, turn skipped
		return false; //needs to be in app code somewhere that if this function call is false, character skips turn
	}
	return true; // return true otherwise, turn is good to go
}
void Character::whatHappened(int damageNum)
{
	hp -= (damageNum * (1 + dmgTaken)); //simple as that may need to test here since we are dealing with a double in dmgTaken
	//dmgTaken should be 0 most of the time.
	if (hp <= 0)
	{
		hp = 0; //negative xp being displayed would be wierd
		isAlive = false;
		isStunned = false;
		isBleed = false;
		isPoisoned = false;
		bDuration = 0;
		pDuration = 0; //complete reset on ailments
	}
	if (hp >= hpMax) //healing could put over health cap so this fixes that
	{
		hp = hpMax;
	}
}
void Character::whatHappened(int damageNum, string Status)
{
	hp -= (damageNum * (1 + dmgTaken));
	if (Status == "Bleed")
	{
		isBleed = true;
		bDuration = 3; //three turns duration
	}
	else if (Status == "Stun")
	{
		isStunned = true;

	}
	else if (Status == "Poison") //can add more if we want, dont want to overbook it
	{
		isPoisoned = true;
		pDuration = 3;
	}
	if (hp <= 0)
	{
		hp = 0;
		isAlive = false;
		isStunned = false;
		isBleed = false;
		isPoisoned = false;
		bDuration = 0;
		pDuration = 0; //complete reset on ailments
	}
	if (hp >= hpMax) //healing could put over health cap so this fixes that
	{
		hp = hpMax;
	}

}
void Character::whatHappened(string Status)
{
	
	if (Status == "Bleed")
	{
		isBleed = true;
		bDuration = 3;
	}
	else if (Status == "Stun")
	{
		isStunned = true;

	}
	else if (Status == "Poison") //will add conditions for healing or revive later done for tonight
	{
		isPoisoned = true;
		pDuration = 3;
	}
	else if (Status == "Taunt")
	{
		isTaunt = true;
	}
	else if (Status == "Full")
	{
		hp = hpMax;
	}
}

bool Character::isdead()
{
	if (!isAlive)
	{
		return true;
	}
	return false;
}
void Character::Revive()
{
	isAlive = true;
	hp = hpMax; // bad game design but whatever we are in a rush
}

string Character::getName()
{
	return Name;
}