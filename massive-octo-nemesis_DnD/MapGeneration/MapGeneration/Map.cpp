#pragma once
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <limits>
#include <ctype.h>
#include <string>
#include <iterator>
#include <map>
#include "Map.h"
#include "MapObservable.h"
#include "chracPosition.h"
#include "GUIclass.h"


using namespace std;

int static rowStart;
int static colStart;
int static rowEnd;
int static colEnd;

Map::Map(void) 
{
}

Map::~Map(void)
{
}


Map::Map (vector<vector<int>> &v,int r, int c) {
	this->row = r;
	this->col = c;
	this->myMap = v;
	this->myObs;

	//ask the user if he wants to reload a character previously saved in a file or create a new one:
	bool isgoodanswer = false;
	while(isgoodanswer == false){
		cout << "Load a character from file? (y/n) --> (enter \"n\" to create a new character)" << endl;
		string doLoadChar;
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n' ); //ignores whatever apeared after the previous input
		cin >> doLoadChar;
		if(doLoadChar == "y") {
			bob = new d20Characters::Fighter(1);
			bob = bob->LoadCharacterFromFile(); // TODO this should be static, but works for now.
			isgoodanswer = true;
		} else if(doLoadChar == "n") {
			bob = new d20Characters::Fighter(1);
			isgoodanswer = true;
		} else {
			cout << "Invalid input." << endl;
			isgoodanswer = false;
		}
	}

	//create GUI class that knows what what to do on fighter changes (e.g. refresh screen, but here just re-print):
	d20Characters::GUIclass* gui = new d20Characters::GUIclass();

	//plug the two together -- the observer (GUI object) and observable (Fighter object):
	gui->registerToObservable(bob);
}

int Map::getRowStart(){
	return rowStart;
}
int Map::getColStart(){
	return colStart;
}


chracPosition Map::getPosition() 
{
	return currentPosition;
}

int Map::getSize() const{

	return myObs.size();
}

Map* Map::at(int i) const{
	return myObs.at(i);
}

int  Map::getMapRow(){
	return row;
}
int  Map::getMapCol(){
	return col;
}
vector<vector<int>> Map::getMapVector(){
	return myMap;
}



vector < vector<int> >& Map::fillUpMap(vector<vector <int>> &m, int row, int col){

	vector<int> columns;
	//chracPosition* pos = new chracPosition();

	cout << "Let's build up your map!" <<endl;
	cout << "Enter \'1\' to fill your map with empty space (free path)" << endl;
	cout << "Enter \'2\' to fill your map with wall" << endl;
	cout << "Enter \'3\' to fill your map" << endl;

	for (int i = 0; i < row; i++) {

		m.push_back(columns);

		for (int j = 0; j < col; j++) {



			int pathChoice; //this variable will hold the user input with the required actu=ion to fill the mao with the elemented wanted
			while (!(cin >> pathChoice) || (pathChoice < 1 || pathChoice > 3) || isalpha(pathChoice)) {

				cout << "Not a valid input!\n";
				cout << "Enter 1 for free path, 2 for wall or 3 for occupied: \n";
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n' ); //ignores whatever apeared after the previous input

			}
			/*
			if(pathChoice==3){
			pos->setChracterPosition(i,j);
			//const d20Items::Item *tempItem = 
			itemLocation.insert(ItemLocation::value_type(pos, addItem2Map()));
			}*/
			m[i].push_back(pathChoice);
		}
	}

	bool isSetStart = Map::Validation::setBegin(m, row, col);
	while (isSetStart != true) {
		isSetStart = Map::Validation::setBegin(m, row, col);
	}

	bool isSetEnd = Map::Validation::setEnd(m, row, col);
	while (isSetEnd != true){ 
		isSetEnd = Map::Validation::setEnd(m, row, col);
	}


	//displayMap(m, row, col);
	//mapDesign(m,row,col);
	return m;

}

int Map::Validation::validateRowInput(int row){


	while ((isalpha(row)) || (row < 1)) {
		cout << "Not a valid input!\n";
		cout << "Enter the number of rows: \n";
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(),'\n'); //ignores whatever apeared after the previous input
		cin >> row;
	}
	return row;
}

int Map::Validation::validateColInput(int col){

	while ((isalpha(col)) || (col <= 1)) {
		cout << "Not a valid input!\n";
		cout << "Enter the number of columns: \n";
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n' ); //ignores whatever apeared after the previous input
		cin >> col;
	}

	return col;
}

void Map::displayMap (vector < vector <int> > myMap, int row, int col){

	int i=0, j=0;

	cout << "Displaying Map" << endl;	
	cout << "****************************************************************" << endl;

	cout << "+ ";
	while (i < col) {
		cout << "+ ";
		i++;
	}
	cout << "+";
	cout << endl;
	//delimitation of the map


	for (int i = 0 ; i < row; i++) {
		cout << "+ ";
		for (int j = 0 ; j <  col; j++) {
			cout << myMap[i][j] << " ";
		}
		cout << "+";
		cout << endl;
	}

	cout << "+ ";
	while (j < col) {
		cout << "+ ";
		j++;
	}
	cout << "+";
	cout << endl;
}

void Map::mapDesign (vector < vector <int> > myMap, int row, int col){

	int i = 0,j = 0;
	cout << "Displaying Map" << endl;	
	cout << "****************************************************************" << endl;


	cout << "+ ";
	while (i < col) {
		cout << "+ ";
		i++;
	}
	cout << "+";
	cout << endl;
	//delimitation of the map
	//chracPosition* pos = new chracPosition();
	for (int i = 0 ; i < row; i++) {
		cout << "+ ";
		for (int j = 0 ; j <  col; j++) {
			if (myMap[i][j] == 1) {
				cout << " " << " ";
			}else if (myMap[i][j] == 2) {
				cout << "|" << " ";
			}else if (myMap[i][j] == 3){
				//pos->setChracterPosition(i,j);
				//itemLocation.find(pos)->second;
				cout << "B" << " ";
				//const d20Items::Item *tempItem = 
				//itemLocation.insert(ItemLocation::value_type(pos, addItem2Map()));
			}else if(myMap[i][j] == 0) {
				cout << "S" << " "; // starting point;  '+' sign, where it limits the map
			}else if(myMap[i][j] == 4){
				cout << "E" << " "; // ending point; '+' sign, where it limits the map
			}else if(myMap[i][j] == 'X'){
				cout << "O" << " "; // ending point; '+' sign, where it limits the map
			}else{
				cout << "P" << " "; //start point when player leaves
			}
		}
		cout << "+";
		cout << endl;
	}

	cout << "+ ";
	while (j < col) {
		cout << "+ ";
		j++;
	}
	cout << "+";
	cout << endl;
}

bool Map::Validation::setBegin(vector < vector <int> >& myMap, int row, int  col){

	//keeps the value of the varibles cal ad row unchanged
	int const sizeRow = row;
	int const sizeCol = col;
	int r, c;


	cout << endl;
	cout << "Where is the start point of your map?\n";
	cout << "Please, enter its first coordinate.\n";
	cout << "Remember: your first parameter has to be between: 0 and " << (sizeRow-1) << " :"<< endl;

	while (!(cin >> r) || (r < 0 || r > (sizeRow-1)) || isalnum(r)) {

		cout << endl;
		cout << "Not a valid input!\n";
		cout << "Enter a number between 0 and " << (sizeRow-1)<< " :"<< endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //ignores whatever apeared after the previous input

	}

	cout << endl;
	cout << "Please, enter its second coordinate.\n";
	cout << "And your seoncd parameter has to be between: 0 and " << (sizeCol-1)<< " :" << endl;

	while (!(cin >> c) || (c < 0 || c > (sizeCol-1)) || isalpha(c)) {

		cout << endl;
		cout << "Not a valid input!\n";
		cout << "Enter a number between 0 and " << (sizeCol-1) <<" :" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //ignores whatever apeared after the previous input

	}

	bool checkStartPoint = Map::Validation::checkingEndAssigned(myMap,r,c);
	if (checkStartPoint == true) {
		cout << "Your START position is: [" <<r <<"][" << c <<"]" << endl;
		myMap[r][c] = 0; // zero will refer to the START point

		rowStart = Map::Validation::getRow(r);
		colStart = Map::Validation::getCol(c);


		return true;
	}else{
		return false;
	}
}

bool Map::Validation::setEnd(vector < vector <int> >& myMap, int endRow, int  endCol){

	//keeps the value of the varibles cal ad row unchanged
	int const sizeRow = endRow;
	int const sizeCol = endCol;
	int r, c;


	cout << endl;
	cout << "Where is the END point of your map?\n";
	cout << "Please, enter its first coordinate.\n";
	cout << "Remember: your first parameter has to be between: 0 and " << (sizeRow-1) << " :"<< endl;

	while (!(cin >> r) || (r < 0 || r > (sizeRow-1)) || isalnum(r)) {

		cout << endl;
		cout << "Not a valid input!\n";
		cout << "Enter a number between 0 and " << (sizeRow-1)<< " :"<< endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //ignores whatever apeared after the previous input

	}

	cout << endl;
	cout << "Please, enter its second coordinate.\n";
	cout << "And your seoncd parameter has to be between: 0 and " << (sizeCol-1)<< " :" << endl;

	while (!(cin >> c) || (c < 0 || c > (sizeCol-1)) || isalpha(c)) {

		cout << endl;
		cout << "Not a valid input!\n";
		cout << "Enter a number between 0 and " << (sizeCol-1) <<" :" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //ignores whatever apeared after the previous input

	}


	bool checkEndPoint = Map::Validation::checkingEndAssigned(myMap,r,c);
	if (checkEndPoint == true) {
		cout << "Your END position is: [" << r <<"][" << c <<"]" << endl;
		myMap[r][c] = 4; // four will refer to the END point
		rowEnd = Map::Validation::getRow(r);
		colEnd = Map::Validation::getCol(c);
		return true;
	}else{
		return false;
	}

}

bool Map::Validation::checkingEndAssigned(vector < vector <int> > myMap, int row, int col){


	if (myMap[row][col] == 0) {
		cout << endl;
		cout << "There is the STARTING point of your map. Sorry! Try again!\n" << endl;
		return false;
	}else{
		return true;
	}

}

bool Map::Validation::checkingPositionAssigned(vector < vector <int> > myMap, int row, int col){


	if (myMap[row][col] == 2) {
		cout << endl;
		cout << "There is a wall in it. Sorry! Try again!\n" << endl;
		return false;
	}else if (myMap[row][col] == 3) {
		cout << endl;
		cout << "This place is occupied already. Sorry! Try again!\n" << endl;
		return false;
	}else{
		return true;
	}

}

int Map::Validation::getRow(int row1){
	return row1;
}

int Map::Validation::getCol(int col1)
{
	return col1;
}	

bool Map::setCell (vector < vector <int> >& myMap, int rowChange, int colChange){
	//keeps the value of the varibles cal ad row unchanged
	int sizeRow = rowChange;
	int sizeCol = colChange;
	int r, c;
	int change;

	cout<< endl;

	//cout << ">>>PLEASE PRESS \'E\' if DO NOT want to change anything<<<\n"<<endl;
	cout << "Enter any letter to finish the changing cells or any digit to continue!"<< endl;
	/*cout << "Please, enter its first coordinate.\n";
	cout << "Remember: your first parameter has to be between: 0 and " << (sizeRow-1) << " :"<< endl;*/

	if(!(cin >> change) || isalpha(change)){
		cout << "Exiting changing mode!" << endl;
		//notifyObs();
		return true;
	}else{
		cout << "CONTINUING..." << endl;
		cout << "Which location of the map you would like to change?\n"<<endl;
		cout << "Please, enter its first coordinate.\n";
		cout << "Remember: your first parameter has to be between: 0 and " << (sizeRow-1) << " :"<< endl;
		while (!(cin >> r) || (r < 0 || r > (sizeRow-1)) || isalnum(r)) {

			cout << endl;
			cout << "Not a valid input!\n";
			cout << "Enter a number between 0 and " << (sizeRow-1)<< " :"<< endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //ignores whatever apeared after the previous input

		}


		cout << endl;
		cout << "Please, enter its second coordinate.\n";
		cout << "And your second parameter has to be between: 0 and " << (sizeCol-1)<< " :" << endl;

		while (!(cin >> c) || (c < 0 || c > (sizeCol-1)) || isalpha(c)) {

			cout << endl;
			cout << "Not a valid input!\n";
			cout << "Enter a number between 0 and " << (sizeCol-1) <<" :" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n' ); //ignores whatever apeared after the previous input

		}

	}


	if((myMap[r][c] == 0) || (myMap[r][c] == 4) ){

		if(myMap[r][c] == 0){
			cout << endl;
			cout << "Sorry, this is yor STARTING point. Please try again!" << endl;
		}else{
			cout << endl;
			cout << "Sorry, this is yor END point. Please try again!" << endl;
		}

		return false;
	}else{

		int chageValue;

		cout << endl;
		cout << "What do you want to insert there?"<<endl;

		while (!(cin >> chageValue) || (chageValue < 1 || chageValue > 3) || isalpha(chageValue)) {

			cout << endl;
			cout << "Not a valid input!\n";
			cout << "Enter 1 for free path, 2 for wall or 3 for occupied: \n";
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n' ); //ignores whatever apeared after the previous input

		}

		int previousVal = myMap[r][c]; //record previous value
		myMap[r][c] = chageValue;
		bool isValid1 = validatingMap(myMap, rowChange, colChange);
		if (isValid1 == false) {
			myMap[r][c] = previousVal;
			return false;
		}else{
			cout << endl;
			cout << "Your changed position: ["<< r <<"][" << c <<"] " << endl;
			myMap[r][c] = chageValue;
			mapDesign(myMap, rowChange, colChange);
			//notify();
			return true;
		}
	}

}

bool Map::validatingMap(vector < vector <int> >& myMap, int row, int col){

	// keeps the size of the 2D vector without changing it
	int rowValue = row;
	int colValue = col;


	int currentRow = rowStart, currentCol = colStart;
	vector<vector<int>> tempMap=myMap;

	//end point where we want to get
	int endR = rowEnd;
	int endC = colEnd;

	vector <int> valR;
	vector <int> valC;

	bool upS, downS, leftS, rightS; 
	bool upE, downE, leftE, rightE;

	//checking start point
	if(currentRow + 1 <= rowValue-1){
		if(myMap[currentRow+1][currentCol] == 2){
			downS = false;
		}else{
			if(myMap[currentRow+ 1][currentCol] == 4){
				cout << "MAP IS VALID!!" << endl;
				downS = true;
				return true;
			}else if((myMap[currentRow+1][currentCol] == 1)||(myMap[currentRow+ 1][currentCol] == 3)){
				downS = true;
			}
		}
	}else{
		downS = false;
	}

	if(currentRow-1 >= 0){
		if(myMap[currentRow-1][currentCol] == 2){
			upS = false;
		}else{
			if(myMap[currentRow-1][currentCol] == 4){
				cout << "MAP IS VALID!!" << endl;
				upS = true;
				return true;
			}else if((myMap[currentRow-1][currentCol] == 1)||(myMap[currentRow-1][currentCol] == 3)){
				upS = true;
			}
		}
	}else{
		upS = false;
	}


	if(currentCol+1 <= colValue-1){
		if(myMap[currentRow][currentCol+1] == 2){
			rightS = false;
		}else{
			if(myMap[currentRow][currentCol+1] == 4){
				cout << "MAP IS VALID!!" << endl;
				rightS = true;
				return true;
			}else if((myMap[currentRow][currentCol+1] == 1)||(myMap[currentRow][currentCol+1] == 3)){
				rightS = true;
			}
		}
	}else{
		rightS = false;
	}

	if(currentCol-1 >= 0){
		if(myMap[currentRow][currentCol- 1] == 2){
			leftS = false;
		}else{
			if(myMap[currentRow][currentCol-1] == 4){
				cout << "MAP IS VALID!!" << endl;
				leftS = true;
				return true;
			}else if((myMap[currentRow][currentCol-1] == 1) || (myMap[currentRow][currentCol-1] == 3)) {
				leftS = true;
			}
		}
	}else{
		leftS = false;
	}




	//checking end point
	if(endR + 1 <= rowValue-1){
		if(myMap[endR+1][endC] == 2){
			downE = false;
		}else{
			if(myMap[endR+1][endC] == 4){
				cout << "MAP IS VALID!!" << endl;
				downE = true;
				return true;
			}else if((myMap[endR+1][endC] == 1)||(myMap[endR+1][endC] == 3)){
				downE = true;
			}
		}
	}else{
		downE = false;
	}

	if(endR-1 >= 0){
		if(myMap[endR-1][endC] == 2){
			upE = false;
		}else{
			if(myMap[endR-1][endC] == 0){
				cout << "MAP IS VALID!!" << endl;
				upE = true;
				return true;
			}else if((myMap[endR-1][endC] == 1)||(myMap[endR- 1][endC] == 3)){
				upE = true;
			}
		}
	}else{
		upE = false;
	}


	if(endC+1 <= colValue-1){
		if(myMap[endR][endC+1] == 2){
			rightE = false;
		}else{
			if(myMap[endR][endC+1] == 0){
				cout << "MAP IS VALID!!" << endl;
				rightE = true;
				return true;
			}else if((myMap[endR][endC+1] == 1)||(myMap[endR][endC+1] == 3)){
				rightE = true;
			}
		}
	}else{
		rightE = false;
	}

	if(endC-1 >= 0){
		if(myMap[endR][endC-1] == 2){
			leftE = false;
		}else{
			if(myMap[endR][endC-1] == 0){
				cout << "MAP IS VALID!!" << endl;
				leftE = true;
				return true;
			}else if((myMap[endR][endC-1] == 1) || (myMap[endR][endC-1] == 3)) {
				leftE = true;
			}
		}
	}else{
		leftE = false;
	}


	//if either the end point or the start point is block the map is not valid
	if(((upS==false)&&(downS==false)&&(leftS==false)&&(rightS==false))||((upE==false)&&(downE==false)&&(leftE==false)&&(rightE==false))){
		cout<<"Map not not valid"<< endl;
		return false;
	}else{ //checks the map depending on the position of the start and end points
		int count=0, count2=0,count3=0, count4=0, count5=0, count6=0,count7=0, count8=0;
		if(currentRow<rowEnd){
			while(currentRow+1<=rowEnd){
				if(currentCol<colEnd){
					while(currentCol <colEnd){//+1no col =
						if(myMap[currentRow][currentCol+1]==2){
							count++;
							if(count==row-1){
								return false;
							}else{
								break;
							}
						}else if(myMap[currentRow][currentCol+1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol++;
						}
					}
				}else{ //currentCol>colEnd
					while(currentCol> colEnd){//-1 no col=
						if(myMap[currentRow][currentCol-1]==2){
							count++;//er2
							if(count==row-1){
								return false;
							}else{
								break;
							}
						}else if(myMap[currentRow][currentCol-1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol--;
						}
					}
				}
				currentRow++;
			}
		}else if(currentRow>rowEnd){
			while(currentRow-1>=rowEnd){
				if(currentCol<colEnd){
					while(currentCol<colEnd){//+1 no col =
						if(myMap[currentRow][currentCol+1]==2){
							count3++;
							if(count3==row-1){
								return false;
							}else{
								break;
							}
						}else if(myMap[currentRow][currentCol+1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol++;
						}
					}

				}else{ //currentCol >colEnd
					while(currentCol>colEnd){//-1 no col=
						if(myMap[currentRow][currentCol-1]==2){
							count3++;//era 4
							if(count3==row-1){
								return false;
							}else{
								break;
							}
						}else if(myMap[currentRow][currentCol-1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol--;
						}
					}

				}
				currentRow--;
			}

		}else{ //rowStart=rowEnd
			while(currentRow+1<row){
				if(colStart<colEnd){
					while(currentCol<colEnd){//+1 no col =
						if(myMap[currentRow][currentCol+1]==2){
							count5++;
							if(count5==col-1){
								return false;
							}else{

								break;
							}
						}else if(myMap[currentRow][currentCol+1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol++;
						}
					}

				}else{// colStart>colEnd
					while(currentCol>colEnd){//=-1 no col
						if(myMap[currentRow][currentCol-1]==2){
							count5++;
							if(count5==col-1){
								return false;
							}else{
								break;
							}
						}else if(myMap[currentRow][currentCol-1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol--;
						}
					}
				}
				currentRow++;
			}


			//cjecks up and down
			while(currentRow-1>=0){
				if(colStart<colEnd){
					while(currentCol<colEnd){//+1 no col =
						if(myMap[currentRow][currentCol+1]==2){
							count7++;
							if(count7==col-1){
								return false;
							}else{

								break;
							}
						}else if(myMap[currentRow][currentCol+1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol++;
						}
					}

				}else{// colStart>colEnd
					while(currentCol>colEnd){//-1 col=
						if(myMap[currentRow][currentCol-1]==2){
							count7++;//era8
							if(count7==col-1){
								return false;
							}else{
								break;
							}
						}else if(myMap[currentRow][currentCol-1]==4){
							cout <<"MAP VALID!"<< endl;
							return true;
						}else{
							currentCol--;
						}
					}
				}
				currentRow--;
			}
		}
	}


	cout<<"Map valid!" << endl;
	return true;

}

bool Map::Validation::validationNewStart(vector<vector<int>>& tempMap, int row, int col, int currentRow, int currentCol){

	int newStartRowPoint = currentRow;
	int newStartColPoint = currentCol;
	bool upS, downS, leftS, rightS; 


	//checking start point
	if(newStartRowPoint + 1 <= row-1){
		if((tempMap[newStartRowPoint+1][newStartColPoint] == 2) ||(tempMap[newStartRowPoint+1][newStartColPoint] == 5)){
			downS = false;
		}else{
			if(tempMap[currentRow+1][currentCol] == 4){ 
				cout << "MAP IS VALID!!" << endl;
				downS = true;
				return true;
			}else{
				downS = true;
			}
		}
	}else{
		downS = false;
	}

	if(newStartRowPoint-1 >= 0){
		if((tempMap[newStartRowPoint-1][newStartColPoint] == 2)||(tempMap[newStartRowPoint-1][newStartColPoint] == 5)){
			upS = false;
		}else{
			if(tempMap[newStartRowPoint- 1][newStartColPoint] == 4){
				cout << "MAP IS VALID!!" << endl;
				upS = true;
				return true;
			}else{
				upS = true;
			}
		}
	}else{
		upS = false;
	}


	if(newStartColPoint+1 <= col-1){
		if((tempMap[newStartRowPoint][newStartColPoint+1] == 2)||(tempMap[newStartRowPoint][newStartColPoint+1] == 5)){
			rightS = false;
		}else{
			if(tempMap[newStartRowPoint][newStartColPoint+1] == 4){
				cout << "MAP IS VALID!!" << endl;
				rightS = true;
				return true;
			}else{
				rightS = true;
			}
		}
	}else{
		rightS = false;
	}

	if(newStartColPoint-1 >= 0){
		if((tempMap[newStartRowPoint][newStartColPoint-1] == 2)||(tempMap[newStartRowPoint][newStartColPoint-1] == 5)){
			leftS = false;
		}else{
			if(tempMap[newStartRowPoint][newStartColPoint-1] == 4){
				cout << "MAP IS VALID!!" << endl;
				leftS = true;
				return true;
			}else{
				leftS = true;
			}
		}
	}else{
		leftS = false;
	}

	if((upS==false)&&(downS==false)&&(leftS==false)&&(rightS==false)){
		return false;
	}else{
		return true;
	}
}

bool Map::move(vector<vector<int>>& tempMap, int row, int col)
{


	/*
	e--> represents up key --> ASCII value 101
	s--> represents left key --> ASCII value 115
	f--> represents right key --> ASCII value 102
	d--> represents key down --> ASCII value 100
	*/

	vector <vector <int>> mapTracker = tempMap;
	int static currentRowPosition = rowStart;
	int static currentColPosition = colStart;	
	int  val; // value on the preivous cell entered
	int previousValRow;
	int previousValCol;
	chracPosition *tempItemLoc = new chracPosition();
	bool tempBool;

	//Map nMap(tempMap,currentRowPosition,currentColPosition);

	tempMap[currentRowPosition][currentColPosition] = 5; //start point with player

	//character name test
	//string player ="player";

	//position object holding row and collumn value
	currentPosition.setChracterPosition(currentRowPosition,currentColPosition);

	//saving charcater current position on map
	characterLocation.insert(CharacterLocation::value_type(bob, currentPosition));

	notify();
	//mapDesign(tempMap,row,col);

	char key;
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n' );

	while(!(cin >> key) || (key != 101)||(key != 115)||(key != 100)||(key != 102))
	{
		if(key=='e'){ //tries to move up
			if((currentRowPosition-1)>=0)
			{//you can move up
				if(tempMap[currentRowPosition-1][currentColPosition] == 1)
				{
					//tempItemLoc->setChracterPosition(currentRowPosition-1, currentColPosition);
					previousValRow = currentRowPosition;
					previousValCol = currentColPosition;

					val = mapTracker[previousValRow][previousValCol]; //previous position
					tempMap[previousValRow][previousValCol] = val; //set previous row with old value

					//walk in the new cell
					currentRowPosition = currentRowPosition-1;
					currentColPosition = currentColPosition;

					//set to player
					tempMap[currentRowPosition][currentColPosition] = 5; //moving player up

					currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
					characterLocation.at(bob) = currentPosition; //update player position
					notify();

					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );

				} else if(tempMap[currentRowPosition-1][currentColPosition] == 4) {

					val = mapTracker[currentRowPosition][currentColPosition]; //preivous position
					tempMap[currentRowPosition][currentColPosition] = val;

					tempMap[currentRowPosition-1][currentColPosition] = 5;

					currentPosition.setChracterPosition(currentRowPosition-1,currentColPosition);
					characterLocation.at(bob) = currentPosition; //update player position

					notify();

					cout<<"YOU HAVE REACHED THE END OF THE MAP"<<endl;
					return true;
				} else if(tempMap[currentRowPosition-1][currentColPosition] == 3) { //found something position =3
					system("pause");
					//tempItemLoc->setChracterPosition(currentRowPosition-1, currentColPosition);
					previousValRow = currentRowPosition-1; //save value on cell into
					previousValCol = currentColPosition;
					val = mapTracker[previousValRow][previousValCol];
					tempMap[currentRowPosition-1][currentColPosition] =5;
					notify();

					system("pause");
					// if true pick up item


					//cout << "We made it!" << endl;
					//map<chracPosition,d20Items::Item*>::iterator it = itemLocation.find(tempItemLoc);

					tempItemLoc->setChracterPosition(previousValRow, previousValCol);
					tempBool = bob->pickUp(itemLocation[tempItemLoc]);
					if(tempBool)
					{

						//val = mapTracker[currentRowPosition-1][currentColPosition]; //previous position
						//val =1;
						tempMap[currentRowPosition-1][currentColPosition] = 1;


					} else {
						val = mapTracker[previousValRow][previousValCol]; //previous position
						tempMap[previousValRow][previousValCol] = val;
					}


					currentRowPosition = currentRowPosition-1;
					currentColPosition = currentColPosition;
					tempMap[currentRowPosition][currentColPosition] = 5; //moving player up

					currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
					characterLocation.at(bob) = currentPosition; //update player position

					notify();

					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );

					//system("cls");

				} else {
					cout<<"here"<<endl;
				}
			} else {
				cout<<"You cannot move up! There is a wall"<<endl;
			}

		} else if(key=='s') { //tries to move left
			//tempItemLoc->setChracterPosition(currentRowPosition-1, currentColPosition);
			if(tempMap[currentRowPosition][currentColPosition-1]==1){
				previousValRow = currentRowPosition;
				previousValCol = currentColPosition;

				val = mapTracker[previousValRow][previousValCol]; //previous position
				tempMap[previousValRow][previousValCol] = val; //set previous row with old value

				//walk in the new cell
				currentRowPosition = currentRowPosition-1;
				currentColPosition = currentColPosition;

				//set to player
				tempMap[currentRowPosition][currentColPosition] = 5; //moving player up

				currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
				characterLocation.at(bob) = currentPosition; //update player position
				notify();

				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n' );

			}else if(tempMap[currentRowPosition][currentColPosition-1] == 4)
			{

				val = mapTracker[currentRowPosition][currentColPosition]; //preivous position
				tempMap[currentRowPosition][currentColPosition] = val;

				tempMap[currentRowPosition][currentColPosition-1] = 5;

				currentPosition.setChracterPosition(currentRowPosition,currentColPosition-1);
				characterLocation.at(bob) = currentPosition; //update player position

				notify();

				cout<<"YOU HAVE REACHED THE END OF THE MAP"<<endl;
				return true;

			}else if(tempMap[currentRowPosition][currentColPosition-1] == 3)
			{ //found something position =3
				system("pause");
				//tempItemLoc->setChracterPosition(currentRowPosition-1, currentColPosition);
				previousValRow = currentRowPosition; //save value on cell into
				previousValCol = currentColPosition-1;
				val = mapTracker[previousValRow][previousValCol];
				tempMap[currentRowPosition][currentColPosition-1] =5;
				notify();

				system("pause");
				// if true pick up item


				//cout << "We made it!" << endl;
				//map<chracPosition,d20Items::Item*>::iterator it = itemLocation.find(tempItemLoc);

				tempItemLoc->setChracterPosition(previousValRow, previousValCol);
				tempBool = bob->pickUp(itemLocation[tempItemLoc]);
				if(tempBool)
				{

					//val = mapTracker[currentRowPosition-1][currentColPosition]; //previous position
					//val =1;
					tempMap[currentRowPosition][currentColPosition-1] = 1;


				} else {
					val = mapTracker[previousValRow][previousValCol]; //previous position
					tempMap[previousValRow][previousValCol] = val;
				}


				currentRowPosition = currentRowPosition;
				currentColPosition = currentColPosition-1;
				tempMap[currentRowPosition][currentColPosition] = 5; //moving player up

				currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
				characterLocation.at(bob) = currentPosition; //update player position

				notify();

				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n' );

				//system("cls");

				//}else{
				cout<<"here"<<endl;

			}else{
				cout<<"You cannot move up! There is a wall"<<endl;
			}
		}else if(key=='f'){ //checks if can move right
			if((currentColPosition+1)<col){//you can move right
				if(tempMap[currentRowPosition][currentColPosition+1] == 1){
					//tempItemLoc->setChracterPosition(currentRowPosition, currentColPosition+1);
					previousValRow = currentRowPosition;
					previousValCol = currentColPosition;
					val = mapTracker[previousValRow][previousValCol]; //preivous position
					tempMap[previousValRow][previousValCol]=val;

					currentRowPosition = currentRowPosition;
					currentColPosition = currentColPosition+1;
					tempMap[currentRowPosition][currentColPosition] = 5;

					currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
					characterLocation.at(bob) = currentPosition; //update player position
					notify();

					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
				}else if(tempMap[currentRowPosition][currentColPosition+1] == 4){
					val = mapTracker[currentRowPosition][currentColPosition]; //preivous position
					tempMap[currentRowPosition][currentColPosition]=val;

					tempMap[currentRowPosition][currentColPosition+1] = 5;

					currentPosition.setChracterPosition(currentRowPosition,currentColPosition+1);
					characterLocation.at(bob) = currentPosition; //update player position

					notify();

					cout<<"YOU HAVE REACHED THE END OF THE MAP"<<endl;
					return true;
				} else if(tempMap[currentRowPosition][currentColPosition+1]==3){ //tempMap[currentRowPosition][currentColPosition+1] == 3) {

					previousValRow = currentRowPosition; //save value on cell into
					previousValCol = currentColPosition+1;
					val = mapTracker[previousValRow][previousValCol];
					tempMap[currentRowPosition][currentColPosition+1] =5;
					notify();

					system("pause");
					// if true pick up item


					//cout << "We made it!" << endl;
					//map<chracPosition,d20Items::Item*>::iterator it = itemLocation.find(tempItemLoc);

					tempItemLoc->setChracterPosition(previousValRow, previousValCol);
					tempBool = bob->pickUp(itemLocation[tempItemLoc]);
					if(tempBool)
					{

						//val = mapTracker[currentRowPosition-1][currentColPosition]; //previous position
						//val =1;
						tempMap[currentRowPosition][currentColPosition+1] = 1;


					} else {
						val = mapTracker[previousValRow][previousValCol]; //previous position
						tempMap[previousValRow][previousValCol] = val;
					}


					currentRowPosition = currentRowPosition;
					currentColPosition = currentColPosition+1;
					tempMap[currentRowPosition][currentColPosition] = 5; //moving player up

					currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
					characterLocation.at(bob) = currentPosition; //update player position

					notify();

					cin.clear();	
					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
				}else{
					cout<<"here t"<<endl;

				}

			}else{
				cout<<"You cannot move right!There is a wall"<<endl;
			}

		}else if(key=='d'){ //checks if can go down
			if((currentRowPosition+1)<row){//you can move down
				if(tempMap[currentRowPosition+1][currentColPosition] == 1){
					//tempItemLoc->setChracterPosition(currentRowPosition+1, currentColPosition);

					previousValRow = currentRowPosition;
					previousValCol = currentColPosition;

					val = mapTracker[previousValRow][previousValCol]; //preivous position
					tempMap[previousValRow][previousValCol]=val;

					currentRowPosition = currentRowPosition+1;
					currentColPosition = currentColPosition;
					tempMap[currentRowPosition][currentColPosition] = 5; //moving player down


					currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
					characterLocation.at(bob) = currentPosition; //update player position
					notify();

					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
				}else if(tempMap[currentRowPosition+1][currentColPosition] == 4){
					val = mapTracker[currentRowPosition][currentColPosition]; //preivous position
					tempMap[currentRowPosition][currentColPosition]=val;

					tempMap[currentRowPosition+1][currentColPosition] = 5;

					currentPosition.setChracterPosition(currentRowPosition+1,currentColPosition);
					characterLocation.at(bob) = currentPosition; //update player position

					notify();

					cout<<"YOU HAVE REACHED THE END OF THE MAP"<<endl;
					return true;
				}else if (tempMap[currentRowPosition+1][currentColPosition]==3){
					previousValRow = currentRowPosition+1; //save value on cell into
					previousValCol = currentColPosition;
					val = mapTracker[previousValRow][previousValCol];
					tempMap[currentRowPosition+1][currentColPosition] =5;
					notify();

					system("pause");
					// if true pick up item


					//cout << "We made it!" << endl;
					//map<chracPosition,d20Items::Item*>::iterator it = itemLocation.find(tempItemLoc);

					tempItemLoc->setChracterPosition(previousValRow, previousValCol);
					tempBool = bob->pickUp(itemLocation[tempItemLoc]);
					if(tempBool)
					{

						//val = mapTracker[currentRowPosition-1][currentColPosition]; //previous position
						//val =1;
						tempMap[currentRowPosition+1][currentColPosition] = 1;


					} else {
						val = mapTracker[previousValRow][previousValCol]; //previous position
						tempMap[previousValRow][previousValCol] = val;
					}


					currentRowPosition = currentRowPosition+1;
					currentColPosition = currentColPosition;
					tempMap[currentRowPosition][currentColPosition] = 5; //moving player up

					currentPosition.setChracterPosition(currentRowPosition,currentColPosition);
					characterLocation.at(bob) = currentPosition; //update player position

					notify();

					cin.clear();	
					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );


				}else{
					cout<<"here"<<endl;
				}
			}else{
				cout<<"You cannot move down! There is a wall"<<endl;
			}
		}else{
			cout<<"You cannot move!"<<endl;
			cin >> key;
		}
	}
}





/*
chracPosition Map::getCharacterPosition(string name){//changed
map<string,chracPosition> temLoc =getLocation();
std::map<string,chracPosition>::iterator it;
it = temLoc.find(name);
chracPosition pos = it->second;
return pos;

}
*/
/*
int Map::getCharColLocation(string name, chracPosition p){ //changed
// p = getCharacterPosition(name);
return p.getCol();
}

int Map::getCharRowLocation(string name,chracPosition p){
//chracPosition pos = getCharacterPosition(name);
return p.getRow();
}
*/
map<d20Characters::Fighter*,chracPosition> Map::getLocation(){
	return characterLocation;
}

/*** FIX create a void method to print correct item ***
d20Items::Item* Map::addItem2Map() const
{
int rNumber;
rNumber = 1 + rand() % 7;

switch(rNumber) 
{
case 0: 
//std::cout << 'A'<< " ";
return new d20Items::Armor("Dragonmail Armor");
break;
case 1: 
//std::cout << 'O'<< " ";
return new d20Items::Belt("Dragonmail Belt");
case 2: 
//std::cout << 'B'<< " ";
return new d20Items::Boots("Dragonmail Boots");
break;
case 3:
//std::cout << 'H' << " ";
return new d20Items::Helmet("Dragonmail Helmet");
break;
case 4:
//std::cout << 'R' << " ";
return new d20Items::Ring("Dragonmail Ring");
break;
case 5:
//std::cout << 'S' << " ";
return new d20Items::Shield("Dragonmail Shield");
break;
case 6:
//std::cout << 'W'<< " ";
return new d20Items::Weapon("Dragonmail Weapon");
break;
default: 
cout << '*'<< " ";
return new d20Items::Item();
break;
}
}*/
