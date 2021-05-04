#pragma once
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>


using namespace std;

class Puzzle
{
public:
	Puzzle(string filename);
	virtual ~Puzzle();
	string getAsString();

	inline const int& getCorrectAnswer() const { return this->correctAnswer; }

private:
	string question;
	vector<string> answers;
	int correctAnswer;

};

