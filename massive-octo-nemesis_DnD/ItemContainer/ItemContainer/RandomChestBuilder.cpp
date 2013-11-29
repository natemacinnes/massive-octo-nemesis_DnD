#include "stdafx.h"
#include "RandomChestBuilder.h"

namespace d20Items
{

RandomChestBuilder::RandomChestBuilder(void)
{
}


RandomChestBuilder::~RandomChestBuilder(void)
{
}

void RandomChestBuilder::buildRandomItems()
{
	int eValue = 1 + rand() % 5;
	int CHEST_SIZE = 1 + rand() % 13;

	for(int i = 0; i < CHEST_SIZE; i++)
	{
		Item* item;

		item = createRandomItem();

		item->getEnchantment().setEnchantmentValue(eValue);
		
		chest->add(item);

	}
}

} // d20Items namespace