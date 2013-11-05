//============================================================================
// Name        : comp345_character.cpp
// Author      : Nicolas Chausseau 643 1526
// Version     :
// Copyright   : Your copyright notice
// Description : test driver for character class of comp345 assignment 1
//============================================================================

#include <iostream>
using namespace std;
//using namespace d20Characters;
#include "character.h"
#include "Fighter.h"
#include "Observable.h"
#include "Observer.h"

int main() {


	//create fighter to observe:
	d20Characters::Fighter myobs(2);

	//faking passing the GUI class:
	// later will be fake_GUi.registerToCharacter // or even done in constructor
	myobs.registerObserver(new d20Characters::Observer(345));

	//fake some modifs:
	myobs.notifyAllObservers();

	cout
			<< "ASSIGNMENT 2 !!! " << "Starting comp345_driver_for_character.cpp by Nicolas Chausseau 643 1526"
			<< endl;
	//==================creating a fighter:
	//d20Characters::character myFighter(1); // passing the level, assuming one for now.
	d20Characters::Fighter myFighter(1);

	//logging all the variables to observe:
	cout << endl << "Simple initialization of Fighter object: " << endl;
	myFighter.printCharacterStats();

	//==================testing all the items setters: and logging after modifications:
	myFighter.setArmor(true);
	myFighter.setBelt(true);
	myFighter.setBoots(true);
	myFighter.setHelmet(true);
	myFighter.setShield(true);
	myFighter.setWeapon(true);

	cout << endl << "Modified fighter items. " << endl;

	cout << endl << "modifying armor and shield should modify setArmorClass()."
			<< endl;
	//
	//myFighter.setArmorClass(); // this one not, it's entirely dependent on other variables.
	//should be protected, user cannot set them directly:
	//myFighter.setAttackBonus(20);
	//myFighter.setCharisma(); // all those should be inaccessible to the user

	myFighter.printCharacterStats();

	//==================testing setting the number of rings different ways:
	cout << endl << "adding some rings several times, in different ways: "
			<< endl;
	myFighter.setRings(32); //should fail with error msg
	myFighter.addRing();
	myFighter.addRing();
	myFighter.addRing();
	myFighter.addRing();
	//myFighter.removeRing();
	cout << endl
			<< "setStrength(18) should affect setAttackBonus(); setDamageBonus(); since those depend on it."
			<< endl;
	myFighter.setStrength(18); // this can really be used by a "user" of the class

	myFighter.printCharacterStats();

	//==================testing removing a ring
	cout << endl << "removing some rings several times, in different ways: "
			<< endl;
	myFighter.removeRing();
	myFighter.removeRing();
	myFighter.removeRing();
	myFighter.removeRing();
	myFighter.removeRing();

	cout << endl
			<< "setDexterity(10) should affect 	setArmorClass(); and setAttackBonus(); since those depend on it."
			<< endl;
	myFighter.setDexterity(10); // this can really be used by a "user" of the class

	myFighter.printCharacterStats();

	//====================testing adding a wrong dice result:
	myFighter.setHitPoints(124);
	myFighter.setDamageBonus(1064);
	myFighter.setAttackBonus(-1);

	myFighter.printCharacterStats();

	return 0;
}
