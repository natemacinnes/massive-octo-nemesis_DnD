#include "stdafx.h"
/*
 * Fighter.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: nick
 */

#include "Fighter.h"
#include "character.h"
#include "Item.h"
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <iostream>
#include <math.h>
using namespace std;

namespace d20Characters {

Fighter::Fighter(int level) :
		character(level) {

	// setting the level
	setLevel(level);

	//	(1) ability scores (generated randomly)
	//	and ability modifiers,

	// (...) Possible ability scores range from 7 to 18:
	// http://www.d20pfsrd.com/basics-ability-scores/character-creation
	srand(time(NULL)); // init random seed
	setStrength(rand() % 11 + 7); // generate random int between 7 and 18
	setIntelligence(rand() % 11 + 7);
	setWisdom(rand() % 11 + 7);
	setConstitution(rand() % 11 + 7);
	setCharisma(rand() % 11 + 7);
	setDexterity(rand() % 11 + 7);

	//==============================now members that depend on other variables:

	//	(2) hit points (based on constitution modifier and level),
	setHitPoints(rand() % 11 + 7);

	//	(3) armor class (based on dexterity modifier),
	setArmorClass(); //TODO: for performance: remove it here and make two different set<ability>() functions to update properly the "dependents"

	//	(4) attack bonus (based level and strength/dexterity modifiers),
	//see table:
	//http://www.d20srd.org/srd/improvingMonsters.htm
	setAttackBonus(rand() % 10 + 1); // for a fighter it's using a d10

	//	(5) damage bonus (based on strength modifier).
	setDamageBonus(rand() % 10 + 1);

}

Fighter::~Fighter() {

}

//level:
void Fighter::setLevel(int thelevel) {
	if (thelevel > 0) {
		level = thelevel;
		//dependents:
		srand(time(NULL));
		setHitPoints(rand() % 11 + 7);
		// notify GUI or MAP
		notifyAllObservers();
	}
}
int Fighter::getLevel() {
	return level;
}

//setters for abilities:
void Fighter::setStrength(int diceResult) {
	if (!(diceResult > 6 && diceResult < 19)) {
		cout << endl << "ERROR: invalid dice value for setStrength(int d)"
				<< endl;
		return;
	}
	strength = diceResult;
	strengthModifier = floor((double) (strength / 2) - 5); //http://www.systemreferencedocuments.org/resources/systems/pennpaper/modern/smack/abilityscores.html
	//dependents:
	setAttackBonus();
	setDamageBonus();
	// notify GUI or MAP
	notifyAllObservers();
}
void Fighter::setCharisma(int diceResult) {
	if (!(diceResult > 6 && diceResult < 19)) {
		cout << endl << "ERROR: invalid dice value for setCharisma(int d)"
				<< endl;
		return;
	}
	charisma = diceResult;
	charismaModifier = floor((double) (charisma / 2) - 5);
	// notify GUI or MAP
	notifyAllObservers();
}
void Fighter::setConstitution(int diceResult) {
	if (!(diceResult > 6 && diceResult < 19)) {
		cout << endl << "ERROR: " << diceResult
				<< "invalid dice value for setConstitution(int d)" << endl;
		return;
	}
	constitution = diceResult;
	constitutionModifier = floor((double) (constitution / 2) - 5);
	// notify GUI or MAP
	notifyAllObservers();
}
void Fighter::setDexterity(int diceResult) {
	if (!(diceResult > 6 && diceResult < 19)) {
		cout << endl << "ERROR: " << diceResult
				<< "invalid dice value for setDexterity(int d)" << endl;
		return;
	}
	dexterity = diceResult;
	dexterityModifier = floor((double) (dexterity / 2) - 5);
	//dependents, to be recalculated:
	setArmorClass();
	setAttackBonus();
	// notify GUI or MAP
	notifyAllObservers(); //comment out because call done in dependents anyways
}
void Fighter::setIntelligence(int diceResult) {
	if (!(diceResult > 6 && diceResult < 19)) {
		cout << endl << "ERROR: " << diceResult
				<< "invalid dice value for setIntelligence(int d)" << endl;
		return;
	}
	intelligence = diceResult;
	intelligenceModifier = floor((double) (intelligence / 2) - 5);
	// notify GUI or MAP
	notifyAllObservers();
}
void Fighter::setWisdom(int diceResult) {
	if (!(diceResult > 6 && diceResult < 19)) {
		cout << endl << "ERROR: " << diceResult
				<< "invalid dice value for setWisdom(int d)" << endl;
		return;
	}
	wisdom = diceResult;
	wisdomModifier = floor((double) (wisdom / 2) - 5);
	// notify GUI or MAP
	notifyAllObservers();
}

//hit points:
void Fighter::setHitPoints(int diceResult) { //(int constitution, int currentLevel) {
	if (!(diceResult > 6 && diceResult < 19)) {
		cout << endl << "ERROR: " << diceResult
				<< "invalid dice value for setHitPoints(int d)" << endl;
		return;
	}
	if (level == 1) {
		hitPoints = diceResult + constitution;
	} else { // if the level is higher than 1:
		srand(time(NULL)); // init random seed
		hitPoints = diceResult + constitution + rand() % 11 + 7;
	}
	// notify GUI or MAP
	//notifyAllObservers(); // since this method is a dependent (called by others)
}

//armor class
void Fighter::setArmorClass() {
	// http://paizo.com/prd/combat.html#_armor-class
	//10 + armor bonus + shield bonus + Dexterity modifier + other modifiers
	armorClass = 10 + armor + shield + dexterityModifier;
	// notify GUI or MAP
	//notifyAllObservers(); //this method is a dependent
}

//attack bonus
void Fighter::setAttackBonus(int diceResult) { //(int level, int strength, int dexterity) {
	if (!(diceResult > 0 && diceResult < 12)) {
		cout << endl << "ERROR: " << diceResult
				<< "invalid dice value for setAttackBonus(int d)" << endl;
		return;
	}
	attackBonusDiceResult = diceResult;
	attackBonus = attackBonusDiceResult + strengthModifier + dexterityModifier;
	// notify GUI or MAP
	notifyAllObservers();
}
void Fighter::setAttackBonus() { //(int level, int strength, int dexterity) {
	attackBonus = attackBonusDiceResult + strengthModifier + dexterityModifier;
	// notify GUI or MAP
	notifyAllObservers();
}

//damage bonus
void Fighter::setDamageBonus(int diceResult) { //(int strength) {
	if (!(diceResult > 0 && diceResult < 12)) {
		cout << endl << "ERROR: " << diceResult
				<< "invalid dice value for setDamageBonus(int d)" << endl;
		return;
	}
	damageBonusDiceResult = diceResult;
	damageBonus = damageBonusDiceResult + strengthModifier;
	// notify GUI or MAP
	notifyAllObservers();
}
void Fighter::setDamageBonus() { //(int strength) {
	damageBonus = damageBonusDiceResult + strengthModifier;
	// notify GUI or MAP
	//notifyAllObservers(); // this method is a dependent
}

} /* namespace d20Characters */
