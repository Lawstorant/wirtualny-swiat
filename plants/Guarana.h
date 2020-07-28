#ifndef Guarana_H
#define Guarana_H

#include "../Plant.h"

class Guarana : public Plant {
public:
	Guarana(int newX, int newY, World *braveNewWorld) {
		this->strength = 0;
		this->age = 0;
		this->positionX = newX;
		this->positionY = newY;
		this->representation = GUARANA;
		this->weLiveIn = braveNewWorld;
		this->myName = "Guarana";
	}

	Organism* returnSelfType(int newX, int newY) {
		return new Guarana(newX, newY, this->weLiveIn);
	}

	Aftermath collision(Organism *invader){
		invader->increaseStrength(3);
		return LOST;
	}

};


#endif
