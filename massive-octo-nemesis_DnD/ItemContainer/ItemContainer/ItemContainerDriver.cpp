///*****************************************************//
//******* Assignent 3: Builder Pattern ****************//
//		Property of Nathan MacInnes 1957341
//			Concordia University

//		Driver for the ItemContainer

#include "stdafx.h"
#include "IItemContainer.h"
#include "ItemContainer.h"
#include "ItemObserver.h"
#include "ConsoleOut.h"
#include "Item.h"
#include "Weapon.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
#include "Ring.h"
#include "Belt.h"
#include "Boots.h"
#include "Bow.h"
#include "ChestBuilder.h"
#include "ChestDirector.h"
#include "LeveledChestBuilder.h"
#include "RandomChestBuilder.h"
#include <string> 
#include <ctime>
#include <cstdlib>

using namespace std;

using namespace d20Items;

// receive user input to remove an item from the container
void removeItem(ItemContainer*&);

int main()
{
	cout << "The following is a small example of the Builder Pattern" << endl;
	cout << "implemented on the Item Container." << endl << endl;
	
	// set time to null for the random function
	srand(time(NULL));

	cout << "Initializing the Chest Director..." << endl;
	ChestDirector cDirector;


	cout << "Initializing a level 4, 11, and 19 Leveled Chest Builder." << endl <<endl;
	ChestBuilder* lChestBuilder4 = new LeveledChestBuilder(4);
	ChestBuilder* lChestBuilder11 = new LeveledChestBuilder(11);
	ChestBuilder* lChestBuilder19 = new LeveledChestBuilder(19);

	cout << "Initializing two Random Chest Builders." << endl <<endl;
	ChestBuilder* rChestBuilder1 = new RandomChestBuilder();
	ChestBuilder* rChestBuilder2 = new RandomChestBuilder();

	cout << "Telling the director to use the Leveled Chest Builder to" << endl;
	cout << "build a level 4 chest (ItemContainer) with the Leveled Chest Builder." << endl;
	cDirector.setChestBuilder(lChestBuilder4);
	cDirector.constructChest();
	
	cout << "Getting the chest built by the Chest Director" << endl << endl;
	ItemContainer* leveledChest4 = cDirector.getChest();

	cout << "Telling the director to use the Leveled Chest Builder to" << endl;
	cout << "build a level 11 chest (ItemContainer) with the Leveled Chest Builder." << endl;
	cDirector.setChestBuilder(lChestBuilder11);
	cDirector.constructChest();
	
	cout << "Getting the chest built by the Chest Director" << endl << endl;
	ItemContainer* leveledChest11 = cDirector.getChest();

	cout << "Telling the director to use the Leveled Chest Builder to" << endl;
	cout << "build a level 19 chest (ItemContainer) with the Leveled Chest Builder." << endl;
	cDirector.setChestBuilder(lChestBuilder19);
	cDirector.constructChest();
	
	cout << "Getting the chest built by the Chest Director" << endl << endl;
	ItemContainer* leveledChest19 = cDirector.getChest();


	cout << "Telling the director to use the Random Chest Builder to" << endl;
	cout << "build a chest (ItemContainer) with the Random Chest Builder." << endl;
	cDirector.setChestBuilder(rChestBuilder1);
	cDirector.constructChest();

	cout << "Getting the chest buiilt by the Chest Director" << endl << endl;
	ItemContainer* randomChest1 = cDirector.getChest();

	cout << "Telling the director to use the Random Chest Builder to" << endl;
	cout << "build a chest (ItemContainer) with the Random Chest Builder." << endl;
	cDirector.setChestBuilder(rChestBuilder2);
	cDirector.constructChest();

	cout << "Getting the chest buiilt by the Chest Director" << endl << endl;
	ItemContainer* randomChest2 = cDirector.getChest();

	cout << "Here is a level 4 Leveled Chest: " << endl;
	ConsoleOut *outputLeveled = new ConsoleOut(leveledChest4);

	cout << "Here is a level 11 Leveled Chest: " << endl;
	ConsoleOut *outputLeveled1 = new ConsoleOut(leveledChest11);

	cout << "Here is a level 19 Leveled Chest: " << endl;
	ConsoleOut *outputLeveled2 = new ConsoleOut(leveledChest19);

	cout << "Here is a Random Chest: " << endl;
	ConsoleOut *outputRandom = new ConsoleOut(randomChest1);

		cout << "Here is a Random Chest: " << endl;
	ConsoleOut *outputRandom1 = new ConsoleOut(randomChest2);



	cout << endl;
	cout << "This has been a demo of Nathan MacInnes's Item Container and the Builder Pattern." << endl;
	cout << "Peace out! And enjoy the winter holidays!" << endl;

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