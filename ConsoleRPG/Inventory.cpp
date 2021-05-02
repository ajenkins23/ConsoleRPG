#include "Inventory.h"



Inventory::Inventory()
{
	this->capacity = 5;
	this->nrItems = 0;
	this->itemArray = new Item*[this->capacity];
	this->initialize();
}


Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrItems; i++)
	{
		delete this->itemArray[i];
	}
	delete[] this->itemArray;
}

Inventory::Inventory(const Inventory& obj) {
	this->capacity = obj.capacity;
	this->nrItems = obj.nrItems;
	this->itemArray = new Item*[this->capacity];

	for (size_t i = 0; i < this->nrItems; i++)
	{
		this->itemArray[i] = obj.itemArray[i]->clone();
	}

	this->initialize(this->nrItems);
}

Item& Inventory::operator[](const int index) {
	if (index < 0 || index >= this->nrItems) {
		throw("BAD INDEX!");
	}
	return *this->itemArray[index];
}

void Inventory::expand() {
	this->capacity *= 2;
	Item **tempArray = new Item*[this->capacity];

	for (size_t i = 0; i < this->nrItems; i++)
	{
		tempArray[i] = this->itemArray[i];
	}

	delete[] this->itemArray;

	this->itemArray = tempArray;
	this->initialize(this->nrItems);
}

void Inventory::initialize(const int from) {
	for (size_t i = from; i < this->capacity; i++)
	{
		this->itemArray[i] = nullptr;
	}
}

void Inventory::addItem(const Item &item) {
	if (this->nrItems >= this->capacity) {
		this->expand();
	}

	this->itemArray[this->nrItems++] = item.clone();
}

void Inventory::removeItem(int index) {

}