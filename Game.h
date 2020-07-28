#ifndef GAME_H
#define GAME_H

#include "World.h"
#include "animals/incAllAnimals.h"
#include "plants/incAllPlants.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <curses.h>

class Game {
protected:
	int turn;
	Logger commentary;
	World *gameWorld;
	Human *myMan;

	void printMenu() const;
	void addAnimal();
	void addPlant();
	void printNextHumanMove() const;
	void humanMoves() const;
	void printLegend() const;
	void saveGame() const;
	bool loadSavedGame();

public:
	Game();
	void play();

	~Game();
};


#endif
