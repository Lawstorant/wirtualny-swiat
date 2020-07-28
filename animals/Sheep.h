#ifndef SHEEP_H
#define SHEEP_H

#include "../Animal.h"

class Sheep : public Animal {
public:
	Sheep(int newX, int newY, World *braveNewWorld) {
		this->initiative = 4;
		this->strength = 4;
		this->age = 0;
		this->positionX = newX;
		this->positionY = newY;
		this->representation = SHEEP;
		this->weLiveIn = braveNewWorld;
		this->myName = "Owca";
	}

	Organism* returnSelfType(int newX, int newY) {
		return new Sheep(newX, newY, this->weLiveIn);
	}

};


#endif
