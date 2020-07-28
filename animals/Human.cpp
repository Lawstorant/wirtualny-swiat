#include "Human.h"

Human::Human(int newX, int newY, World *braveNewWorld) {
	this->initiative = 4;
	this->strength = 5;
	this->age = 0;
	this->positionX = newX;
	this->positionY = newY;
	this->representation = HUMAN;
	this->weLiveIn = braveNewWorld;
	this->cooldown = 0;
	this->powerActivated = false;
	this->myName = "Człowiek";
}


Organism* Human::returnSelfType(int newX, int newY) {
	return new Human(newX, newY, this->weLiveIn);
}


bool Human::action() {
	List<avaiableCells> moveHere = MoveHelper::helpMeMove(this->positionX, this->positionY, this->weLiveIn);

	Directions direction = this->weLiveIn->getHumanDirection();

	if (moveHere.getLength() > 0) {
		switch (direction) {
		case UP:
			if (this->positionY - 1 > 0) {
				--this->positionY;
			}
			break;
		case DOWN:
			if (this->positionY + 1 <= this->weLiveIn->getBoundY()) {
				++this->positionY;
			}
			break;
		case LEFT:
			if (this->positionX - 1 > 0) {
				--this->positionX;
			}
			break;
		case RIGHT:
			if (this->positionX + 1 <= this->weLiveIn->getBoundX()) {
				++this->positionX;
			}
			break;
		}
	}
	else {
		// TODO: logowanie o tym że nie można się ruszyć;
	}
	return false;
}


Aftermath Human::collision(Organism *invader) {
	return Organism::collision(invader);
}


void Human::activatePower() {
	this->powerActivated = true;
	this->cooldown = 5;
	this->weLiveIn->addToCommentary("Człowiek aktywuje całopalenie!");
}


bool Human::isPowerActivated() const {
	return this->powerActivated;
}


void Human::cool() {
	if (this->cooldown > 0) --this->cooldown;
	if (this->powerActivated && this->cooldown == 0) {
		this->weLiveIn->addToCommentary("Całopalenie wyłączone, trzeba odczekać pięć tur");
		this->powerActivated = false;
		this->cooldown = 5;
	}
}


int Human::getCooldown() const {
	return this->cooldown;
}

void Human::setCooldown(int newCooldown) {
	this->cooldown = newCooldown;
}


void Human::burnThemAll() {
	// Indeks: 172064
	// 4 % 5 = 4
	// Umiejętność -> Całopalenie
	Organism *tmp;

	int index = this->weLiveIn->checkField(this->positionX, this->positionY - 1, -1);
	if (index >= 0) {
		std::string temp = "Człowiek pali ";
		tmp = this->weLiveIn->getOrganism(index);
		temp += tmp->returnString() + " X:" + std::to_string(tmp->getX()) + ", Y:" + std::to_string(tmp->getY());
		this->weLiveIn->addToCommentary(temp);
		this->weLiveIn->kill(index);
	}
	index = this->weLiveIn->checkField(this->positionX, this->positionY + 1, -1);
	if (index >= 0) {
		std::string temp = "Człowiek pali ";
		tmp = this->weLiveIn->getOrganism(index);
		temp += tmp->returnString() + " X:" + std::to_string(tmp->getX()) + ", Y:" + std::to_string(tmp->getY());
		this->weLiveIn->addToCommentary(temp);
		this->weLiveIn->kill(index);
	}
	index = this->weLiveIn->checkField(this->positionX - 1, this->positionY, -1);
	if (index >= 0) {
		std::string temp = "Człowiek pali ";
		tmp = this->weLiveIn->getOrganism(index);
		temp += tmp->returnString() + " X:" + std::to_string(tmp->getX()) + ", Y:" + std::to_string(tmp->getY());
		this->weLiveIn->addToCommentary(temp);
		this->weLiveIn->kill(index);
	}
	index = this->weLiveIn->checkField(this->positionX + 1, this->positionY, -1);
	if (index >= 0) {
		std::string temp = "Człowiek pali ";
		tmp = this->weLiveIn->getOrganism(index);
		temp += tmp->returnString() + " X:" + std::to_string(tmp->getX()) + ", Y:" + std::to_string(tmp->getY());
		this->weLiveIn->addToCommentary(temp);
		this->weLiveIn->kill(index);
	}
}
