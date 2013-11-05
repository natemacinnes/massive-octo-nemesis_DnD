/*
 * Observer.cpp
 *
 *  Created on: Nov 5, 2013
 *      Author: nick
 */

#include "Observer.h"
#include <iostream>
using namespace std;


namespace d20Characters {

Observer::Observer() {
	// TODO Auto-generated constructor stub
	index = 0;

}

Observer::Observer(int i) {
	// TODO Auto-generated constructor stub
	index = i;

}

Observer::~Observer() {
	// TODO Auto-generated destructor stub
}

void Observer::onEvent() {
	cout << " default Observer.onEvent() triggered!" << endl;
}

} /* namespace d20Characters */
