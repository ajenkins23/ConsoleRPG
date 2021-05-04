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
	cout << "ENTER to continue..." << endl;
	cin.get();
	system("cls");

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

	while (cin.fail()) {
		cout << "Fualty input!" << endl;
		cin.clear();
		cin.ignore(100, '\n');

		cout << endl << "Choice: ";
		cin >> choice;
	}

	cin.ignore(100, '\n');
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
	ifstream inFile(this->filename);
	this->characters.clear();

	string line = "";
	string name = "";
	int distanceTraveled, level, exp, strength, vitality, dexterity, intelligence,
		hp, stamina, statPoints, skillPoints = 0;
	stringstream str;

	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			str.str(line);

			str >> name;
			str >> distanceTraveled;
			str >> level;
			str >> exp;
			str >> strength;
			str >> vitality;
			str >> dexterity;
			str >> intelligence;
			str >> hp;
			str >> stamina;
			str >> statPoints;
			str >> skillPoints;

			Character temp(name, distanceTraveled, level, exp, strength, vitality, dexterity, intelligence,
				hp, stamina, statPoints, skillPoints);

			cout << "Character " << name << " loaded!" << endl;
			this->characters.push_back(temp);
			str.clear();
		}
	}
	inFile.close();

	if (this->characters.size() <= 0) {
		throw("ERROR!! No characters loaded or empty file.");
	}
	else
	{
		activeCharacter = 0;
		cout << "Character " << this->characters[this->activeCharacter].getName() << " is currently active!" << endl;
	}
}

void Game::travel() {
	this->characters[this->activeCharacter].travel();

	Event event;
	event.generateEvent(this->characters[this->activeCharacter]);
}