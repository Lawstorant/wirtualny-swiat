#ifndef WORLD_H
#define WORLD_H

#include "Organism.h"
#include "Aftermath.h"
#include "Characters.h"
#include "List.h"
#include "MoveHelper.h"
#include "Logger.h"
#include "Directions.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

class Organism;

class World {
protected:
	List<Organism> *organisms;
	int boundX;
	int boundY;
	Logger *shenanigans;
	bool gameOver;
	Directions humanDirection;

public:
	World(int newBX, int newBY, Logger *newShenanigans);
	World(int newBX, int newBY, List<Organism> *newOrganisms, Logger *newShenanigans);
	~World();
	void executeTurn();
	void drawWorld();
	int checkField(int x, int y, int omit) const;
	bool makeNew(Organism *newOrganism);
	void kill(int toKill);
	Organism* getOrganism(int index) const;
	int getOrganismCount() const;
	int getBoundX() const;
	int getBoundY() const;
	bool isGameOver() const;
	void setGameOver();
	void setHumanDirection(Directions newDirection);
	Directions getHumanDirection() const;
	void addToCommentary(std::string newString);
	void redirectToFile(std::ofstream &saveFile) const;
};


#endif
