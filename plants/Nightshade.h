#ifndef NIGHTSHADE_H
#define NIGHTSHADE_H

#include "../Plant.h"

class Nightshade : public Plant {
public:
	Nightshade(int newX, int newY, World *braveNewWorld) {
		this->strength = 99;
		this->age = 0;
		this->positionX = newX;
		this->positionY = newY;
		this->representation = NIGHTSHADE;
		this->weLiveIn = braveNewWorld;
		this->myName = "Wilcze jagody";
	}

	Organism* returnSelfType(int newX, int newY) {
		return new Nightshade(newX, newY, this->weLiveIn);
	}

	Aftermath collision(Organism *invader) {
		return DRAW;
	}

};


#endif
