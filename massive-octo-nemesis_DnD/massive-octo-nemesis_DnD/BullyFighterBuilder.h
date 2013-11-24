#pragma once
#include "characterbuilderabstract.h"

namespace d20Characters {

	class BullyFighterBuilder :
		public CharacterBuilderAbstract
	{
	public:
		BullyFighterBuilder(void);
		~BullyFighterBuilder(void);
		Fighter* getCharacter(); 
	};

}