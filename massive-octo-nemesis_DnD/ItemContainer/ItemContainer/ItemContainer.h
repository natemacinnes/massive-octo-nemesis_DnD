#pragma once
#include <vector>
#include "IItemContainer.h"
#include "Item.h"
#include "Observer.h"

// ItemContainer class using the IItemContainer interface, equivalent to the "Concrete Subject" or "Concrete Observable" in the observer pattern 

class ItemContainer : 
	public IItemContainer
{
private:
	//Vector to hold items in the container
	vector<Item*> items;
	vector<Item*>::iterator iter;

public:

	ItemContainer ();
	
	virtual ~ItemContainer();

	// returns the size of the ItemContainer
	int getSize() const;

	// returns an item at a given location in the ItemContianer
	Item* at(int) const;

	// adds an item to the container
	void add(Item*);
	
	// removes a specified item from the container
	void remove(Item*);

};

