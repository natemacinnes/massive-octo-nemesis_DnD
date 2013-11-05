README.txt

 Created on: Oct 22, 2013
     Author: Nicolas Chausseau 643 1526



As demonstrated by the comp345_driver_for_character, 
the abstract class character and its implementation fighter
allow to create a fighter character according to selected
d20 rules. We verify in the driver that each function call
(that will be necessary for the manipulation of characters
in the future, during a game) operates as desired.



==========================================================
DESCRIPTION OF THE RULES FOR SELECTED ATTRIBUTES

Upon character creation, the different character attributes
(strength, constitution, wisdom, intelligence, etc.) are
generated using random numbers that replace the 
"throwing of the dice" that is necessary in the original 
game.

the exact rules can be read in the code, but in particular:

	// (...) Possible ability scores range from 7 to 18:
	// http://www.d20pfsrd.com/basics-ability-scores/character-creation
	
and

	// http://paizo.com/prd/combat.html#_armor-class
	//10 + armor bonus + shield bonus + Dexterity modifier + other modifiers
	armorClass = 10 + armor + shield + dexterityModifier;	

as well as

	// rules for determining hitPoints:
	// Your Hit Dice have to do with Hit Points and you get one 
	// d8 per level. First level you start with the maximum 
	// (8+your Con modifier). You roll a d8 every level up and add 
	// your Con modifier.
	//http://www.escapistmagazine.com/forums/read/9.306810-D-D-3-5e-Character-Creation-help
	
	//which translate into the following logic:
	
	if (level == 1) {
		hitPoints = diceResult + constitution;
	} else { // if the level is higher than 1:
		srand(time(NULL)); // init random seed
		hitPoints = diceResult + constitution + rand() % 11 + 7;
	}
	
Finally some boundary checks were added to parameters passed, 
for example the kind of dice allowed in the calculation of an
attribute allows only for a certain range of possibilities.
This is done in the first line of relevant Fighter methods. 
	
N.B. the rules had to be simplified to be adapted to our project
which contains only a selection of attributes and parameters
compared to the original game.


==========================================================
DESIGN DECISIONS

Here we choose to implement first an abstract character class
since in theory different characters can interact in the game.

Then we implemented the abstract character class with a Fighter.
	it must implement most of the setters, since their logic is
	specific to each character, according to the rules.
	
	getters on the other hand can be implemented by the base
	class character since they won't vary and are shared.
	
Protected methods in character, why?
	some methods are not to be called by an external user class
	during the game. For example all abilities are set upon character
	creation and shouldn't change during the game according to 
	the rules. Conversely items (shield, rings, boots, belt, 
	helmet, etc.) can be modified during the game,
	as well as hitPoints; their setters must be public.
	
	Attributes that are entirely dependent on other attributes
	-- such as ArmorClass, attach and damage bonuses as well as 
	all modifiers -- are modifier through protected methods
	or in the body of protected methods that set the attribute
	they dependent on (in the case of modifiers).
	
Protected data members in character, why?
	this is to allow subclasses (e.g. fighter etc) to access 
	those variables directly without resorting to (s/g)etters function 
	calls to the base class's setters and getters (character) 
	-- thus increasing performance, by removing an extra function call. 
	
Integer types for all items, and the armorClass, why?
	Because I do not yet have my partner's implementation of
	the items classes, I had to use a simplified version of those
	attributes, represented as integers. Those will be replaced
	with their corresponding types in the next assignment.
	

