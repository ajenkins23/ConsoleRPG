#pragma once
#include"Character.h"


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
	void saveCharacters();
	void loadCharacters();

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

