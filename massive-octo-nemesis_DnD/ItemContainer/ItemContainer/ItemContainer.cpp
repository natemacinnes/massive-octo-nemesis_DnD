#include "stdafx.h"
#include "ItemContainer.h"

namespace d20Items {

ItemContainer::ItemContainer(void) 
{
	this->items;
}

ItemContainer::~ItemContainer() 
{

}

int ItemContainer::getSize() const
{
	return items.size();
}

Item* ItemContainer::at(int i) const 
{
	return items.at(i);
}


void ItemContainer::add(Item* item)
{
	items.push_back(item);
	notify();
}

void ItemContainer::remove(Item* item)
{
	iter = items.begin();

	while (iter != std::end(items)) 
	{
		if (item->getName() == (*iter)->getName())
		{
			iter = items.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	notify();
}

void ItemContainer::printItems()  {

	//test:
	//Item* item = new Weapon("Bob's Sword");
	//cout << item->toString() << endl;

	//printing the bag's content:
	//bag->add(item);
	//bag->add(new Armor("Chest Plate"));

	//std::cout << bag->at(0)->toString() << std::endl;
	//std::cout << bag->at(1)->toString() << std::endl;

	iter = items.begin();
	int i=1;
	//std::cout << "this is the size of the container: " << items.size();
	std::cout << std::endl;
	while (iter != std::end(items)) 
	{
		//std::cout << i << ". " << (*iter)->getName() << ", with enchantement: " << (*iter)->getEnchantment().toString() << std::endl; //this->at(i-1)->toString()
		std::cout << i << ". " << items.at(i-1)->getName() << ", with enchantement: " << items.at(i-1)->getEnchantment().toString() << std::endl; //this->at(i-1)->toString()
		//typeid(class).name
		//std::cout << i << ". " << typeid((&items.at(i-1))).name;// << ", with enchantement: " << items.at(i-1)->getEnchantment().toString() << std::endl; //this->at(i-1)->toString()
		//std::cout << i << ". " << items.at(i-1)->toString();// << ", with enchantement: " << items.at(i-1)->getEnchantment().toString() << std::endl; //this->at(i-1)->toString()
		iter++;
		i++;
	}

	notify();

}
} // namespace d20Items 


/*	*/