#include "Puzzle.h"



Puzzle::Puzzle(string filename)
{
	ifstream inFile(filename);
	string answer = "";

	this->correctAnswer = 0;
	int nrOfAnswers = 0;

	if (inFile.is_open()) {
		getline(inFile, this->question);
		inFile >> nrOfAnswers;
		inFile.ignore();

		for (size_t i = 0; i < nrOfAnswers; i++){
			getline(inFile,answer);
			this->answers.push_back(answer);
		}
		inFile >> this->correctAnswer;
	}
	else
	{
		throw("Could not open " + filename);
	}

	inFile.close();
	this->correctAnswer = correctAnswer;
	inFile.ignore();
}


Puzzle::~Puzzle()
{
}


string Puzzle::getAsString() {
	string answers = "";
	for (size_t i = 0; i < this->answers.size(); i++)
	{
		answers += to_string(i) + ": " + this->answers[i] + "\n";
	}


	//return this->question + "\n\n"
	//	+ answers + "\n"
	//	+ to_string(this->correctAnswer) + "\n";

	return this->question + "\n\n"
		+ answers + "\n";
}