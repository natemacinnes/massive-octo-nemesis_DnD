#pragma once
#include "Observer.h"
#include <vector>

using namespace std;

class Observer;

// Interface for the ItemContainer and equivalent to "Subject" or "Observable" in the observer pattern

class IItemContainer
{
public:
	virtual ~IItemContainer(void);

	// Attaches an observer to the ItemContainer
	virtual void attach(Observer*);

	// Detaches an observer currently attached to the observer
	virtual void detach(Observer*);

	// notifies the observer that the ItemContainer has changed
	virtual void notify();


protected:
	IItemContainer(void);

private:
	// vector that holds the observers
	vector<Observer*> _observers;
};