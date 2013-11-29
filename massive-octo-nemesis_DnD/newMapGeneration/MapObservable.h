#pragma once
#include <vector>
using namespace std;

class MapObserver;

class MapObservable{

public:
	virtual ~MapObservable();
	virtual void attach(MapObserver *);
	virtual void detach(MapObserver *);
	virtual void notify();
	//MapObserver* at(int) const;
	vector<MapObserver*> getMyObs();

protected:
	MapObservable();

private:
	vector<MapObserver*> mapObs;
};