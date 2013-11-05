/*
 * Observer.h
 *
 *  Created on: Nov 5, 2013
 *      Author: nick
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

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
#endif /* OBSERVER_H_ */
