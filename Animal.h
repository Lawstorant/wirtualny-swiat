#ifndef ANIMAL_H
#define ANIMAL_H

#include "Organism.h"
#include <stdlib.h>
#include "Directions.h"
#include "MoveHelper.h"

class Animal : public Organism {
public:
	bool action() {
		List<avaiableCells> moveHere = MoveHelper::helpMeMove(this->positionX, this->positionY, this->weLiveIn);

		if(moveHere.getLength() > 0) {
			int rnd = rand() % moveHere.getLength();

			this->positionX = moveHere.getCell(rnd)->x;
			this->positionY = moveHere.getCell(rnd)->y;
		}
		return false;
	}


	Aftermath collision(Organism *invader) {
		if (invader->getType() == this->representation) {

			int chance = rand() % 10 + 1;

			if ((chance == 3 || chance == 6) && this->age > 3 && invader->getAge() > 3)
				return BRED;
			else
				return SHOO;
		}
		else {
			return Organism::collision(invader);
		}
	}


};


#endif
