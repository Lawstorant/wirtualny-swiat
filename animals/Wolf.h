#ifndef WOLF_H
#define WOLF_H

#include "../Animal.h"

class Wolf : public Animal {
public:
	Wolf(int newX, int newY, World *braveNewWorld) {
		this->initiative = 5;
		this->strength = 9;
		this->age = 0;
		this->positionX = newX;
		this->positionY = newY;
		this->representation = WOLF;
		this->weLiveIn = braveNewWorld;
		this->myName = "Wilk";
	}

	Organism* returnSelfType(int newX, int newY) {
		return new Wolf(newX, newY, this->weLiveIn);
	}


};


#endif
