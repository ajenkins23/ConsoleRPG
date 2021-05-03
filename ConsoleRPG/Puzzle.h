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

private:
	string question;
	vector<string> answers;
	int correctAnswer;

};

