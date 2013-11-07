#pragma once
#include "IItemContainer.h"

class IItemContainer;

// Observer Interface a pure virtual class allowing the concrete observers to receive notifications from the observable subjects in the observer pattern

class Observer
{
public:
	virtual ~Observer(void);
	
	virtual void update(IItemContainer*) = 0;

protected:
	Observer(void);
};
