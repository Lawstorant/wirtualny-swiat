#include "Organism.h"

Aftermath Organism::collision(Organism *invader) {
	if (invader->getStrength() >= this->strength) return LOST;
	else return WON;
}


void Organism::draw() const {
	printf("%c", this->representation);
};

int Organism::getX() const {
	return this->positionX;
}


int Organism::getY() const {
	return this->positionY;
}

int Organism::getAge() const {
	return this->age;
}

void Organism::setAge(int newAge) {
	this->age = newAge;
}


int Organism::getInitiative() const {
	return this->initiative;
}


void Organism::makeOlder() {
	++this->age;
}


void Organism::setX(int newX) {
	this->positionX = newX;
}


void Organism::setY(int newY) {
	this->positionY = newY;
}

Characters Organism::getType() const {
	return this->representation;
}


int Organism::getStrength() const {
	return this->strength;
}


void Organism::increaseStrength(int muchyMuchy) {
	this->strength += muchyMuchy;
}

std::string Organism::returnString() const {
	return this->myName;
}
