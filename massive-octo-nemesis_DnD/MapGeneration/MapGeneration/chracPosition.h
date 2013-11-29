#pragma once
//#include <string>
//#include "Map.h"

class chracPosition{

public:
	chracPosition();
	chracPosition(int, int);
	int getRow();
	int getCol();
	void setChracterPosition(int, int);
	
	//chracPosition getCharacterRow();
	
	void print();

private:
	int rowPosition;
	int colPosition;

};