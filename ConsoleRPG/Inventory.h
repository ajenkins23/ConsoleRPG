#pragma once
#include "Weapon.h"
#include "Armor.h"
#include <sstream>


class Inventory
{
public:
	Inventory();
	virtual ~Inventory();
	Inventory(const Inventory& obj);
	void addItem(const Item &item);
	void removeItem(int index);
	inline int size()const { return this->nrItems; }
	Item& operator[](const int index);

	inline void debugprint() const{
		for (size_t i = 0; i < this->nrItems; i++)
		{
			cout << this->itemArray[i]->debugPrint() << endl;
		}
	}

private:
	int capacity;
	int nrItems;
	Item **itemArray;
	void expand();
	void initialize(const int from = 0);
};

