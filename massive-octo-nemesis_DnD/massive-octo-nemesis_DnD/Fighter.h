#pragma once
/*
 * Fighter.h
 *
 *  Created on: Oct 21, 2013
 *      Author: nick
 */

#include "character.h"
#include "Observable.h"
#include "chracPosition.h"



namespace d20Characters {

class Fighter: public character {
public:
	
	Fighter(int level);
	Fighter(std::vector<int> v, int level);//this is to create a fighter from loadFile
	virtual ~Fighter();

	using character::setLevel;
	virtual void setLevel(int level);
	using character::getLevel;
	virtual int getLevel();

	using character::setStrength;
	void setStrength(int strength);
	using character::setIntelligence;
	void setIntelligence(int i);
	using character::setWisdom;
	void setWisdom(int w);
	using character::setConstitution;
	void setConstitution(int c);
	using character::setCharisma;
	void setCharisma(int c);
	using character::setDexterity;
	void setDexterity(int d);

	//hit points:
	using character::setHitPoints;
	virtual void setHitPoints(int h); //(int constitution, int currentLevel);

	//armor class
	using character::setArmorClass;
	virtual void setArmorClass();

	//attack bonus
	using character::setAttackBonus;
	virtual void setAttackBonus(int a); //(int level, int strength, int dexterity);
	virtual void setAttackBonus();

	//damage bonus
	using character::setDamageBonus;
	virtual void setDamageBonus(int d); //(int strength);
	virtual void setDamageBonus();

	//save character and items to file
	void SaveCharacterToFile();

	//load character and items from file
	Fighter* LoadCharacterFromFile();
	Fighter* returnedFighter;

	//info for load
	std::vector<int> characterParams;
	
	//pickup items
	//bool pickUp(d20Items::Item*); //before was like this
	bool pickUp(int);
	std::string identifyItemOnMap(int);
	void setItemToPla(std::string);
};

} /* namespace d20Characters */