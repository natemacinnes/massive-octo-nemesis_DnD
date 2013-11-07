#pragma once
/*
 * Observer.h
 *
 *  Created on: Nov 5, 2013
 *      Author: nick
 */

namespace d20Characters {

class Observer {
public:
	Observer();
	Observer(int index);
	~Observer();
	int index;
	virtual void onEvent(); // = 0;
};

} /* namespace d20Characters */