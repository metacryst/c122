#pragma once
#include "PlayerChar.h"


void Physical::BaseAttack(Character* target)
{
	int critroll = rand() % 100; //zero rollable
	if (critroll <= crit)
	{
		target->whatHappened(baseDamage * 2); //multiplier to crits can be debated here if we want
	}
	else
	{
		target->whatHappened(baseDamage);
	}
}
void  Physical::SpecialAttack(Character* target) //this is just a bigger attack
{
	int critroll = rand() % 100;
	if (critroll <= crit)
	{
		if (passive) //passive on
		{
			target->whatHappened(SpecialDamage * 2, "Bleed");
		}
		else
		{
			target->whatHappened(SpecialDamage * 2); //multiplier to crits can be debated here if we want

		}
		
	}
	else
	{
		if (passive) //passive on
		{
			target->whatHappened(baseDamage, "Bleed");
		}
		else
		{
			target->whatHappened(baseDamage);

		}

	}

}

bool Physical::islevelup()
{
	return levelup;
}
void Physical::AwardXP(int num)
{
	xp += num;
	if (xp >= xpMax) //level gained
	{
		levelup = true;
		xp = xp - xpMax; // ex: 203/200 xp would become 3/200, as in 3xp into the next level
		//we dont really need to scale anything here since we are pressed for time
		level++;
		if (level == 5)
		{
			passive = true;
		}

	}
}
void Physical::Upgrade(int num)
{
	switch (num)
	{
	case 1: baseDamage += 5; //damage, will probably have a more general term like power.
		SpecialDamage += 5;
		break;
	case 2: hpMax += 20;
		hp += 20; //will heal 20 as well
		break;
	case 3: crit += 5; //+5% crit
		break;
	case 4: hp = hpMax; //fullheal, contemplating getting rid of this, its bad game design since we have a ton of full heal options
		break;
	}
}
sf::RectangleShape Physical::display(int index)
{
	switch (index)
	{
	case 0: sprite.setPosition(sf::Vector2f(0, 0)); //conditional on UI demands
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
sf::Text Physical::UpdateSheet(int index)
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
	
	return sheetStats;
}




void Tank::BaseAttack(Character* target)
{
	int critroll = rand() % 100; //zero rollable
	if (critroll <= crit)
	{
		target->whatHappened(baseDamage * 2); //multiplier to crits can be debated here if we want
	}
	else
	{
		target->whatHappened(baseDamage);
	}
}
void  Tank::SpecialAttack(Character* target1, Character* target2, Character* target3, Character* target4) //this is just a bigger attack
{
	target1->whatHappened("Taunt");
	target2->whatHappened("Taunt");
	target3->whatHappened("Taunt");
	target4->whatHappened("Taunt");

}

bool Tank::islevelup()
{
	return levelup;
}
void Tank::AwardXP(int num)
{
	xp += num;
	if (xp >= xpMax) //level gained
	{
		levelup = true;
		xp = xp - xpMax; // ex: 203/200 xp would become 3/200, as in 3xp into the next level
		//we dont really need to scale anything here since we are pressed for time
		level++;
		if (level == 5)
		{
			hpMax += 200; //more max hp at upon hitting level 5
			hp += 200;
			passive = true;
		}

	}
}
void Tank::Upgrade(int num)
{
	switch (num)
	{
	case 1: baseDamage += 5; //damage, will probably have a more general term like power.
		SpecialDamage += 5;
		break;
	case 2: hpMax += 20;
		hp += 20; //will heal 20 as well
		break;
	case 3: crit += 5; //+5% crit
		break;
	case 4: hp = hpMax; //fullheal, contemplating getting rid of this, its bad game design since we have a ton of full heal options
		break;
	}
}
sf::RectangleShape Tank::display(int index)
{
	switch (index)
	{
	case 0: sprite.setPosition(sf::Vector2f(0, 0)); //conditional on UI demands
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
sf::Text Tank::UpdateSheet(int index)
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
	
	return sheetStats;
}


void Magic::BaseAttack(Character* target)
{
	int critroll = rand() % 100; //zero rollable
	if (critroll <= crit)
	{
		target->whatHappened(baseDamage * 2); //multiplier to crits can be debated here if we want
	}
	else
	{
		target->whatHappened(baseDamage);
	}
}
void  Magic::SpecialAttack(Character* target1, Character* target2, Character* target3, Character* target4)
{
	int critroll = rand() % 100;
	if (critroll <= crit)
	{
		target1->whatHappened(SpecialDamage * 2);
		target2->whatHappened(SpecialDamage * 2);
		target3->whatHappened(SpecialDamage * 2);
		target4->whatHappened(SpecialDamage * 2);
		

	}
	else
	{
		target1->whatHappened(SpecialDamage);
		target2->whatHappened(SpecialDamage);
		target3->whatHappened(SpecialDamage);
		target4->whatHappened(SpecialDamage);

	}

}

void Magic::SpecialAttack(Character* target)
{
	int critroll = rand() % 100;
	if (critroll <= crit)
	{
		if (passive) //passive on
		{
			target->whatHappened(SpecialDamage * 4 * 2); //total damage that would be dealt to all 4 targets is consolidated for one single target
		}
		else
		{
			target->whatHappened(SpecialDamage * 2); //multiplier to crits can be debated here if we want

		}


	}
	else
	{
		if (passive) //passive on
		{
			target->whatHappened(baseDamage * 4);
		}
		else
		{
			target->whatHappened(baseDamage);

		}

	}
}

bool Magic::islevelup()
{
	return levelup;
}
void Magic::AwardXP(int num)
{
	xp += num;
	if (xp >= xpMax) //level gained
	{
		levelup = true;
		xp = xp - xpMax; // ex: 203/200 xp would become 3/200, as in 3xp into the next level
		//we dont really need to scale anything here since we are pressed for time
		level++;
		if (level == 5)
		{
			passive = true;
		}

	}
}
void Magic::Upgrade(int num)
{
	switch (num)
	{
	case 1: baseDamage += 5; //damage, will probably have a more general term like power.
		SpecialDamage += 5;
		break;
	case 2: hpMax += 20;
		hp += 20; //will heal 20 as well
		break;
	case 3: crit += 5; //+5% crit
		break;
	case 4: hp = hpMax; //fullheal, contemplating getting rid of this, its bad game design since we have a ton of full heal options
		break;
	}
}
sf::RectangleShape Magic::display(int index)
{
	switch (index)
	{
	case 0: sprite.setPosition(sf::Vector2f(0, 0)); //conditional on UI demands
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
sf::Text Magic::UpdateSheet(int index)
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

	return sheetStats;
}

void Healer::BaseAttack(Character* target)
{
	int critroll = rand() % 100; //zero rollable
	if (critroll <= crit)
	{
		target->whatHappened(baseDamage * 2); //multiplier to crits can be debated here if we want
	}
	else
	{
		target->whatHappened(baseDamage);
	}
}
void  Healer::SpecialAttack(Character* target)
{
	int critroll = rand() % 100;
	if (critroll <= crit)
	{
		if (passive)
		{
			target->whatHappened("Full");
		}
		else
		{
			target->whatHappened(SpecialDamage * 2);
		}


	}
	else
	{
		if (passive)
		{
			target->whatHappened("Full");
		}
		else
		{
			target->whatHappened(SpecialDamage);
		}

	}

}


bool Healer::islevelup()
{
	return levelup;
}
void Healer::AwardXP(int num)
{
	xp += num;
	if (xp >= xpMax) //level gained
	{
		levelup = true;
		xp = xp - xpMax; // ex: 203/200 xp would become 3/200, as in 3xp into the next level
		//we dont really need to scale anything here since we are pressed for time
		level++;
		if (level == 5)
		{
			baseDamage += 15; // base damage boost
			passive = true; //full heal enabled
		}

	}
}
void Healer::Upgrade(int num)
{
	switch (num)
	{
	case 1: baseDamage += 5; //damage, will probably have a more general term like power.
		SpecialDamage += 5;
		break;
	case 2: hpMax += 20;
		hp += 20; //will heal 20 as well
		break;
	case 3: crit += 5; //+5% crit
		break;
	case 4: hp = hpMax; //fullheal, contemplating getting rid of this, its bad game design since we have a ton of full heal options
		break;
	}
}
sf::RectangleShape Healer::display(int index)
{
	switch (index)
	{
	case 0: sprite.setPosition(sf::Vector2f(0, 0)); //conditional on UI demands
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
sf::Text Healer::UpdateSheet(int index)
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

	return sheetStats;
}

