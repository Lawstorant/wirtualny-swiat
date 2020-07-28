#ifndef FOX_H
#define FOX_H

#include "../Animal.h"
#include "../MoveHelper.h"

class Fox : public Animal {
public:
	Fox(int newX, int newY, World *braveNewWorld) {
		this->initiative = 7;
		this->strength = 3;
		this->age = 0;
		this->positionX = newX;
		this->positionY = newY;
		this->representation = FOX;
		this->weLiveIn = braveNewWorld;
		this->myName = "Lis";
	}


	bool action() {
		List<avaiableCells> moveHere = MoveHelper::helpMeMove(this->positionX, this->positionY, this->weLiveIn);

		for (int i = 0; i < moveHere.getLength(); ++i) {
			int check1 = weLiveIn->checkField(moveHere.getCell(i)->x, moveHere.getCell(i)->y,-1);
			if(check1 != -1) {
				if(weLiveIn->getOrganism(check1)->getStrength() > this->strength) {
					moveHere.popSelected(i);
					--i;
				}
			}
		}

		if(moveHere.getLength() > 0) {
			int rnd = rand() % moveHere.getLength();
			this->positionX = moveHere.getCell(rnd)->x;
			this->positionY = moveHere.getCell(rnd)->y;
		}
		return false;
	}

	Organism* returnSelfType(int newX, int newY) {
		return new Fox(newX, newY, this->weLiveIn);
	}

};


#endif
