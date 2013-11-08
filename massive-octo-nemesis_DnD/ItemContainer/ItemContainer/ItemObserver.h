#pragma once
#include "IItemContainer.h"

namespace d20Items {

class IItemContainer;

// Observer Interface a pure virtual class allowing the concrete observers to receive notifications from the observable subjects in the observer pattern

class ItemObserver
{
public:
	virtual ~ItemObserver(void);
	
	virtual void update(IItemContainer*) = 0;

protected:
	ItemObserver(void);
};
} // namespace d20Items 