//include "stdafx.h"
#include "MapObservable.h"
#include "Display.h"
#include "chracPosition.h"
#include "Item.h"
#include "ItemContainer.h"
#include "Helmet.h"
#include "Shield.h"
#include "ConsoleOut.h"
#include "GUIclass.h"
#include "GUI.h"
#include "ChestBuilder.h"
//#include "IChestBuilder.h"
#include "LeveledChestBuilder.h"
#include "ChestDirector.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include <limits>
#include <ctype.h>
#include <stdlib.h>

//This is the Driver :)

using std::numeric_limits;
using std::streamsize;
using namespace std;


int main(int argc, char** argv)
{

	//TODO this should be a form of factory pattern:
	// a static method that returns an instance of map after prompting the user for the inputs:
	Map* map = Map::createOrReloadAMap();


	map->gameLoopOUTER(); // this plays the game and increases the level after each level.

	map->saveCharacterToFile(); // again, although it's done after each level anyway.

	//end program:
	return 0;
}
