/*
 * Observable.cpp
 *
 *  Created on: Nov 4, 2013
 *      Author: nick
 */

#include "Observable.h"
//#include <list>
#include <vector>
using namespace std;
#include <iostream>
#include "Observer.h"
#include "GUIclass.h"

namespace d20Characters {

Observable::Observable() {

}

Observable::~Observable() {
}

void Observable::registerObserver(Observer *obs) {

	this->listOfObservers_vector.push_back(obs); //(new GUIclass());//(obs); // TODO put obs back in!

}

void Observable::notifyAllObservers() {
	for (int i = 0; i < listOfObservers_vector.size(); i++) {
		listOfObservers_vector[i]->onEvent();
	}

}

} /* namespace d20Characters */
