#include "Event.h"



Event::Event()
{
	this->nrEvents = 2;
}


Event::~Event()
{
}

void Event::generateEvent(Character& character) {
	int i = rand() % this->nrEvents;

	switch (i){
	case 0:
		// Enemy encounet
		this->enemyEncounter(character);
		break;
	case 1:
		this->puzzleEncounter(character);
		// Puzzle
		break;
	case 2:
		break;
	default:
		break;
	}
}

// Different events
void Event::enemyEncounter(Character& character) {

}

void Event::puzzleEncounter(Character& character) {

}