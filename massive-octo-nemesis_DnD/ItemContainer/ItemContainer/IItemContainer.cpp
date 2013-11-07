#include "stdafx.h"
#include "IItemContainer.h"
#include <iostream>


IItemContainer::IItemContainer(void)
{
}

IItemContainer::~IItemContainer(void)
{
}

void IItemContainer::attach(Observer* o)
{
	_observers.push_back(o);
}

void IItemContainer::detach(Observer* o)
{
	//_observers.remove(o);
}

void IItemContainer::notify()
{
	for(unsigned int i = 0; i < _observers.size(); i++ )
		_observers[i]->update(this);
}