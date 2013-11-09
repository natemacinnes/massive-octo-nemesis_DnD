#include "stdafx.h"
#include <list>
#include <iterator>
#include <iostream>
#include "MapObserver.h"
#include "MapObservable.h"

using namespace std;

MapObservable::MapObservable() 
{
}

MapObservable::~MapObservable()
{
}

void MapObservable::attach(MapObserver* ob){

	mapObs.push_back(ob);

}

void MapObservable::detach(MapObserver* ob){
	//mapObs.remove(ob);
}

void MapObservable::notify(){
	for( int i=0; i< mapObs.size();i++){
		std::cout << "Notifying " << i << endl;
		mapObs[i]->update(this);
	}
	
}

