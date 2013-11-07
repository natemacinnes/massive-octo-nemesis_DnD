#pragma once
#include <iostream>
#include <vector>
#include "MapObserver.h"
using namespace std;

class Map
{

public:
  
	Map(vector <vector<int> >,int, int);
	vector < vector <int> > static fillUpMap(vector <vector <int> >, int, int );
	void static displayMap (vector < vector <int> >, int, int);
	void static  mapDesign (vector < vector <int> >, int, int);
	bool validatingMap(vector < vector <int> >&, int, int);
	bool setCell (vector < vector <int> >&, int, int);
	bool move(vector<vector<int>>&, int, int);
	void attach( MapObserver *myMap);
    void detach( MapObserver *myMap);
    void notifyObs();
	~Map(void);
	int getMapRow();
	int getMapCol();
	vector<vector<int>> getMapVector();
	int getRowStart();
	int getColStart();
	

	class Validation{
	public:
		int static getRow(int);
		int static getCol(int);
		int static validateRowInput(int);
		int static validateColInput(int);
		bool static checkingPositionAssigned(vector < vector <int> >, int, int);
		bool static checkingEndAssigned(vector < vector <int> >, int, int);
		bool static setBegin(vector < vector <int> >&, int, int);
		bool static setEnd(vector < vector <int> >&, int, int);
		bool static validationNewStart(vector<vector<int>>&, int, int, int, int);
	};

private:
	vector< vector <int> > myMap;
	int row;
	int col;
    vector<MapObserver *> myObs; //vector containing mapObserver pointer  

    
};