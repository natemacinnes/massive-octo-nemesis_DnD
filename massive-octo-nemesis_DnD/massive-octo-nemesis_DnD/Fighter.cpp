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
//#include "Map.h"
#include <stdlib.h>
#include <stddef.h>
#include <iostream>
#include <math.h>
using namespace std;

#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <deque>
#include <cassert>
#include <sstream>

#include <windows.h>

namespace d20Characters {

	Fighter::Fighter(vector<int> v, int level_)
		:character (level)
	{


		//the actual fighter variables:
		//myStream << getLevel() << endl;
		//cout << "LEVEL?????????????" << level_;
		level = v.at(0);
		//cout << "LEVEL?????????????" << level_;

		//myStream << getArmorClass() << endl;
		armorClass = v.at(1);
		//myStream << getAttackBonus() << endl;
		attackBonus = v.at(2);
		//myStream << getCharisma() << endl;
		charisma = v.at(3);
		//myStream << getConstitution() << endl;
		constitution = v.at(4);
		//myStream << getDamageBonus() << endl;
		damageBonus = v.at(5);
		//myStream << getDexterity() << endl;
		dexterity = v.at(6);
		//myStream << getHitPoints() << endl;
		hitPoints = v.at(7);
		//myStream << getIntelligence() << endl;
		intelligence= v.at(8);
		//myStream << getStrength() << endl;
		strength = v.at(9);
		//myStream << getWisdom() << endl;
		wisdom = v.at(10);

		//additional ones:
		//	1 helmet,
		helmet = v.at(11);
		//	2 rings,
		rings = v.at(12);
		//	1 weapon,
		weapon = v.at(13); 
		//	1 shield,
		shield = v.at(14);
		//	1 armor,
		armor = v.at(15);
		//	1 belt,
		belt = v.at(16);
		//	1 boots
		boots = v.at(17);

	}

	Fighter::Fighter(int level) :
		character(level) {

			//init bag:
			bag = new d20Items::ItemContainer();

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

			//init all small vars:
			//	1 helmet,
			helmet = 0;
			//	2 rings,
			rings = 0;
			//	1 weapon,
			weapon = 0; 
			//	1 shield,
			shield = 0;
			//	1 armor,
			armor = 0;
			//	1 belt,
			belt = 0;
			//	1 boots
			boots = 0;
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


	void Fighter::SaveCharacterToFile()
	{

		std::string CharName;
		std::string InformationTextFile;
		std::string characterNames;
		std::string characterNamesFile;
		std::string HELDSTRING;
		std::string inputs;

		ofstream myStream;

		cout << "Input CHARACTER name to save" << endl;

		//input character name
		cin >> CharName;
		cout << endl;

		//covertly convert to _Character.txt so user doesn't have to input it
		InformationTextFile = (CharName + "_Character.txt");
		characterNamesFile = "characterNames.txt";



		//create dir if it doesn't exist yet:
		LPCWSTR outerDir = L"C:\\massive-octo-nemesis_DnD";
		CreateDirectoryW(outerDir, NULL);

		//and again, for the inner level:
		LPCWSTR innerDir = L"C:\\massive-octo-nemesis_DnD\\Characters";
		CreateDirectoryW(innerDir, NULL);

		//try to open the file (or create it if the two lines above just created the folders):
		cout << InformationTextFile;
		myStream.open("C:\\massive-octo-nemesis_DnD\\Characters\\" + InformationTextFile);
		if(!myStream.is_open()) {

			//if it failed try to create the file:
			myStream.open("C:\\massive-octo-nemesis_DnD\\Names\\characterNames.txt", std::fstream::trunc);
			if(!myStream.is_open()) {
				cout << "Error opening file" << endl;
				//system("Pause");
				//return 0;

			} else {

				//than all is good now, continue with reading the file.


				//then no else , just continue, all is good now:

				myStream << getLevel() << endl;///level
				myStream << getArmorClass() << endl;
				myStream << getAttackBonus() << endl;
				myStream << getCharisma() << endl;
				myStream << getConstitution() << endl;
				myStream << getDamageBonus() << endl;
				myStream << getDexterity() << endl;
				myStream << getHitPoints() << endl;
				myStream << getIntelligence() << endl;
				myStream << getStrength() << endl;
				myStream << getWisdom() << endl;
				//additional private members:
				//	1 helmet,
				//cout << "HELLO!!!!!!!!!!!!!!!" << helmet << endl;
				myStream << (helmet? 1: 0) << endl;
				//	2 rings,
				myStream << (rings? 1: 0) << endl;
				//	1 weapon,
				myStream << (weapon? 1: 0) << endl;
				//	1 shield,
				myStream << (shield? 1: 0) << endl;
				//	1 armor,
				myStream << (armor? 1: 0) << endl;
				//	1 belt,
				myStream << (belt? 1: 0) << endl;
				//	1 boots
				myStream << (boots? 1: 0) << endl;

				myStream.close();
			}
		}
		//TODO make helper function here: to avoid duplicating this code:
		//then no else , just continue, all is good now:

		myStream << getLevel() << endl;///level
		myStream << getArmorClass() << endl;
		myStream << getAttackBonus() << endl;
		myStream << getCharisma() << endl;
		myStream << getConstitution() << endl;
		myStream << getDamageBonus() << endl;
		myStream << getDexterity() << endl;
		myStream << getHitPoints() << endl;
		myStream << getIntelligence() << endl;
		myStream << getStrength() << endl;
		myStream << getWisdom() << endl;
		//additional private members:
		//	1 helmet,
		//cout << "HELLO!!!!!!!!!!!!!!!" << helmet << endl;
		myStream << (helmet? 1: 0) << endl;
		//	2 rings,
		myStream << (rings? 1: 0) << endl;
		//	1 weapon,
		myStream << (weapon? 1: 0) << endl;
		//	1 shield,
		myStream << (shield? 1: 0) << endl;
		//	1 armor,
		myStream << (armor? 1: 0) << endl;
		//	1 belt,
		myStream << (belt? 1: 0) << endl;
		//	1 boots
		myStream << (boots? 1: 0) << endl;

		myStream.close();




		//DONT FORGET THE ITEM CONTAINER


		//create dir if it doesn't exist yet:
		LPCWSTR outerDir2 = L"C:\\massive-octo-nemesis_DnD";
		CreateDirectoryW(outerDir2, NULL);

		//again, for the inner level:
		LPCWSTR innerDir2 = L"C:\\massive-octo-nemesis_DnD\\Names";
		CreateDirectoryW(innerDir2, NULL);

		//try to open it or create the file:
		myStream.open("C:\\massive-octo-nemesis_DnD\\Names\\characterNames.txt", ios_base::out | ios_base::app);
		if(!myStream.is_open()) {
			//if it failed try to create the file:
			myStream.open("C:\\massive-octo-nemesis_DnD\\Names\\characterNames.txt", std::fstream::trunc);
			if(!myStream.is_open()) {
				cout << "Error opening characetrNames file" << endl;
				//system("Pause");
				return;// 0;
			} else {
				//than all is good now, continue with reading the file.
				myStream.open("C:\\massive-octo-nemesis_DnD\\Names\\characterNames.txt", ios_base::out | ios_base::app);
				myStream << CharName << endl;
				myStream.close();
			}
		} else {
			//TODO: make helper function to avoid duplicate code block
			//than all is good now, continue with reading the file.
			myStream << CharName << endl;
			myStream.close();
		}








	}


	Fighter* Fighter::LoadCharacterFromFile()
	{
		std::string CharName;
		std::string InformationTextFile;
		std::string characterNames;
		std::string characterNamesFile;
		std::string HELDSTRING;
		std::string HS2;

		std::string inputs;

		std::ifstream myStream;
		std::ifstream mySecondStream;

		std::vector<std::string> tempArray;
		std::vector<std::string> NameArray;
		std::vector<int> valueArray;
		std::vector<std::string> ItemTypeArray;
		std::vector<std::string> EnhancementTypeArray;
		//std::vector<int> HS2;
		std::string k;
		std::string s;


		//std::vector<int> characterParams(30);


		cout << endl;//make it cleaner

		myStream.open("C:\\massive-octo-nemesis_DnD\\Names\\characterNames.txt");
		if(!myStream.is_open())
		{
			cout << "Error opening file, creating new character instead: " << endl;
			//system("Pause");
			//return 0;
			returnedFighter = new Fighter(1);
			return returnedFighter;
		}
		else
		{
			cout << "Select a Character Name to Load" << endl;

			while(getline(myStream, HELDSTRING, '\n'))
			{
				cout << HELDSTRING << endl;
			}
			myStream.close();

			while(true)
			{
				cout << "Select a Character Name to Load" << endl;
				cin >> inputs;
				CharName = (inputs + "_Character.txt");
				myStream.open("C:\\massive-octo-nemesis_DnD\\Characters\\" + CharName);
				if(myStream.good())
				{
					int i=0;
					while(getline(myStream, HS2, '\n'))
					{
						//cout << "DERP DERP" << HS2 << endl;
						characterParams.push_back(stoi(HS2));
						i++;
					}
					//getline(myStream, HELDSTRING, '\n');
					//cout << HELDSTRING << endl;
					myStream.close();
					break;

					/*THIS IS WHERE WE GET INFORMATION FOR THE GAME */
				}
			}
			returnedFighter = new Fighter(characterParams, 1);
			return returnedFighter;
		}
	}

	//bool Fighter::pickUp(d20Items::Item* item) //hyo
	bool Fighter::pickUp(int itVl) //hyo
	{
		char input = ' ';
		cout << "Pick up " << /*item->toString() << */ " 'Y' or 'N' ?" << endl;
		do{ 
			cin >> input;
			cout <<endl;
			if(input == 'Y' || input == 'y') {
				//this->setBoots(item); // that will be correct in the future ...
				//right now it's just an int value for the number of boots:
				//this->setBoots(this->boots+1);
				std::string itemName = identifyItemOnMap(itVl);
				setItemToPla(itemName);
				return true;
			} else if(input == 'N' || input == 'n') {
				return false;
			} else {
				cout << "Please enter 'Y' for yes or 'N' for no." << endl;
			}
		}while(input != 'Y' || input != 'N');

	}

	std::string Fighter::identifyItemOnMap(int itVal)
	{
		std::string itName;
		if(itVal == 13){
			itName = "Armor";
			return itName;
		}else if(itVal == 14){
			itName = "Belt";
			return itName;
		}else if(itVal == 15){
			itName = "Boots";
			return itName;
		}else if(itVal == 16){
			itName = "Helmet";
			return itName;
		}else if(itVal == 17){
			itName = "Ring";
			return itName;
		}else if(itVal == 18){
			itName = "Shield";
			return itName;
		}else{ //itVal == 19
			itName = "Weapon";
			return itName;
		}
	}

	void Fighter::setItemToPla(std::string itemName)
	{
		if(itemName == "Armor"){
			d20Items::Item* item  = new d20Items::Item("Armor");
			this->setArmor(item);
		}else if(itemName == "Belts"){
			d20Items::Item* item  = new d20Items::Item("Belts");
			this->setBelt(item);
		}else if(itemName == "Boots"){
			d20Items::Item* item  = new d20Items::Item("Boots");
			this->setBoots(item);
		}else if(itemName == "Helmet" ){
			d20Items::Item* item  = new d20Items::Item("Helmet");
			this->setHelmet(item);
		}else if(itemName == "Ring"){
			d20Items::Item* item  = new d20Items::Item("Ring");
			this->setRings(1);
		}else if(itemName == "Shield"){
			d20Items::Item* item  = new d20Items::Item("Shield");
			this->setShield(item);
		}else{ //itVal == 19
			d20Items::Item* item  = new d20Items::Item("Weapon");
			this->setWeapon(item);
		}
	}
} /* namespace d20Characters */
