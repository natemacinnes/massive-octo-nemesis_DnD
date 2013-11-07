#pragma once
#include "Observer.h"
#include "ItemContainer.h"

// A concrete application of an Observer

class ConsoleOut :
	public Observer
{

public:
	ConsoleOut(ItemContainer*);
	
	~ConsoleOut(void);

	void update(IItemContainer*);

	void output(void);

private:
	ItemContainer *_items;
};

