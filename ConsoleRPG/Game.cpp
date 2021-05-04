#include "Game.h"

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
	this->createNewCharacter();
}

void Game::mainMenu() {
	if (this->characters[activeCharacter].getExp() >= this->characters[activeCharacter].getExpNext()) {
		cout << "LEVEL UP AVAIDABLE!!!" << endl << endl;
	}


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
	case 1:
		this->travel();
		break;
	case 3:
		this->characters[activeCharacter].levelUp();
		break;
	case 5:
		system("cls");
		this->characters[this->activeCharacter].printStats();
		break;
	case 6:
		system("cls");
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
	case 555:
		this->characters[this->activeCharacter].gainExperience(9*9*9*9*9*9*9);
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
	this->characters[this->activeCharacter].travel();

	Event event;
	event.generateEvent(this->characters[this->activeCharacter]);
}