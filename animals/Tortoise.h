#ifndef TORTOISE_H
#define TORTOISE_H

#include "../Animal.h"

class Tortoise : public Animal {
public:
	Tortoise(int newX, int newY, World *braveNewWorld) {
		this->initiative = 1;
		this->strength = 2;
		this->age = 0;
		this->positionX = newX;
		this->positionY = newY;
		this->representation = TORTOISE;
		this->weLiveIn = braveNewWorld;
		this->myName = "Zółw";
	}


	bool action() {
		int areWeGoingSomewhere = rand() % 100 + 1;

		if (areWeGoingSomewhere > 20 && areWeGoingSomewhere <= 45) {
			Animal::action();
		}
		return false;
	}


	Aftermath collision(Organism *invader) {
		Characters invaderType = invader->getType();
		int invaderStrength = invader->getStrength();

		if (invaderType != this->representation && invaderStrength < 5) return SHOO;
		else return Animal::collision(invader);
	}

	Organism* returnSelfType(int newX, int newY) {
		return new Tortoise(newX, newY, this->weLiveIn);
	}


};


#endif
