#pragma once
#include "Weapon.h"
#include "Armor.h"

class Inventory
{
public:
	Inventory();
	virtual ~Inventory();
	void addItem(const Item &item);
	void removeItem(int index);

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
	void initialize(const int from);
};

