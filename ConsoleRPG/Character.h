#pragma once
#include "Inventory.h"

class Character
{
public:
	Character();
	virtual ~Character();

	// Functions
	string getAsString() const;
	void printStats() const;

	void initialize(const string name);
	void levelUp();

	// Accessors
	inline const double& getX() { return this->xPos; }
	inline const double& getY() { return this->yPos; }

	inline const string& getName() { return this->name; }

	inline const int& getLevel() { return this->level; }
	inline const int& getExp() { return this->exp; }
	inline const int& getExpNext() { return this->expNext; }
	inline const int& getHp() { return this->hp; }
	inline const int& getHpMax() { return this->hpMax; }
	inline const int& getStamina() { return this->stamina; }
	inline const int& getStaminaMax() { return this->staminaMax; }
	inline const int& getDamageMin() { return this->damageMin; }
	inline const int& getDamageMax() { return this->damageMax; }
	inline const int& getDefence() { return this->defence; }
	inline const int& getLuck() { return this->luck; }

	inline const int& getStrength() { return this->strength; }
	inline const int& getVitality() { return this->vitality; }
	inline const int& getDexterity() { return this->dexterity; }
	inline const int& getIntelligence() { return this->intelligence; }

	inline const int& getStatPoints() { return this->statPoints; }
	inline const int& getSkillPoints() { return this->skillPoints; }


	// Modifiers

private:
	double xPos;
	double yPos;

	Inventory inventory;
	Weapon weapon;
	Armor armorChest;
	Armor armorHead;
	Armor armorArms;
	Armor armorLegs;

	string name;
	int level;
	int exp;
	int expNext;

	int strength;
	int vitality;
	int dexterity;
	int intelligence;

	int hp;
	int hpMax;
	int stamina;
	int staminaMax;
	int damageMin;
	int damageMax;
	int defence;
	int luck;

	int statPoints;
	int skillPoints;

};

