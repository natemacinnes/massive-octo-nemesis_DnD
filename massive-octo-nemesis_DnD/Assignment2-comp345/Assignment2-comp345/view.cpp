
#include "view.h"
#include "MapObservable.h" 

display::display(Map &myMap, vector<vector<int>> mapV , int row, int col)
{
	mapV = myMap.getMapVector();
	row = myMap.getMapRow();
	col = myMap.getMapCol();

}


display::~display(void)
{
}

void display::update (Map &myMap) 
{
	
	int row = myMap.getMapRow();
	int col = myMap.getMapCol();
	vector<vector<int>>  mapV = myMap.getMapVector();
	

	/*vector <vector <int>> mapTracker = mapV;
	int static currentRowPosition = myMap.getRowStart();
	int static currentColPosition = myMap.getColStart();	*/
	//int  val;
	//mapV[currentRowPosition][currentColPosition] = 5; //start point with player
	//myMap.mapDesign(mapV,row,col);
	////notifyObs();
	//
	//int previousValRow;
	//int previousValCol;
	//
	//char key;
	///*while(!(cin >> key) || (key != 101)||(key != 115)||(key != 100)||(key != 102))
 //       {*/
	//		if(key=='e'){ //tries to move up
	//			if((currentRowPosition-1)>=0){//you can move up
	//				if(mapV[currentRowPosition-1][currentColPosition] == 2){
	//					cout<<"Sorry you cannot move there. There is a wall!"<<endl;
	//				/*	cin.clear();
	//					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );*/
	//				}else if(mapV[currentRowPosition-1][currentColPosition] == 4){
	//					val = mapTracker[currentRowPosition][currentColPosition]; //preivous position
	//					mapV[currentRowPosition-1][currentColPosition] = 5;
	//					mapV[currentRowPosition][currentColPosition]=val;
	//					//notifyObs();
	//					myMap.mapDesign(mapV,row,col);
	//					cout<<"YOU HAVE REACHED THE END OF THE MAP"<<endl;
	//					//return true;
	//				}else{
	//					previousValRow = currentRowPosition;
	//					previousValCol = currentColPosition;
	//					val = mapTracker[previousValRow][previousValCol]; //previous position
	//					mapV[previousValRow][previousValCol] = val;
	//					currentRowPosition = currentRowPosition-1;
	//					currentColPosition = currentColPosition;
	//					mapV[currentRowPosition][currentColPosition] = 5; //moving player up
	//					/*cin.clear();
	//					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );*/
	//					//notifyObs();
	//					myMap.mapDesign(mapV,row,col);
	//					
	//					
	//				}
	//			}else{
	//				cout<<"You cannot move up!"<<endl;
	//			}
	//		}else if(key=='s'){ //tries to move left
	//			if((currentColPosition-1)>=0){//you can move left
	//				if(mapV[currentRowPosition][currentColPosition-1] == 2){
	//					cout<<"Sorry you cannot move there. There is a wall!"<<endl;
	//					/*cin.clear();
	//					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );*/
	//				}else if(mapV[currentRowPosition][currentColPosition-1] == 4){
	//					val = mapTracker[currentRowPosition][currentColPosition]; //preivous position
	//					mapV[currentRowPosition][currentColPosition-1] = 5;
	//					mapV[currentRowPosition][currentColPosition]=val;
	//					//notifyObs();
	//					myMap.mapDesign(mapV,row,col);
	//					
	//					cout<<"YOU HAVE REACHED THE END OF THE MAP"<<endl;
	//					//return true;
	//				}else{
	//					previousValRow = currentRowPosition;
	//					previousValCol = currentColPosition;
	//					val = mapTracker[previousValRow][previousValCol]; //preivous position
	//					mapV[currentRowPosition][currentColPosition] = val;
	//					currentRowPosition = currentRowPosition;
	//					currentColPosition = currentColPosition-1;
	//					mapV[currentRowPosition][currentColPosition] = 5; //moving player left
	//					/*cin.clear();
	//					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );*/
	//					//notifyObs();
	//					myMap.mapDesign(mapV,row,col);
	//					
	//				}
	//			}else{
	//				cout<<"You cannot move left!"<<endl;
	//			}
	//		}else if(key=='f'){ //checks if can move right
	//			if((currentColPosition+1)<col){//you can move right
	//				if(mapV[currentRowPosition][currentColPosition+1] == 2){
	//					cout<<"Sorry you cannot move there. There is a wall!"<<endl;
	//					/*cin.clear();
	//					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );*/
	//				}else if(mapV[currentRowPosition][currentColPosition+1] == 4){
	//					val = mapTracker[currentRowPosition][currentColPosition]; //preivous position
	//					mapV[currentRowPosition][currentColPosition+1] = 5;
	//					mapV[currentRowPosition][currentColPosition]=val;
	//					//notifyObs();
	//					myMap.mapDesign(mapV,row,col);
	//					
	//					cout<<"YOU HAVE REACHED THE END OF THE MAP"<<endl;
	//					//return true;
	//				}else{
	//					previousValRow = currentRowPosition;
	//					previousValCol = currentColPosition;
	//					val = mapTracker[previousValRow][previousValCol]; //preivous position
	//					mapV[currentRowPosition][currentColPosition] = val;
	//					currentRowPosition = currentRowPosition;
	//					currentColPosition = currentColPosition+1;
	//					mapV[currentRowPosition][currentColPosition] = 5; //moving player right
	//					/*cin.clear();
	//					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );*/
	//					//notifyObs();
	//					myMap.mapDesign(mapV,row,col);
	//					
	//				}
	//			}else{
	//				cout<<"You cannot move right!"<<endl;
	//			}
	//		
	//		}else{ //checks if can go down
	//			if((currentRowPosition+1)<row){//you can move down
	//				if(mapV[currentRowPosition+1][currentColPosition] == 2){
	//					cout<<"Sorry you cannot move there. There is a wall!"<<endl;
	//					cin.clear();
	//					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );
	//				}else if(mapV[currentRowPosition+1][currentColPosition] == 4){
	//					val = mapTracker[currentRowPosition][currentColPosition]; //preivous position
	//					mapV[currentRowPosition+1][currentColPosition] = 5;
	//					mapV[currentRowPosition][currentColPosition]=val;
	//					//notifyObs();
	//					myMap.mapDesign(mapV,row,col);
	//					
	//					cout<<"YOU HAVE REACHED THE END OF THE MAP"<<endl;
	//					//return true;
	//				}else{
	//					previousValRow = currentRowPosition;
	//					previousValCol = currentColPosition;
	//					val = mapTracker[previousValRow][previousValCol]; //preivous position
	//					mapV[currentRowPosition][currentColPosition] = val;
	//					currentRowPosition = currentRowPosition+1;
	//					currentColPosition = currentColPosition;
	//					mapV[currentRowPosition][currentColPosition] = 5; //moving player down
	//					/*cin.clear();
	//					cin.ignore((numeric_limits<streamsize>::max)(), '\n' );*/
	//					//notifyObs();
	//					myMap.mapDesign(mapV,row,col);
	//					
	//				}
	//			}else{
	//				cout<<"You cannot move down!"<<endl;
	//			}
	//		}
 //  // }

//while(myMap.move(mapV, row, col) == true){
	myMap.mapDesign(mapV, row, col);
	//
	
	//myMap.move(mapV, row, col);
//}

}