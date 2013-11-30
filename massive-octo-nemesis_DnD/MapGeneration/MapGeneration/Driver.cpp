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
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <Wincon.h>


//This is the Driver :)

using std::numeric_limits;
using std::streamsize;
using namespace std;

int main(int argc, char** argv)
{

	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);//you don't have to call this function every time

    CONSOLE_FONT_INFOEX font;//CONSOLE_FONT_INFOEX is defined in some windows header
    GetCurrentConsoleFontEx(outcon, false, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
    font.dwFontSize.X = 48;
    font.dwFontSize.Y = 54;
    SetCurrentConsoleFontEx(outcon, false, &font);
    
    SetConsoleTextAttribute(outcon, 0x0C);
    //std::cout << "I'm red";
    std::cin.get();
	//
	cout << "Welcome to Massive Octo Nemesis DnD!" << endl << endl;
	//TODO this should be a form of factory pattern:
	// a static method that returns an instance of map after prompting the user for the inputs:
	Map* map = Map::createOrReloadAMap();


	map->gameLoopOUTER(); // this plays the game and increases the level after each level.

	map->saveCharacterToFile(); // again, although it's done after each level anyway.

	//end program:
	return 0;
}
