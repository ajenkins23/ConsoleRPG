#include "Event.h"



Event::Event()
{
	this->nrEvents = 2;
}


Event::~Event()
{
}

void Event::generateEvent(Character& character, dArray<Enemy> enemies) {
	int i = rand() % this->nrEvents;

	switch (i){
	case 0:
		// Enemy encounet
		this->enemyEncounter(character, enemies);
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
void Event::enemyEncounter(Character& character, dArray<Enemy> enemies) {
	system("cls");
	bool escape = false;
	bool playerDefeated = false;
	bool enemiesDefeated = false;
	bool playerTurn = true;

	int choice = 0;
	int nrOfEnemies = rand() % 5 + 1;

	for (size_t i = 0; i < nrOfEnemies; i++)
	{
		enemies.push(Enemy(character.getLevel()));
	}
	cout << "Nr of enemies = " << enemies.size() << endl; 

	while (!escape && !playerDefeated && !enemiesDefeated)
	{
		if (playerTurn) {
			// MENU
			cout << "= BATTLE MENU =\n\n";
			cout << "0: Escape\n";
			cout << "1: Attack\n";
			cout << "2: Defend\n";
			cout << "3: Use Item\n";

			cout << "Choice: ";

			cin >> choice;
			switch (choice)
			{
			case 0:
				escape = true;
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				break;
			}

			// MOVE

			playerTurn = false;
		}
		else
		{
			for (size_t i = 0; i < enemies.size(); i++)
			{

			}

			playerTurn = true;
		}

		// CONDITIONS

		if (!character.isAlive()) {
			playerDefeated = true;
		}
		else if (enemies.size() <= 0) {
			enemiesDefeated = true;
		}
	}
}

void Event::puzzleEncounter(Character& character) {
	bool completed = false;
	int puzzleNumber = 2;
	string puzzleName = "puzzles/" + to_string(puzzleNumber) + ".txt";
	Puzzle puzzle(puzzleName);

	int chances = 3;
	int userAnswer = 0;
	int expGained = rand() % (character.getLevel() * chances * character.getLuck()) + 1;

	while (!completed && chances > 0)
	{
		system("cls");
		cout << "Chances left: " << chances << endl << endl;
		cout << puzzle.getAsString();
		cout << "\nYour ANSWER: ";
		cin >> userAnswer;

		while (cin.fail()) {
			cout << "Fualty input!" << endl;
			cin.clear();
			cin.ignore(100, '\n');

			cout << endl << "Choice: ";
			cin >> userAnswer;
		}

		cin.ignore(100, '\n');
		cout << endl;

		cout << "\n";
		if (puzzle.getCorrectAnswer() == userAnswer) {
			completed = true;
			character.gainExperience(expGained);
			cout << "You have gained " << expGained << " experience!!" << endl;
			// Give user exp and etc
		}
		chances--;

	}

	if (completed)
	{
		cout << "Congratulations! You got the correct answer!" << endl << endl;
	}
	else
	{
		cout << "Sorry you used up all your attempts..." << endl << endl;
	}
}