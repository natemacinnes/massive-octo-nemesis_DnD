/*
 * GUIclass.cpp
 *
 *  Created on: Nov 5, 2013
 *      Author: nick
 */

#include "GUIclass.h"
#include <iostream>
using namespace std;
#include "character.h"

namespace d20Characters {

GUIclass::GUIclass() {
}

GUIclass::~GUIclass() {
}

void GUIclass::onEvent() {
	//every time there's a change in one fighter, refresh the whole list.

	for (int i = 0; i < listOfObservables_vector.size(); i++) {
		listOfObservables_vector[i]->printCharacterStats();
	}
}

void GUIclass::registerToObservable(character *obs) {

	this->listOfObservables_vector.push_back(obs);
	obs->registerObserver(this);

}

} /* namespace d20Characters */
