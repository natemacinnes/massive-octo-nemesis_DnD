#include "stdafx.h"
/*
 * character.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: nick
 */
#include "character.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <iostream>
using namespace std;

namespace d20Characters {

character::character(int thelevel) {
	this->level = thelevel;
	this->wornContainer = new d20Items::ItemContainer();
	this->bagContainer = new d20Items::ItemContainer();
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
void character::addHelmet(d20Items::Item* h) {
	

	//prompt the user if he wants to wear it or put it his bag:

	//check if he's already wearing a helmet:
	if (helmet == true) {
		cout << "You are already wearing a helmet. Adding to bag instead." << endl;
		bagContainer->add(h);
	} else {
		wornContainer->add(h);

		// since we can't get items easily after putting them in the bag, keep a boolean:
		helmet = true; //h;
	} 

	// notify GUI or MAP
	notifyAllObservers();
}
void character::addRing(d20Items::Item* r) {
	if (rings == false) {

		wornContainer->add(r);

		rings = true;
		// notify GUI or MAP
		notifyAllObservers();
	} else {
		cout << endl << "You already wear a ring. Adding to bag instead." << endl;
		bagContainer->add(r);
	}
}

//void character::removeRing() {
//	if (rings > 0) {
//		rings -= 1;
//		// notify GUI or MAP
//		notifyAllObservers();
//	} else
//		cout << endl << "CANNOT removeRing(): already 0 rings" << endl;
//}
//void character::setRings(int number) { // max of 2
//	if (number >= 0 && number < 2) {
//		rings = number;
//		// notify GUI or MAP
//		notifyAllObservers();
//	} else
//		cout << endl
//				<< "CANNOT setRings: invalid number of rings (range is 0-2 inclusive)"
//				<< endl;
//}
void character::addWeapon(d20Items::Item* w) {
	//prompt the user if he wants to wear it or put it his bag:

	//check if he's already wearing a helmet:
	if (weapon == true) {
		cout << "You are already wearing a weapon. Adding to bag instead." << endl;
		bagContainer->add(w);
	} else {
		wornContainer->add(w);

		// since we can't get items easily after putting them in the bag, keep a boolean:
		weapon = true; //h;
	} 

	// notify GUI or MAP
	notifyAllObservers();
}
void character::addShield(d20Items::Item* s) {
	//prompt the user if he wants to wear it or put it his bag:

	//check if he's already wearing a helmet:
	if (shield == true) {
		cout << "You are already wearing a shield. Adding to bag instead." << endl;
		bagContainer->add(s);
	} else {
		wornContainer->add(s);

		// since we can't get items easily after putting them in the bag, keep a boolean:
		weapon = true; //h;
	} 

	setArmorClass();
	// notify GUI or MAP
	notifyAllObservers();
}
void character::addArmor(d20Items::Item* a) {
	//prompt the user if he wants to wear it or put it his bag:

	//check if he's already wearing a helmet:
	if (armor == true) {
		cout << "You are already wearing an armor. Adding to bag instead." << endl;
		bagContainer->add(a);
	} else {
		wornContainer->add(a);

		// since we can't get items easily after putting them in the bag, keep a boolean:
		armor = true; //h;
	} 
	setArmorClass();
	// notify GUI or MAP
	notifyAllObservers();
}
void character::addBelt(d20Items::Item* b) {
	//prompt the user if he wants to wear it or put it his bag:

	//check if he's already wearing a helmet:
	if (belt == true) {
		cout << "You are already wearing an armor. Adding to bag instead." << endl;
		bagContainer->add(b);
	} else {
		wornContainer->add(b);

		// since we can't get items easily after putting them in the bag, keep a boolean:
		belt = true; //h;
	} 	
	// notify GUI or MAP
	notifyAllObservers();
}
void character::addBoots(d20Items::Item* b) {
	//prompt the user if he wants to wear it or put it his bag:

	//check if he's already wearing a helmet:
	if (boots == true) {
		cout << "You are already wearing boots. Adding to bag instead." << endl;
		bagContainer->add(b);
	} else {
		wornContainer->add(b);

		// since we can't get items easily after putting them in the bag, keep a boolean:
		belt = true; //h;
	} 	
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
	cout << "Level: " << getLevel() << endl;

	//hit points:
	cout << "hitPoints: " << hitPoints << endl;

	//armor class:
	// N.B. in waiting for the actual armor class, I simply set an int which gives a "range":
	cout << "armorClass: " << armorClass << endl;

	//attack bonus:
	cout << "attackBonus: " << attackBonus << endl;
	//assignment 3: number of attacks per round:
	cout << "NumAttacksPerRound: " << NumAttacksPerRound << endl;
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

void character::wear() {
	cout <<endl<< "********** Inventory Pane of Items in Bag: **********" ;
	bagContainer->printItems();

	cout << endl << "Enter the number of the item in your bag that you want to wear: ";
	int indexPlusOne = 0;
	cin >> indexPlusOne;

	d20Items::Item* itemPicked = bagContainer->at(indexPlusOne-1);
	wornContainer->add(itemPicked);
	bagContainer->remove(itemPicked);

}

//void character unwear() {
//
//}

} /* namespace d20Characters */
