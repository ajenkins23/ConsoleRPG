#pragma once
#include <stdlib.h>
#include <string>

using namespace std;

class Enemy
{
public:
	Enemy(int level = 0);
	virtual ~Enemy();

	inline bool isAlive() { return this->hp > 0; }
	string getAsString() const;
	inline void takeDamage(int damage) { this->hp -= damage; }
	inline int getDamage() const { rand() % this->damageMax - this->damageMin; }
	inline int getExp() const { return this->level * 100; }

private:
	int hp;
	int hpMax;
	int level;
	int damageMin;
	int damageMax;
	int defence;
	int accuracy;

	float dropChance;
};

