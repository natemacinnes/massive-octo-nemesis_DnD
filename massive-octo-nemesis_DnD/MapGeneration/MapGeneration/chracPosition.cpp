#include "stdafx.h"
#include "chracPosition.h"
#include <iostream>
//#include <string>
//include <map>
//#include "Map.h"

chracPosition::chracPosition()
{
	rowPosition = 0;
	colPosition = 0;
}

 chracPosition::chracPosition(int r, int c){
	
	rowPosition = r;
	colPosition = c;
	

}

int chracPosition::getRow(){
	return rowPosition;
}

int chracPosition::getCol(){
	return colPosition;
}

void chracPosition::setChracterPosition(int newRow, int newCol){
 
	rowPosition=newRow;
	colPosition=newCol;
	//pos=chracPosition(newRow,newCol);

}

void chracPosition::print()
{
	std::cout << rowPosition << " " << colPosition;
}

//chracPosition chracPosition::getCharacterPosition(Map m,string name){
	//map<string,chracPosition> loc =m.getLocation();


	//chracPosition pos= loc.find(name)->second;
	//return pos;
	
//}