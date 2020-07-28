#ifndef PLANT_H
#define PLANT_H

#include "Organism.h"
#include <stdlib.h>
#include "Directions.h"

class Plant : public Organism {
protected:
	int initiative = 0;

public:
	Plant() {
		this->initiative = 0;
	}


	bool action() {
		int chance = rand() % 10 + 1;
		bool ret = false;
		std::string temp = "";
		if (chance == 4 && this->age > 3) {
			temp += this->returnString() + " próbuje się rozprzestrzenić.";
			int direction = rand() % 4 + 1;
			switch (direction) {
			case UP:
				if (this->weLiveIn->getBoundY() - 1 >= 0) {
					ret = this->weLiveIn->makeNew(this->returnSelfType(this->positionX, this->positionY - 1));
				}
				break;

			case DOWN:
				if (this->positionY + 1 <= this->weLiveIn->getBoundY()) {
					ret = this->weLiveIn->makeNew(this->returnSelfType(this->positionX, this->positionY + 1));
				}
				break;

			case LEFT:
				if (this->weLiveIn->getBoundX() - 1 >= 0) {
					ret = this->weLiveIn->makeNew(this->returnSelfType(this->positionX - 1, this->positionY));
				}
				break;

			case RIGHT:
				if (this->positionX + 1 <= this->weLiveIn->getBoundX()) {
					ret = this->weLiveIn->makeNew(this->returnSelfType(this->positionX + 1, this->positionY));
				}
				break;
			}
			if(ret) temp += " Udało się! Pojawia się nowy " + this->returnString();
			else  temp += " Niestety :(";
			this->weLiveIn->addToCommentary(temp);
		}
		return ret;
	}
};


#endif
