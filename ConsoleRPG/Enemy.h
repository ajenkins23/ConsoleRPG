#pragma once
#include <stdlib.h>
#include <string>

using namespace std;

class Enemy
{
public:
	Enemy(int level = 0, string name = "");
	virtual ~Enemy();

	inline bool isAlive() { return this->hp > 0; }
	string getAsString() const;
	void takeDamage(int damage);
	inline int getDamage() const { rand() % this->damageMax - this->damageMin; }
	inline int getExp() const { return this->level * 100; }
	inline string getName() const { return this->name; }
	inline int getHp() const { return this->hp; }
	inline int getHpMax() const { return this->hpMax; }

private:
	string name;
	int hp;
	int hpMax;
	int level;
	int damageMin;
	int damageMax;
	int defence;
	int accuracy;

	float dropChance;
};

