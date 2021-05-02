#include "Game.h"
#include "Character.h"

Game::Game()
{
	this->choice = 0;
	this->playing = true;
	this->activeCharacter = 0;
	this->filename = "characters.txt";
}


Game::~Game()
{

}

void Game::initGame() {
	Enemy e(rand() & 10 + 1);
	cout << e.getAsString() << endl;

	this->createNewCharacter();
}

void Game::mainMenu() {
	cout << "= MAIN MENU =" << endl << endl;
	cout << "0: Quit" << endl;
	cout << "1: Travel" << endl;
	cout << "2: Shop" << endl;
	cout << "3: Level Up" << endl;
	cout << "4: Rest" << endl;
	cout << "5: Character Sheet" << endl;
	cout << "6: Create new character" << endl;
	cout << "7: Save character" << endl;
	cout << "8: Load character" << endl;
	cout << endl;

	cout << endl << "Coice: "; 
	cin >> choice;
	cout << endl;

	switch (choice) {
	case 0:
		playing = false;
		break;
	case 5:
		this->characters[this->activeCharacter].printStats();
		break;
	case 6:
		cin.ignore();
		this->createNewCharacter();
		this->saveCharacters();
		break;
	case 7:
		this->saveCharacters();
		break;
	case 8:
		this->loadCharacters();
		break;
	default:
		break;
	}
}

void Game::createNewCharacter() {
	string name;
	cout << "Enter name for Character : ";
	getline(cin, name);

	this->characters.push_back(Character());
	this->activeCharacter = this->characters.size() - 1;
	this->characters[this->activeCharacter].initialize(name);
}


void Game::saveCharacters() {
	ofstream outFile(this->filename);

	if (outFile.is_open()) {
		for (size_t i = 0; i < this->characters.size(); i++)
		{
			outFile << this->characters[i].getAsString() << "\n";
		}
	}

	outFile.close();
}

void Game::loadCharacters() {

}

void Game::travel() {

}