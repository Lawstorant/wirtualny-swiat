#ifndef GRASS_H
#define GRASS_H

#include "../Plant.h"

class Grass : public Plant {
public:
	Grass(int newX, int newY, World *braveNewWorld) {
		this->strength = 0;
		this->age = 0;
		this->positionX = newX;
		this->positionY = newY;
		this->representation = GRASS;
		this->weLiveIn = braveNewWorld;
		this->myName = "Trawa";
	}

	Organism* returnSelfType(int newX, int newY) {
		return new Grass(newX, newY, this->weLiveIn);
	}

};


#endif
