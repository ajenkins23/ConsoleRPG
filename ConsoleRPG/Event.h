#pragma once
#include "Puzzle.h"
#include "Character.h"

class Event
{
public:
	Event();
	virtual ~Event();
	void generateEvent(Character& character, dArray<Enemy> enemies);

private:
	int nrEvents;
	void enemyEncounter(Character& character, dArray<Enemy> enemies);
	void puzzleEncounter(Character& character);
};

