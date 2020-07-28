#include "World.h"
#include "animals/Human.h"

World::World(int newBX, int newBY, Logger *newShenanigans){
	this->organisms = new List<Organism>();
	this->boundX = newBX;
	this->boundY = newBY;
	this->shenanigans = newShenanigans;
	this->gameOver = false;
};

World::World(int newBX, int newBY, List<Organism> *newOrganisms, Logger *newShenanigans){
	this->organisms = newOrganisms;
	this->boundX = newBX;
	this->boundY = newBY;
	this->shenanigans = newShenanigans;
	this->gameOver = false;
};

World::~World(){
	delete organisms;
};

void World::executeTurn(){
	for (int i = 0; i < this->organisms->getLength(); ++i) {
		Organism *current = this->organisms->getCell(i);
		int lastX = current->getX(), lastY = current->getY();

		if (current->getAge() > 0) {
			current->action();

			int isThereAnything = this->checkField(current->getX(), current->getY(), i);
			if (isThereAnything >= 0) {
				Aftermath after = organisms->getCell(isThereAnything)->collision(current);

				std::string temp = current->returnString();
				temp += " X:" + std::to_string(lastX) + ", Y:" + std::to_string(lastY);
				temp += " atakuje ";
				temp += organisms->getCell(isThereAnything)->returnString();
				temp += " X:" + std::to_string(current->getX()) + ", Y:" + std::to_string(current->getY());

				if (after == WON) {
					temp += " i przegrywa";
					kill(i);
				}
				else if (after == LOST) {
					temp += " i wygrywa";
					kill(isThereAnything);
				}
				else if (after == BRED) {
					temp += " i próbuje się rozmnożyć.";
					current->setX(lastX);
					current->setY(lastY);

					Organism partner = *getOrganism(isThereAnything);
					List<avaiableCells> breedHere = MoveHelper::helpMeBreed(*current, partner, this);

					if (breedHere.getLength() > 0) {
						int rnd = rand() % breedHere.getLength();
						this->makeNew(current->returnSelfType(breedHere.getCell(rnd)->x, breedHere.getCell(rnd)->y));
						temp += "\nNowy organizm " + current->returnString() + " X:" + std::to_string(breedHere.getCell(rnd)->x);
						temp += ", Y:" + std::to_string(breedHere.getCell(rnd)->y) + " rodzi się";
					}
					else {
						temp += " Niestey, nie ma miejsca.";
					}
				}
				else if (after == SHOO) {
					temp += " i jest odgoniony.";
					current->setX(lastX);
					current->setY(lastY);
				}
				else if (after == DRAW) {
					temp += ". Zjada " + organisms->getCell(isThereAnything)->returnString() + " i umiera.";
					this->kill(this->checkField(current->getX(), current->getY(), i));
					this->kill(this->checkField(current->getX(), current->getY(), -1));
				}
				else if (after == FLED) {
					temp += organisms->getCell(isThereAnything)->returnString() + " ucieka.";
				}

				this->shenanigans->log(temp);
			}
		}
	}


	for (int i = 0; i < this->organisms->getLength(); ++i) {
		this->organisms->getCell(i)->makeOlder();
	}
};


int World::checkField(int x, int y, int omit) const {
	int f1 = -1;
	if (x > 0 && x <= this->boundX && y > 0 && y <= this->boundY) {
		for (int i = 0; i < this->organisms->getLength(); ++i) {
			if (i == omit) continue;
			if (organisms->getCell(i)->getX() == x && organisms->getCell(i)->getY() == y) {
				f1 = i;
				break;
			}
		}
	}
	else {
		f1 = -2;
	}
	return f1;
}


bool World::makeNew(Organism *newOrganism) {
	if (checkField(newOrganism->getX(), newOrganism->getY(), -1) == -1) {
		if (organisms->getLength() > 0) {
			bool f1 = false;
			for (int i = 0; i < organisms->getLength(); ++i) {
				if (organisms->getCell(i)->getInitiative() < newOrganism->getInitiative()) {
					organisms->pushAfter(newOrganism, i - 1);
					f1 = true;
					break;
				}
			}

			if (!f1) organisms->pushBack(newOrganism);
		}
		else {
			organisms->pushBack(newOrganism);
		}
		return true;
	}
	else {
		return false;
	}
}


void World::kill(int toKill) {
	if (this->organisms->getCell(toKill)->getType() == HUMAN) this->gameOver = true;
	this->organisms->popSelected(toKill);
}


Organism* World::getOrganism(int index) const {
	return this->organisms->getCell(index);
}


int World::getOrganismCount() const {
	return this->organisms->getLength();
};


int World::getBoundX() const {
	return this->boundX;
}


int World::getBoundY() const {
	return this->boundY;
}


void World::drawWorld(){
	for (int j = 0; j < this->boundX + 2; ++j) printf("-");
	printf("\n");
	int z = -1;
	for (int i = 0; i < this->boundY; ++i) {
		printf("|");
		for (int j = 0; j < this->boundX; ++j) {
			z = this->checkField(j + 1, i + 1, -1);
			if (z != -1) printf("%c", this->getOrganism(z)->getType());
			else printf(" ");
		}
		printf("|\n");
	}
	for (int j = 0; j < this->boundX + 2; ++j) printf("-");
	printf("\n");
};

bool World::isGameOver() const {
	return this->gameOver;
};

void World::setGameOver() {
	this->gameOver = true;
}


void World::setHumanDirection(Directions newDirection) {
	this->humanDirection = newDirection;
}


Directions World::getHumanDirection() const {
	return this->humanDirection;
}


void World::addToCommentary(std::string newString) {
	this->shenanigans->log(newString);
}


void World::redirectToFile(std::ofstream &saveFile) const {
	saveFile << std::to_string(this->boundX) << " " << std::to_string(this->boundY) << std::endl;
	saveFile << this->gameOver << " " << this->humanDirection << std::endl;

	int len = this->organisms->getLength();
	saveFile << std::to_string(len) << std::endl;

	Organism *current;
	for (int i = 0; i < len; ++i) {
		current = this->organisms->getCell(i);
		saveFile << current->getType() << " ";
		saveFile << std::to_string(current->getStrength()) << " ";
		saveFile << std::to_string(current->getAge()) << " ";
		saveFile << std::to_string(current->getX()) << " ";
		saveFile << std::to_string(current->getY()) << std::endl;
	}
}
