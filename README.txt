README.txt

 Created on: Nov 4th, 2013
     Author: Nicolas Chausseau 643 1526


=======================================================

NOTE FOR EXECUTABLE: the executable can be found 
in the Debug/ folder, with name comp345_character.

the explanation for the code is straighforward and 
can be simply explained by the driver's series of 
events (as requested in assignment handout):

	//create fighter that we will observe / watch for changes:
	d20Characters::Fighter myFighter(2);

	//create GUI class that knows what what to do on fighter changes 
	//(e.g. refresh screen, but here just a re-print):
	d20Characters::GUIclass* gui = new d20Characters::GUIclass();

	//plug the two together -- the observer (GUI object) and observable (Fighter object):
	gui->registerToObservable(&myFighter);

	//now any modifications on myFighter should trigger a re-print of myFighter:
	....(it is indeed the case after running all the test calls)
	
the organization of classes follows the classic Observer pattern:

	Fighter extends character, which itself extends Observable
		--> any character (not just fighter) can be watched
		--> Observable ensures the presence of two methods:
			registerObserver
			notifyAllObservers
		observers are held in a vector.
	
	the GUIclass extends Observer
		--> Observer ensures two methods
			onEvent (called by Observable object upon changes)
			RegisterToObservable
				in which we keep pointers to all characters watched
				in which we register for changes for a given character
			
A call to NotifyAllObservers were of course added in all Fighter methods that alter its state.
