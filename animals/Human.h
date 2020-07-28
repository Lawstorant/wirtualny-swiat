#ifndef HUMAN_H
#define HUMAN_H

#include "../Animal.h"
#include <iostream>

class Human : public Animal {
protected:
	int cooldown;
	bool powerActivated;

public:
	Human(int newX, int newY, World *braveNewWorld);
	Organism* returnSelfType(int newX, int newY);
	bool action();
	Aftermath collision(Organism *invader);
	void activatePower();
	bool isPowerActivated() const;
	void cool();
	void setCooldown(int newCooldown);
	int getCooldown() const;
	void burnThemAll();
};


#endif
