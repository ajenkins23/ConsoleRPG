#include "Character.h"

Character::Character()
{
	this->xPos = 0.0;
	this->yPos = 0.0;

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
	this->luck = 0;
}


Character::~Character()
{
}

// Functions
void Character::initialize(string name) {
	this->xPos = 0.0;
	this->yPos = 0.0;

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
	cout << "= Defence : " << this->intelligence << endl;
	cout << endl;


}

string Character::getAsString() const {
	return to_string(this->xPos) + " "
		+ to_string(this->yPos) + " "
		+ name + " "
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
	 while (this->exp >= this->expNext) {
		this->exp -= this->expNext;
		this->level++;
		this->expNext =
			static_cast<int> ((50 / 3)*((pow(this->level, 3) -
				6 * pow(this->level, 2)) +
				17 * this->level - 12)) + 25;
		this->skillPoints++;
		this->statPoints++;
	}
}