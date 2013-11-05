/*
 * character.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: nick
 */

#include "character.h"
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <iostream>
using namespace std;

namespace d20Characters {

character::character(int thelevel) {
}

character::~character() {

}

//getters:
int character::getStrength() {
	return strength;
}
int character::getCharisma() {
	return charisma;
}
int character::getConstitution() {
	return constitution;
}
int character::getDexterity() {
	return dexterity;
}
int character::getIntelligence() {
	return intelligence;
}
int character::getWisdom() {
	return wisdom;
}

//hitPoints:
// When a creature's hit points drop below 0, it becomes unconscious.
// When a creature's hit points reach a negative total equal to its Constitution score, it dies.

int character::getDamageBonus() {
	return damageBonus;
}
int character::getHitPoints() {
	return hitPoints;
}
int character::getArmorClass() {
	return armorClass;
}
int character::getAttackBonus() {
	return attackBonus;
}

// items:
void character::setHelmet(bool h) {
	helmet = h;
	// notify GUI or MAP
	notifyAllObservers();
}
void character::addRing() {
	if (rings < 2) {
		rings += 1;
		// notify GUI or MAP
		notifyAllObservers();
	} else
		cout << endl << "CANNOT addRing(): already 2 rings" << endl;
}
void character::removeRing() {
	if (rings > 0) {
		rings -= 1;
		// notify GUI or MAP
		notifyAllObservers();
	} else
		cout << endl << "CANNOT removeRing(): already 0 rings" << endl;
}
void character::setRings(int number) { // max of 2
	if (number >= 0 && number < 2) {
		rings = number;
		// notify GUI or MAP
		notifyAllObservers();
	} else
		cout << endl
				<< "CANNOT setRings: invalid number of rings (range is 0-2 inclusive)"
				<< endl;
}
void character::setWeapon(bool w) {
	weapon = w;
	// notify GUI or MAP
	notifyAllObservers();
}
void character::setShield(bool s) {
	shield = s;
	//dependents:
	setArmorClass();
	// notify GUI or MAP
	notifyAllObservers();
}
void character::setArmor(bool a) {
	armor = a;
	//dependents:
	setArmorClass();
	// notify GUI or MAP
	notifyAllObservers();
}
void character::setBelt(bool b) {
	belt = b;
	// notify GUI or MAP
	notifyAllObservers();
}
void character::setBoots(bool b) {
	boots = b;
	// notify GUI or MAP
	notifyAllObservers();
}

//print:
void character::printCharacterStats() {

	cout << endl << "====================================================="
			<< endl;
	cout << "PRINTING CHARACTER STATS: " << endl << endl;

	cout << "strength: " << strength << endl;
	cout << "intelligence: " << intelligence << endl;
	cout << "wisdom: " << wisdom << endl;
	cout << "constitution: " << constitution << endl;
	cout << "charisma: " << charisma << endl;
	cout << "dexterity: " << dexterity << endl;

	//hit points:
	cout << "hitPoints: " << hitPoints << endl;

	//armor class:
	// N.B. in waiting for the actual armor class, I simply set an int which gives a "range":
	cout << "armorClass: " << armorClass << endl;

	//attack bonus:
	cout << "attackBonus: " << attackBonus << endl;
	//damage bonus:
	cout << "damageBonus: " << damageBonus << endl;

	// items, with max allowed:
	// N.B. again, since I don't have the items class made by my team partner,
	// I will use these temporary variables.

	//	1 helmet,
	cout << "helmet: " << helmet << endl;
	//	2 rings,
	cout << "rings: " << rings << endl;
	//	1 weapon,
	cout << "weapon: " << weapon << endl;
	//	1 shield,
	cout << "shield: " << shield << endl;
	//	1 armor,
	cout << "armor: " << armor << endl;
	//	1 belt,
	cout << "belt: " << belt << endl;
	//	1 boots
	cout << "boots: " << boots << endl;
	cout << "=====================================================" << endl;
}
} /* namespace d20Characters */
