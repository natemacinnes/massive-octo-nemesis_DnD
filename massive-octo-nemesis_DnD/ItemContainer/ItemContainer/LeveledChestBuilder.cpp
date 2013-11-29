#include "stdafx.h"
#include "LeveledChestBuilder.h"

namespace d20Items
{

LeveledChestBuilder::LeveledChestBuilder(int level)
{
	this->level = level;
}

LeveledChestBuilder::~LeveledChestBuilder(void)
{
}

/*
void LeveledChestBuilder::createNewChest()
{
	//chest = new ItemContainer;
}
*/
// takes in level in this instance, in game will take in a character object
void LeveledChestBuilder::buildRandomItems()
{
	int eValue = leveledEnchantmentValue();

	int CHEST_SIZE = leveledRandomSize();

	for(int i = 0; i < CHEST_SIZE; i++)
	{
		Item* item;

		item = createRandomItem();

		item->getEnchantment().setEnchantmentValue(eValue);
		
		chest->add(item);

	}
}

int LeveledChestBuilder::leveledEnchantmentValue()
{	
	// Set up distribution
    double interval[] = {1, 2, 3, 4, 5, 6};
    double weights[] =  {(20 - level)*(0.2), (20 - level)*(0.4), 0.2, (level*.4), (level*.2)};
    std::piecewise_constant_distribution<> dist(std::begin(interval),
                                                std::end(interval),
                                                std::begin(weights));
	
	std::random_device rd;
	std::mt19937 gen(rd());

	unsigned r = static_cast<unsigned>(dist(gen));
	
	return r;


}
int LeveledChestBuilder::leveledRandomSize()
{
	double probs[] = {(20 - level)*(0.002), (20 - level)*(0.004), 0.2, (level*.004), (level*.002)};
	
	// Set up distribution
    double interval[] = {1, 3, 7, 10, 13};
    double weights[] =  {(20 - level)*(0.2), (20 - level)*(0.4), 0.2, (level*.4), (level*.2)};
    std::piecewise_constant_distribution<> dist(std::begin(interval),
                                                std::end(interval),
                                                std::begin(weights));
	
	std::random_device rd;
	std::mt19937 gen(rd());

	unsigned r = static_cast<unsigned>(dist(gen));
	
	return r;
}

} // d20Items namespace