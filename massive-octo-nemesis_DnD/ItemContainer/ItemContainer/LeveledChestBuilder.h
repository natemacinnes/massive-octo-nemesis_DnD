#pragma once
#include "chestbuilder.h"
#include <random>
#include <iostream>
#include <vector>

namespace d20Items
{

class LeveledChestBuilder :
	public ChestBuilder
{
public:
	LeveledChestBuilder(void);

	LeveledChestBuilder(int);

	virtual ~LeveledChestBuilder(void);

	//virtual void createNewChest();

	void buildRandomItems();

	int getEnchantmentValue(int);

private:
	int level;

	int leveledEnchantmentValue();

	int leveledRandomSize();
};

} //d20Items namespace
