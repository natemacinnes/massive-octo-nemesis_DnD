#include "stdafx.h"
#include "ConsoleOut.h"
#include <iostream>

namespace d20Items {

ConsoleOut::ConsoleOut(ItemContainer* items)
{
	_items = items;
	_items->attach(this);
	output();
}


ConsoleOut::~ConsoleOut(void)
{
	_items->detach(this);
}

void ConsoleOut::update(IItemContainer* modifiedIC)
{
	if(modifiedIC == _items)
	{
		std::cout << "ItemContainer updated: " << std::endl;
		output();
	}	
}

void ConsoleOut::output(void)
{
	for( int i = 0; i < _items->getSize(); i++)
	{
		std::cout << i + 1 << ". " << (_items->at(i)->toString()) << std::endl;
	}
	std::cout << std::endl;
}
} // namespace d20Items 