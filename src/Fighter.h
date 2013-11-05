/*
 * Fighter.h
 *
 *  Created on: Oct 21, 2013
 *      Author: nick
 */

#ifndef FIGHTER_H_
#define FIGHTER_H_

#include "character.h"

namespace d20Characters {

class Fighter: public d20Characters::character {
public:
	Fighter(int level);
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

};

} /* namespace d20Characters */
#endif /* FIGHTER_H_ */
