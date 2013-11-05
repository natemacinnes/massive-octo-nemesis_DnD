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

Observable::Observable() { //:	listOfObservers() {
	// TODO Auto-generated constructor stub

//	//listOfObservers = {Observer1 myobs(42), Observer2 myobs(41)};
//    for (int i = 0; i < MAX_SIZE; i++){
//
//    	Observer myobs(56);
//    	listOfObservers[i] = Observer(56);
//
//    }

}

Observable::~Observable() {
	// TODO Auto-generated destructor stub
}

void Observable::registerObserver(Observer *obs) {

	this->listOfObservers_vector.push_back(obs);//(new GUIclass());//(obs); // TODO put obs back in!

}

void Observable::notifyAllObservers() {
	//for (std::list<Observer*>::const_iterator iterator = listOfObservers.begin(), end = listOfObservers.end(); iterator != end; ++iterator) {
	//  std::cout << *iterator;
	//}
	//std::list<Observer*>::const_iterator iter = this->listOfObservers.begin();

	//typedef std::list<Observer*>::const_iterator entityIter;

//	for ( std::list<Observer*>::const_iterator entityIter = this->listOfObservers.begin(),
//	     end = this->listOfObservers.end();
//	     iter != end;
//	     ++iter)
//	{
//	    //(*iter)->print();
//	}

//	  for(list<Observer*>::const_iterator iter = listOfObservers.begin();
//	      iter != listOfObservers.end(); ++iter)
//	    {
//	      cout << ">> " << (*iter)->getName() << endl;
//	    }

//	typedef std::list<Observer*> listMyClass;
//	listMyClass instance; // instance, you shouldn't use type in the following loop
//
//	for( listMyClass::iterator listMyClassIter = instance.begin(); // not listMyClass.begin()
//	    listMyClassIter != instance.end(); // not listMyClass.end()
//	    listMyClassIter ++)
//	{
//	    (*listMyClassIter)->PrintMeOut();
//	}

//	Observer *obs1 = new Observer(90);
//	Observer *obs2 = new Observer(91);
//	Observer *obs3 = new Observer(92);
//	Observer *obs4 = new Observer(93);
//	listOfObservers_vector.push_back(obs1);
//	listOfObservers_vector.push_back(obs2);
//	listOfObservers_vector.push_back(obs3);
//	listOfObservers_vector.push_back(obs4);
	//cout << "adding to vector ... ?";

//	for (vector<Observer*>::const_iterator i = listOfObservers_vector.begin();
//			i != listOfObservers_vector.end(); ++i) {
//		// process i
//		cout  << " vector??? "; // this will print all the contents of *features*
//		//(*i).index <<
//	}
	for (int i = 0; i < listOfObservers_vector.size(); i++) {
		cout << " vector? ... " << listOfObservers_vector[i]->index;
		//listOfObservers_vector[i]->onEvent(); // object slicing problem
		//listOfObservers_vector.at(i)->onEvent(); // still object slicing
		//(*listOfObservers_vector[i]).onEvent();
		listOfObservers_vector[i]->onEvent();
	}

//	for (int i = 0; i < MAX_SIZE; i++) {
//
//		Observer myobs(56);
//		listOfObservers[i] = Observer(56);
//
//	}

//	for (int i = 0; i < MAX_SIZE; i++)
//		cout << " HELLO " << listOfObservers[i].index;
}

} /* namespace d20Characters */
