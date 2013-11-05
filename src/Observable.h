/*
 * Observable.h
 *
 *  Created on: Nov 4, 2013
 *      Author: nick
 */

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_
//#include <list>
//using namespace std;
#include <vector>
#include <iostream>
#include "Observer.h"
//#include <boost/shared_ptr.hpp>

namespace d20Characters {

class Observable {

private:
	std::vector<Observer*> listOfObservers_vector;
	std::vector<Observer*>::iterator iter;

public:
	//Observable(): listOfObservers() {};
	Observable();
	~Observable();
	//2 methods essential to observer pattern:
	void registerObserver(Observer *obs);
protected:
	void notifyAllObservers();

};

} /* namespace d20Characters */
#endif /* OBSERVABLE_H_ */
