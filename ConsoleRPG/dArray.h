#pragma once

template<typename T>
class dArray {
public:
	dArray(unsigned size = 5);
	dArray(const dArray& obj);
	~dArray();

	T& operator[] (const unsigned index);
	void operator = (const dArray& obj);

	unsigned maxCap();
	unsigned size();
	void push(const T element);
	void remove(const unsigned index, bool ordered = false);

private:
	unsigned cap;
	unsigned initialCap;
	unsigned nrOfElements();

	T** array;

	void expand();
	void initialize(unsigned from);
};

template<typename T>
dArray<T>::dArray(unsigned size) {
	this->initialCap = size;
	this->cap = size;
	this->nrOfElements = 0;

	this->array = new T*[this->cap];

	this->initialize();
}

template<typename T>
dArray<T>::dArray(const dArray& obj) {
	this->initialCap = obj.initialCap;
	this->cap = obj.size;
	this->nrOfElements = obj.nrOfElements;

	this->array = new T*[this->cap];

	for (size_t i = 0; i < nrOfElements; i++)
	{
		this->array[i] = new T(*obj.array[i]);
	}

	this->initialize();
}

template<typename T>
dArray<T>::~dArray() {
	for (size_t i = 0; i < this->nrOfElements; i++)
	{
		delete this->array[i];
	}
	delete[] array;
}

template<typename T>
T& dArray<T>::operator[] (const unsigned index) {
	if (index < 0 || index >= this->nrOfElements) {
		throw"OUT OF BOUNDS";
	}
	return *this->array[index];
}

template<typename T>
void dArray<T>::operator = (const dArray& obj) {
	for (size_t i = 0; i < this->nrOfElements; i++)
	{
		delete this->array[i];
	}
	delete[] array;

	this->initialCap = obj.initialCap;
	this->cap = obj.size;
	this->nrOfElements = obj.nrOfElements;

	this->array = new T*[this->cap];

	for (size_t i = 0; i < nrOfElements; i++)
	{
		this->array[i] = new T(*obj.array[i]);
	}

	this->initialize();
}

template<typename T>
void dArray<T>::expand() {
	this->cap *= 2;

	T** tempArray = new T*[this->cap];

	for (size_t i = 0; i < this->nrOfElements; i++)
	{
		tempArray[i] = this->array[i];
	}

	delet[] array;
	this->array = tempArray;

	this->initialize();
}

template<typename T>
void dArray<T>::initialize(unsigned from) {
	for (size_t from = 0; from < this->cap; from++)
	{
		this->array[i] = nullptr;
	}
}

template<typename T>
unsigned dArray<T>::maxCap() {
	return this->cap;
}

template<typename T>
unsigned dArray<T>::size() {
	return this->nrOfElements;
}

template<typename T>
void dArray<T>::push(const T element) {
	if (this->nrOfElements >= this->cap) {
		this->expand();
	}
	this->array[this->nrOfElements++] = new T(element);
}

template<typename T>
void dArray<T>::remove(const unsigned index, bool ordered) {
	if (index < 0 || index >= this->nrOfElements) {
		throw"OUT OF BOUNDS REMOVE";
	}

	if (ordered) {
		delete this->array[index];

		for (size_t i = 0; i < this->nrOfElements; i++)
		{
			this->array[i] = this->array[i + 1];
		}

		this->array[--this->nrOfElements] = nullptr;
	}
	else
	{
		delete this->array[index];

		this->array[index] = this->array[this->nrOfElements - 1];
		this->array[--this->nrOfElements] = nullptr;
	}
}
