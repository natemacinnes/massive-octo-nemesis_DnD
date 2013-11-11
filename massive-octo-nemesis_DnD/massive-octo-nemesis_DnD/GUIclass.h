#pragma once
/*
 * GUIclass.h
 *
 *  Created on: Nov 5, 2013
 *      Author: nick
 */

#include "Observer.h"
#include "Observable.h"
#include "character.h"

namespace d20Characters {

class GUIclass: public Observer {

public:
	GUIclass();

	virtual ~GUIclass();

	//register to watch and reflect changes on fighter, and keep a reference to that fighter to print its changes later:
	void registerToObservable(character *obs); // optional really, must be done anyways from the main.
	//using Observer::onEvent;
	virtual void onEvent();

private:
	std::vector<character*> listOfObservables_vector;
	std::vector<character*>::iterator iter;

};

} /* namespace d20Characters */