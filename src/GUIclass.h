/*
 * GUIclass.h
 *
 *  Created on: Nov 5, 2013
 *      Author: nick
 */

#ifndef GUICLASS_H_
#define GUICLASS_H_
#include "Observer.h"

namespace d20Characters {

class GUIclass : public Observer {
public:
	GUIclass();
	virtual ~GUIclass();
	//register to watch and reflect changes on fighter:
	void registerToObservable(); // optional really, must be done anyways from the main.

//	using character::setStrength;
//	void setStrength(int strength);

};

} /* namespace d20Characters */
#endif /* GUICLASS_H_ */
