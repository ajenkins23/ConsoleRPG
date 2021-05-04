#include "Character.h"

Character::Character()
{
	this->distanceTravled = 0;

	this->gold = 0; 
	this->name = "NONE";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;

	this->strength = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->accuracy = 0;
	this->luck = 0;
}

Character::Character(string name,int distanceTraveled, int level, int exp, 
	int strength, int vitality, int dexterity, int intelligence,
	int hp, int stamina, int statPoints,int skillPoints)
{
	this->distanceTravled = distanceTraveled;

	this->gold = gold;
	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = expNext;

	this->strength = strength;
	this->vitality = vitality;
	this->dexterity = dexterity;
	this->intelligence = intelligence;

	this->hp = hp;
	this->hpMax = hpMax;
	this->stamina = stamina;
	this->staminaMax = staminaMax;
	this->damageMin = damageMin;
	this->damageMax = damageMax;
	this->defence = defence;
	this->accuracy = accuracy;
	this->luck = luck;

	this->updateStats();
}

Character::~Character()
{
}

// Functions
void Character::initialize(string name) {

	this->gold = 100;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext =
		static_cast<int> ((50 / 3)*((pow(this->level, 3) -
			6 * pow(this->level, 2)) +
			17 * this->level - 12)) + 25;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;

	this->hpMax = (this->vitality*2) + (this->strength/2);
	this->hp = hpMax;

	this->staminaMax = this->vitality + (this->strength / 2) + (this->dexterity / 3);
	this->stamina = staminaMax;

	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;

	this->defence = this->dexterity + (this->intelligence/2);
	this->accuracy = this->dexterity / 2;
	this->luck = this->intelligence;

	this->statPoints = 0;
	this->skillPoints = 0;
}

void Character::printStats() const {
	cout << "= Character Sheet =" << endl;
	cout << "= Name : " << this->name << endl;
	cout << "= Level : " << this->level << endl;
	cout << "= Exp : " << this->exp << " / " << this->expNext << endl;
	cout << endl;
	cout << "= Strength : " << this->strength << endl;
	cout << "= Vitality : " << this->vitality << endl;
	cout << "= Dexterity : " << this->dexterity << endl;
	cout << "= Intelligence : " << this->intelligence << endl;
	cout << endl;
	cout << "= HP : " << this->hp << " / " << this->hpMax << endl;
	cout << "= Stamina : " << this->stamina << " / " << this->staminaMax << endl;
	cout << "= Damage : " << this->damageMin << " - " << this->damageMax << endl;
	cout << "= Defence : " << this->defence << endl;
	cout << "= Accuracy : " << this->accuracy << endl;
	cout << "= Luck : " << this->luck << endl;
	cout << endl;


}

string Character::getAsString() const {
	return name + " "
		+ to_string(this->distanceTravled) + " "
		+ to_string(this->level) + " "
		+ to_string(this->exp) + " "
		+ to_string(this->strength) + " "
		+ to_string(this->vitality) + " "
		+ to_string(this->dexterity) + " "
		+ to_string(this->intelligence) + " "
		+ to_string(this->hp) + " "
		+ to_string(this->stamina) + " "
		+ to_string(this->statPoints) + " "
		+ to_string(this->skillPoints) + " ";
}


void Character::levelUp() {
	if (this->exp >= this->expNext) {
		this->exp -= this->expNext;
		this->level++;
		this->expNext =
			static_cast<int> ((50 / 3)*((pow(this->level, 3) -
				6 * pow(this->level, 2)) +
				17 * this->level - 12)) + 25;
		this->skillPoints++;
		this->statPoints++;
		cout << "You are now level " << this->level << "!!" << endl << endl;
	}
	else
	{
		cout << "Not enough exp..." << endl << endl;
	}
}

void Character::updateStats() {
	this->expNext =
		static_cast<int> ((50 / 3)*((pow(this->level, 3) -
			6 * pow(this->level, 2)) +
			17 * this->level - 12)) + 25;

	this->hpMax = (this->vitality * 2) + (this->strength / 2);

	this->staminaMax = this->vitality + (this->strength / 2) + (this->dexterity / 3);

	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;

	this->defence = this->dexterity + (this->intelligence / 2);
	this->accuracy = this->dexterity / 2;
	this->luck = this->intelligence;
}