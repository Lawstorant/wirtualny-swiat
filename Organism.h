#ifndef ORGANISM_H
#define ORGANISM_H

#include "Aftermath.h"
#include "Characters.h"
#include <stdio.h>
#include "World.h"
#include <string>

class World;

typedef struct {
	int x;
	int y;
} Position;

class Organism {
protected:
	int strength;
	int age;
	int initiative;
	World *weLiveIn;
	int positionX;
	int positionY;
	Characters representation;
	std::string myName;


public:
	virtual bool action(){};
	virtual Organism* returnSelfType(int newX, int newY){};

	virtual Aftermath collision(Organism *invader);
	void draw() const;
	int getX() const;
	int getY() const;
	int getAge() const;
	void setAge(int newAge);
	int getInitiative() const;
	void makeOlder();
	void setX(int newX);
	void setY(int newY);
	Characters getType() const;
	int getStrength() const;
	void increaseStrength(int muchyMuchy);
	std::string returnString() const;

};


#endif
