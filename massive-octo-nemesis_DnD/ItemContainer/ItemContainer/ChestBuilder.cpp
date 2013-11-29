#include "stdafx.h"
#include "ChestBuilder.h"

namespace d20Items
{

ChestBuilder::ChestBuilder(void)
{
}


ChestBuilder::~ChestBuilder(void)
{
}

ItemContainer* ChestBuilder::getChest() const
{
	return chest;
}

void ChestBuilder::fillItemContainer() const
{
}

void ChestBuilder::createNewChest()
{
	chest = new ItemContainer;
}

Item* ChestBuilder::createRandomItem()
{
	int itemID = (rand() % 9);
	Item* item;

	switch(itemID)
	{
		case 0:
			return item = new Armor("Armor of ");
			break;
		case 1:
			return item = new Belt("Belt of ");
			break;
		case 2:
			return item = new Boots("Boots of ");
			break;
		case 3:
			return item = new Bow("Bow of ", 20);
			break;
		case 4:
			return item = new Bracers("Bracers of ");
			break;
		case 5:
			return item = new Helmet("Helmet of ");
			break;
		case 6:
			return item = new Ring("Ring of ");
			break;
		case 7:
			return item = new Shield("Shield of ");
			break;
		case 8:
			return item = new Sword("Sword of ");
			break;
		default:
			return item = new Item("Default Item");
			break;
	}
}

}// d20Items namespace