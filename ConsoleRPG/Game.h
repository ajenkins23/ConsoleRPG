#pragma once
#include "Event.h"
#include "dArray.h"

using namespace std;

class Game
{
public:
	Game();
	virtual ~Game();

	// Operators

	// Functions
	void mainMenu();
	void initGame();
	void createNewCharacter();
	void levelUpCharacter();
	void saveCharacters();
	void loadCharacters();
	void travel();

	// Accessors
	inline bool getPlaying() const {
		return this->playing;
	}

	// Modifiers

private:
	int choice;
	bool playing;

	// Character related
	int activeCharacter;
	vector<Character> characters;
	string filename;
};

