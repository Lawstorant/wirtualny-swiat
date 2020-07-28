#ifndef ANTELOPE_H
#define ANTELOPE_H

#include "../Animal.h"
#include <iostream>

class Antelope : public Animal {
public:
	Antelope(int newX, int newY, World *braveNewWorld) {
		this->initiative = 4;
		this->strength = 4;
		this->age = 0;
		this->positionX = newX;
		this->positionY = newY;
		this->representation = ANTELOPE;
		this->weLiveIn = braveNewWorld;
		this->myName = "Antylopa";
	}


	bool action() {
		Animal::action();
		Animal::action();
		return false;
	}


	Aftermath collision(Organism *invader) {
		int flee = 0;
		if (flee == 1) {
			List<avaiableCells> moveHere = MoveHelper::helpMeMove(this->positionX, this->positionY, this->weLiveIn);

			for (int i = 0; i < moveHere.getLength(); ++i) {
				int check1 = weLiveIn->checkField(moveHere.getCell(i)->x, moveHere.getCell(i)->y,-1);
				if (check1 != -1) {
					moveHere.popSelected(i);
					--i;
				}
			}

			int rnd = rand() % moveHere.getLength();
			this->positionX = moveHere.getCell(rnd)->x;
			this->positionY = moveHere.getCell(rnd)->y;

			return FLED;
		}
		else return Animal::collision(invader);
	}

	Organism* returnSelfType(int newX, int newY) {
		return new Antelope(newX, newY, this->weLiveIn);
	}


};


#endif
