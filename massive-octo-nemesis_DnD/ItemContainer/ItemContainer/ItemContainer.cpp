#include "stdafx.h"
#include "ItemContainer.h"

ItemContainer::ItemContainer(void) 
{
	this->items;
}

ItemContainer::~ItemContainer() 
{

}

int ItemContainer::getSize() const
{
	return items.size();
}

Item* ItemContainer::at(int i) const 
{
	return items.at(i);
}

void ItemContainer::add(Item* item)
{
	items.push_back(item);
	notify();
}

void ItemContainer::remove(Item* item)
{
	iter = items.begin();

	while (iter != end(items)) 
	{
		if (item->getName() == (*iter)->getName())
		{
			iter = items.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	notify();
}