///*****************************************************//
//******* Assignent 2: Observer Pattern ****************//
//		Property of Nathan MacInnes 1957341
//			Concordia University

//		Driver for the ItemContainer

#include "stdafx.h"
#include "IItemContainer.h"
#include "ItemContainer.h"
#include "Observer.h"
#include "ConsoleOut.h"
#include "Item.h"
#include "Weapon.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
#include "Ring.h"
#include "Belt.h"
#include "Boots.h"
#include <string> 
#include <ctime>
#include <cstdlib>

using namespace std;

// receive user input to remove an item from the container
void removeItem(ItemContainer*&);

int main()
{
	cout << "The following is a small example of the Observer Pattern" << endl;
	cout << "implemented on the Item Container." << endl << endl;

	// set time to null for the random function
	srand(time(NULL));
	
	Item* weapon1 = new Weapon("Sword of Ice Storm");
	Item* helmet1 = new Helmet("Ice Storm Heml");
	Item* armor1 = new Armor("Ice Storm Armor");
	Item* shield1 = new Shield("Ice Storm Shield");
	Item* ring1 = new Ring("Ice Storm Shield");
	Item* belt1 = new Belt("Ice Storm Belt");
	Item* boots1 = new Boots("Ice Storm Boots");

	// Create an item container called 'chest'
	ItemContainer *chest = new ItemContainer();

	// add Items to the chest
	chest->add(weapon1);
	chest->add(helmet1);
	chest->add(armor1);
	chest->add(shield1);
	chest->add(ring1);
	chest->add(belt1);
	
	// Instantiate a concrete observer of type ConsoleOutput
	// and register it to the chest
	ConsoleOut *output = new ConsoleOut(chest);

	//add boots to the chest
	cout << "Adding " << boots1->toString() << " to the contianer" << endl << endl;
	chest->add(boots1);
	
	// allow user to remove an item or items if they wish
	removeItem(chest);
	
	cout << endl;
	cout << "This has been a demo of Nathan MacInnes's Item Container" << endl;
	cout << "using the observer pattern." << endl;
	cout << "Peace out!" << endl;

	// Wait for user input to end the program
	system("pause");

	return 0;
}

void removeItem(ItemContainer* &items) {
	int itemNumber = -1;
	char confirm = NULL;

	cout << "If you would like to remove an item," << endl;
	cout << "enter the number corresponding to " << endl;
	cout <<	"the item you would like to remove." << endl;
	cout << "If you do not wish to remove a number enter 0" << endl;

	

	do 
	{
		cin >> itemNumber;
		cout << endl;
		if(itemNumber == 0)
			break;
		if(itemNumber <= items->getSize()) {
			cout << "Removing " << items->at(itemNumber - 1)->toString() << endl;
			items->remove(items->at(itemNumber - 1));
		}
		else
		{
			cout << "That is not a valid choice" << endl;
		}
	}
	while(itemNumber != 0);
}