#ifndef MOVE_HELPER_H
#define MOVE_HELPER_H

#include "List.h"
#include "World.h"
#include "Organism.h"

class World;
class Organism;

class avaiableCells {
public:
	int x;
	int y;
	avaiableCells(int newX, int newY) {
		this->x = newX;
		this->y = newY;
	}


};


class MoveHelper {
public:
	static List<avaiableCells> helpMeMove(int posX, int posY, World *thisOne);
	static List<avaiableCells> helpMeBreed(Organism or1, Organism or2, World *thisOne);
};


#endif
