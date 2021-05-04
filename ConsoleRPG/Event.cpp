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
	// while()
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