#pragma once
#include "ItemObserver.h"
#include <vector>

namespace d20Items {

class ItemObserver;

// Interface for the ItemContainer and equivalent to "Subject" or "Observable" in the observer pattern

class IItemContainer
{
public:
	virtual ~IItemContainer(void);

	// Attaches an observer to the ItemContainer
	virtual void attach(ItemObserver*);

	// Detaches an observer currently attached to the observer
	virtual void detach(ItemObserver*);

	// notifies the observer that the ItemContainer has changed
	virtual void notify();


protected:
	IItemContainer(void);

private:
	// vector that holds the observers
	std::vector<ItemObserver*> _observers;
};
} // namespace d20Items 