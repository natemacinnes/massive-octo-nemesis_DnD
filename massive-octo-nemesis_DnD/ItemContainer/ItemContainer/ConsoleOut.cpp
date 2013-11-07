#include "stdafx.h"
#include "ConsoleOut.h"
#include <iostream>


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
		cout << "ItemContainer updated: " << endl;
		output();
	}	
}

void ConsoleOut::output(void)
{
	for( int i = 0; i < _items->getSize(); i++)
	{
		cout << i + 1 << ". " << (_items->at(i)->toString()) << endl;
	}
	cout << endl;
}

