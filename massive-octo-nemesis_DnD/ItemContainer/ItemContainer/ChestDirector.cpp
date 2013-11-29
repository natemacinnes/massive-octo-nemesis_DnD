#include "stdafx.h"
#include "ChestDirector.h"

namespace d20Items
{

ChestDirector::ChestDirector()
{
}


ChestDirector::~ChestDirector(void)
{
}

void ChestDirector::setChestBuilder(ChestBuilder* cb)
{
	this->chestBuilder = cb;
}

ItemContainer* ChestDirector::getChest()
{
	return this->chestBuilder->getChest();
}

void ChestDirector::constructChest()
{
	chestBuilder->createNewChest();
	chestBuilder->buildRandomItems();

}

} // d20Items namespace