#ifndef DANDELION_H
#define DANDELION_H

#include "../Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(int newX, int newY, World *braveNewWorld) {
		this->strength = 0;
		this->age = 0;
		this->positionX = newX;
		this->positionY = newY;
		this->representation = DANDELION;
		this->weLiveIn = braveNewWorld;
		this->myName = "Mlecz";
	}


	bool action() {
		if (!Plant::action())
			if (!Plant::action())
				Plant::action();
		return false;
	}


	Organism* returnSelfType(int newX, int newY) {
		return new Dandelion(newX, newY, this->weLiveIn);
	}


};


#endif
