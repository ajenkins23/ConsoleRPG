#pragma once
#include "Functions.h"
#include<iostream>
#include<iomanip>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Item
{
public:
	Item(string name = "NONE", int level = 0,
		int buyValue = 0, int sellValue = 0, int rarity = 0);
	virtual ~Item();

	inline string debugPrint() const { return this->name; }
	virtual Item* clone() const = 0;

	// Accessors
	inline const string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getBuyValue() const { return this->buyValue; }
	inline const int& getSellValue() const { return this->sellValue; }
	inline const int& getRarity() const { return this->rarity; }

	// Modifieers



private:
	string name;
	int level;
	int rarity;
	int sellValue;
	int buyValue;
};

