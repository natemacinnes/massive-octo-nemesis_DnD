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
	cout << "hello from sub class!!!!!!!!! " << listOfObservables_vector.size();
	for (int i = 0; i < listOfObservables_vector.size(); i++) {
		cout << endl << " PRINTING CHARACTER STATS TO REFLECT CHANGES TO FIGHTER ... "
				<< listOfObservables_vector.size();
		listOfObservables_vector[i]->printCharacterStats();
		//cout << "hello";
	}
}

void GUIclass::registerToObservable(character *obs) {

	this->listOfObservables_vector.push_back(obs);
	cout << "!! PUSHED TO VECTOR!!!" << listOfObservables_vector.size();
	obs->registerObserver(this);
	cout << "worked..........";

}

} /* namespace d20Characters */
