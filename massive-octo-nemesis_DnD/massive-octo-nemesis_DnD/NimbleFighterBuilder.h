#pragma once
#include "characterbuilderabstract.h"

namespace d20Characters {

	class NimbleFighterBuilder :
		public CharacterBuilderAbstract
	{
	public:
		NimbleFighterBuilder(void);
		~NimbleFighterBuilder(void);
		Fighter* getCharacter(); 
	};

}