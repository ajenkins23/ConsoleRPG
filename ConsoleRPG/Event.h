#pragma once
#include "Puzzle.h"
#include "Character.h"

class Event
{
public:
	Event();
	virtual ~Event();
	void generateEvent(Character& character);

private:
	int nrEvents;
	void enemyEncounter(Character& character);
	void puzzleEncounter(Character& character);
};

