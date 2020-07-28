#ifndef HOGWEED_H
#define HOGWEED_H

#include "../Plant.h"

class Hogweed : public Plant {
public:
	Hogweed(int newX, int newY, World *braveNewWorld) {
		this->strength = 10;
		this->age = 0;
		this->positionX = newX;
		this->positionY = newY;
		this->representation = HOGWEED;
		this->weLiveIn = braveNewWorld;
		this->myName = "Barszcz";
	}

	Organism* returnSelfType(int newX, int newY) {
		return new Hogweed(newX, newY, this->weLiveIn);
	}

	Aftermath collision(Organism *invader) {
		return DRAW;
	}

};


#endif
