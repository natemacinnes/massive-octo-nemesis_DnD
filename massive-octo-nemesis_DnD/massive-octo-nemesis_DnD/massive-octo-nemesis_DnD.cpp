// massive-octo-nemesis_DnD.cpp : Defines the entry point for the console application.
//
//============================================================================
// Name        : comp345_character.cpp
// Author      : Nicolas Chausseau 643 1526
// Version     :
// Copyright   : Your copyright notice
// Description : test driver for character class of comp345 assignment 1
//============================================================================


#include "stdafx.h"

#include <iostream>
using namespace std;
//using namespace d20Characters;
#include "character.h"
#include "Fighter.h"
#include "Observable.h"
#include "Observer.h"
#include "GUIclass.h"
#include "TankFighterBuilder.h"
#include "BullyFighterBuilder.h"
#include "NimbleFighterBuilder.h"
#include <time.h>

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL)); // init random seed for all 

	cout << endl
		<< "Starting demonstration driver for assignment 3 by Nicolas Chausseau 643 1526"
		<< endl << endl;

	cout << "We demonstrate the builder pattern and the effects of setLevel. " << endl << endl;

	//make a tank:
	d20Characters::TankFighterBuilder* tankbuilder = new d20Characters::TankFighterBuilder();
	d20Characters::Fighter* tank = tankbuilder->getCharacter();
	cout << "\nCreated tank fighter with builder pattern: " << endl;
	tank->addRing(new d20Items::Ring("Ring"));
	tank->addRing(new d20Items::Ring("Ring"));
	tank->addRing(new d20Items::Ring("Ring"));
	tank->addRing(new d20Items::Ring("Ring"));
	tank->addRing(new d20Items::Ring("Ring"));
	tank->printCharacterStats();
	cout <<endl<< "********** Inventory Pane of Worn Items: **********" ;
	tank->wornContainer->printItems();
	cout << endl<< "********** Inventory Pane of Items in Bag: **********";
	tank->bagContainer->printItems();

	tank->wearItem();

	cout <<endl<< "********** Inventory Pane of Worn Items: **********" ;
	tank->wornContainer->printItems();
	cout << endl<< "********** Inventory Pane of Items in Bag: **********";
	tank->bagContainer->printItems();

	////make a bully:
	//d20Characters::BullyFighterBuilder* bullybuilder = new d20Characters::BullyFighterBuilder();
	//d20Characters::Fighter* bully = bullybuilder->getCharacter();
	//cout << "\nCreated bully fighter with builder pattern: " << endl;
	//bully->printCharacterStats();

	////make a nimble:
	//d20Characters::NimbleFighterBuilder* nimblebuilder = new d20Characters::NimbleFighterBuilder();
	//d20Characters::Fighter* nimble = nimblebuilder->getCharacter();
	//cout << "\nCreated nimble fighter with builder pattern: " << endl;
	//nimble->printCharacterStats();

	////now increase the levels and print to verify:
	//tank->increaseLevel();
	//cout << "\nwe increased the level for tank. This should affect \n - hitPoints, \n - attackBonus and \n - numAttackPerRound: " << endl;
	//tank->printCharacterStats();

	//bully->increaseLevel();
	//cout << "\nwe increased the level for bully. This should affect \n - hitPoints, \n - attackBonus and \n - numAttackPerRound: " << endl;
	//bully->printCharacterStats();

	//nimble->increaseLevel();
	//cout << "\nwe increased the level for nimble. This should affect \n - hitPoints, \n - attackBonus and \n - numAttackPerRound: " << endl;
	//nimble->printCharacterStats();


	//demonstrate save load functionality:
	//cout << endl
	//	<< "Starting comp345_driver_for_character.cpp for assignment 2 by Nicolas Chausseau 643 1526"
	//	<< endl << endl;

	////create fighter that we will observe / watch for changes:
	//d20Characters::Fighter myFighter(1);
	//myFighter.printCharacterStats();


	////TEST FOR SAVE FILE & LOAD
	//myFighter.SaveCharacterToFile();
	//d20Characters::Fighter* myFighter2 = myFighter.LoadCharacterFromFile();
	//cout << "HERE: MAIN: " << myFighter2->getLevel() << endl;
	//myFighter2->printCharacterStats();


	//demonstrate assignment 2:
	/*
	//create GUI class that knows what what to do on fighter changes (e.g. refresh screen, but here just re-print):
	d20Characters::GUIclass* gui = new d20Characters::GUIclass();

	//plug the two together -- the observer (GUI object) and observable (Fighter object):
	gui->registerToObservable(&myFighter);

	//now any modifications on myFighter should trigger a re-print of myFighter:
	cout << endl << "myFighter.addRing(); SHOULD TRIGGER A RE-PRINT";
	myFighter.addRing();
	cout << endl << "myFighter.removeRing(); SHOULD TRIGGER A RE-PRINT";
	myFighter.removeRing();
	cout << endl << "myFighter.setArmor(true);; SHOULD TRIGGER A RE-PRINT";
	myFighter.setArmor(true);
	cout << endl << "myFighter.setBelt(true); SHOULD TRIGGER A RE-PRINT";
	myFighter.setBelt(true);
	cout << endl << "myFighter.setBoots(true); SHOULD TRIGGER A RE-PRINT";
	myFighter.setBoots(true);
	cout << endl << "myFighter.setHelmet(true); SHOULD TRIGGER A RE-PRINT";
	myFighter.setHelmet(true);
	cout << endl << "myFighter.setShield(true); SHOULD TRIGGER A RE-PRINT";
	myFighter.setShield(true);
	cout << endl << "myFighter.setWeapon(true); SHOULD TRIGGER A RE-PRINT";
	myFighter.setWeapon(true);

	//those should not work because out of bounds:
	cout << endl
	<< "myFighter.setHitPoints(124); SHOULD *NOT* TRIGGER A RE-PRINT";
	myFighter.setHitPoints(124);
	cout << endl
	<< "myFighter.setDamageBonus(1064); SHOULD *NOT* TRIGGER A RE-PRINT";
	myFighter.setDamageBonus(1064);
	cout << endl
	<< "myFighter.setAttackBonus(-1); SHOULD *NOT* TRIGGER A RE-PRINT";
	myFighter.setAttackBonus(-1);
	*/
	system("pause");

	return 0;
}

