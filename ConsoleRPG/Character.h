#pragma once
#include "Inventory.h"
#include "Enemy.h";



class Character
{
public:
	Character();
	Character(string name, int distanceTraveled, int level, int exp,
		int strength, int vitality, int dexterity, int intelligence,
		int hp, int stamina, int statPoints, int skillPoints);
	virtual ~Character();

	// Functions
	string getAsString() const;
	void printStats() const;

	void initialize(const string name);
	void levelUp();
	void updateStats();

	// Accessors
	inline const int& getDistanceTraveled() const { return this->distanceTravled; }

	inline const string& getName() const { return this->name; }

	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getHp() const { return this->hp; }
	inline const int& getHpMax() const { return this->hpMax; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getStaminaMax() const { return this->staminaMax; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDefence() const { return this->defence; }
	inline const int& getAccuracy() const { return this->accuracy; }
	inline const int& getLuck() const { return this->luck; }

	inline const int& getStrength() const { return this->strength; }
	inline const int& getVitality() const { return this->vitality; }
	inline const int& getDexterity() const { return this->dexterity; }
	inline const int& getIntelligence() const { return this->intelligence; }

	inline const int& getStatPoints() const { return this->statPoints; }
	inline const int& getSkillPoints() const { return this->skillPoints; }

	inline const int& getGold() const { return this->gold; }


	// Modifiers
	inline void setDistancedTraveled(const int& distanceTraveled) { this->distanceTravled = distanceTraveled; }
	inline void travel() { this->distanceTravled++; }
	inline void gainExperience(const int& expierience) { this->exp += expierience; }



private:
	int distanceTravled;
	
	string name;

	Inventory inventory;
	Weapon weapon;
	Armor armorChest;
	Armor armorHead;
	Armor armorArms;
	Armor armorLegs;

	int gold;

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
	int accuracy;
	int luck;

	int statPoints;
	int skillPoints;

};

