#pragma once
#include "Item.h"
#include "ChestBuilder.h"

namespace d20Items
{

class ChestDirector
{
public:
	ChestDirector(void);

	virtual ~ChestDirector(void);

	void setChestBuilder(ChestBuilder*);

	ItemContainer* getChest();

	void constructChest();

private:
	ChestBuilder* chestBuilder;

};

} //d20Items namespace