#pragma once
/*
 * character.h
 *
 *  Created on: Oct 21, 2013
 *      Author: nick
 */

#include "Observable.h"
#include "ItemContainer.h"
#include "Helmet.h"
#include "Shield.h"
#include "Weapon.h"
#include "Ring.h"
#include "Helmet.h"
#include "Armor.h"
#include "Belt.h"
#include "Boots.h"

namespace d20Characters {

class character: public d20Characters::Observable {
public:
	character(int level);
	virtual ~character();

	//item container for the BAG:
	d20Items::ItemContainer* bag; 

	//to string for logging:
	virtual void printCharacterStats();

	//
	virtual void setLevel(int level_) = 0;
	virtual int getLevel() = 0;
	virtual void increaseLevel() = 0;

	//abilities: getters only,
	//setters are specific to subclasses to define boundaries:
	//and should be protected.
	int getStrength();
	int getIntelligence();
	int getWisdom();
	int getConstitution();
	int getCharisma();
	int getDexterity();

	//hit points:
	virtual void setHitPoints(int diceResult) = 0;//(int constitution, int currentLevel) = 0;
	int getHitPoints();

	//armor class
	int getArmorClass();

	//attack bonus
	int getAttackBonus();

	//damage bonus
	int getDamageBonus();

	//items: simple accessors, don't need to be redefined in subclass fighter
	void addHelmet(d20Items::Helmet* h);
	void addRing(d20Items::Ring* r);
	void removeRing();
	//void setRings( number); // max of 2
	void addWeapon(d20Items::Weapon* w);
	void addShield(d20Items::Shield* s);
	void addArmor(d20Items::Armor* a);
	void addBelt(d20Items::Belt* b);
	void addBoots(d20Items::Boots* b);

	d20Items::ItemContainer* wornContainer;
	d20Items::ItemContainer* bagContainer;

protected:

	//protected setters for abilities:
	virtual void setStrength(int diceResult) = 0;
	virtual void setIntelligence(int diceResult) = 0;
	virtual void setWisdom(int diceResult) = 0;
	virtual void setConstitution(int diceResult) = 0;
	virtual void setCharisma(int diceResult) = 0;
	virtual void setDexterity(int diceResult) = 0;

	//armor class
	virtual void setArmorClass() = 0;

	//attack bonus
	virtual void setAttackBonus(int a) = 0; //(int level, int strength, int dexterity) = 0;
	virtual void setAttackBonus() = 0;
	//assignment3:
	virtual void setNumAttacksPerRound(int level) = 0;
	int NumAttacksPerRound;

	//damage bonus
	virtual void setDamageBonus(int d) = 0; //(int strength) = 0;
	virtual void setDamageBonus() = 0;

	//level
	int level;// = 1;

	//abilities:
	int strength;
	int intelligence;
	int wisdom;
	int constitution;
	int charisma;
	int dexterity;
	//and their modifiers:
	int strengthModifier;
	int intelligenceModifier;
	int wisdomModifier;
	int constitutionModifier;
	int charismaModifier;
	int dexterityModifier;

	//hit points:
	int hitPoints;

	//armor class:
	// N.B. in waiting for the actual armor class, I simply set an int
	// which specifies what future type of armor it will have
	int armorClass;

	//attack bonus:
	int attackBonus;
	int attackBonusDiceResult; // for ease of recalculating

	//damage bonus:
	int damageBonus;
	int damageBonusDiceResult; // for ease or recalculation

	// items, with max allowed:
	// N.B. again, since I don't have the items class made by my team partner,
	// I will use these temporary variables.

	//	1 helmet,
	bool helmet;// = false;
	//	2 rings,
	bool rings;// = 0;
	//	1 weapon,
	bool weapon;// = false;
	//	1 shield,
	bool shield;// = false;
	//	1 armor,
	bool armor;// = false;
	//	1 belt,
	bool belt;// = false;
	//	1 boots
	bool boots;// = false;


};

} /* namespace d20Characters */