#include "stdafx.h"
#include "IItemContainer.h"
#include <iostream>

namespace d20Items {

IItemContainer::IItemContainer(void)
{
}

IItemContainer::~IItemContainer(void)
{
}

void IItemContainer::attach(ItemObserver* o)
{
	_observers.push_back(o);
}

void IItemContainer::detach(ItemObserver* o)
{
	//_observers.remove(o);
}

void IItemContainer::notify()
{
	for(unsigned int i = 0; i < _observers.size(); i++ )
		_observers[i]->update(this);
}
} // namespace d20Items 