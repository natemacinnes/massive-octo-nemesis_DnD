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

namespace d20Characters {

class Observable {

private:
	//std::list<int> integer_list;
	//std::list<Observer*> listOfObservers;
	//typedef list<int> IntegerList;
	//listOfObservers = list();

    std::vector<Observer*> listOfObservers_vector;
    std::vector<Observer*>::iterator iter;

	static const unsigned MAX_SIZE = 2;
	Observer listOfObservers[MAX_SIZE];

public:
	//Observable(): listOfObservers() {};
	Observable();
	~Observable();
	//2 methods essential to observer pattern:
	void registerObserver(Observer *obs);
	void notifyAllObservers();


};

} /* namespace d20Characters */
#endif /* OBSERVABLE_H_ */
