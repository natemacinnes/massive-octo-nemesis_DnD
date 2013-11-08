#pragma once
#include "ItemObserver.h"
#include "ItemContainer.h"

// A concrete application of an Observer
namespace d20Items {

class ConsoleOut :
	public ItemObserver
{

public:
	ConsoleOut(ItemContainer*);
	
	~ConsoleOut(void);

	void update(IItemContainer*);

	void output(void);

private:
	ItemContainer *_items;
};
} // namespace d20Items 