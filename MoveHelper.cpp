#include "MoveHelper.h"

List<avaiableCells> MoveHelper::helpMeMove(int posX, int posY, World *thisOne) {
	List<avaiableCells> hereYouGo;

	if (posY - 1 > 0)
		hereYouGo.pushBack(new avaiableCells(posX, posY - 1));

	if (posY + 1 <= thisOne->getBoundY())
		hereYouGo.pushBack(new avaiableCells(posX, posY + 1));

	if (posX - 1 > 0)
		hereYouGo.pushBack(new avaiableCells(posX - 1, posY));

	if (posX + 1 <= thisOne->getBoundX())
		hereYouGo.pushBack(new avaiableCells(posX + 1, posY));

	return hereYouGo;
}


List<avaiableCells> MoveHelper::helpMeBreed(Organism or1, Organism or2, World *thisOne) {
	List<avaiableCells> hereYouGo;

	if (or1.getY() - 1 > 0 && thisOne->checkField(or1.getX(), or1.getY() - 1, -1) == -1)
		hereYouGo.pushBack(new avaiableCells(or1.getX(), or1.getY() - 1));

	if (or1.getY() + 1 <= thisOne->getBoundY() && thisOne->checkField(or1.getX(), or1.getY() + 1, -1) == -1)
		hereYouGo.pushBack(new avaiableCells(or1.getX(), or1.getY() + 1));

	if (or1.getX() - 1 > 0 && thisOne->checkField(or1.getX() - 1, or1.getY(), -1) == -1)
		hereYouGo.pushBack(new avaiableCells(or1.getX() - 1, or1.getY()));

	if (or1.getY() + 1 <= thisOne->getBoundX() && thisOne->checkField(or1.getX() + 1, or1.getY(), -1) == -1)
		hereYouGo.pushBack(new avaiableCells(or1.getX() + 1, or1.getY()));

	if (or2.getY() - 1 > 0 && thisOne->checkField(or2.getX(), or2.getY() - 1, -1) == -1)
		hereYouGo.pushBack(new avaiableCells(or2.getX(), or2.getY() - 1));

	if (or2.getY() + 1 <= thisOne->getBoundY() && thisOne->checkField(or2.getX(), or2.getY() + 1, -1) == -1)
		hereYouGo.pushBack(new avaiableCells(or2.getX(), or2.getY() + 1));

	if (or2.getX() - 1 > 0 && thisOne->checkField(or2.getX() - 1, or2.getY(), -1) == -1)
		hereYouGo.pushBack(new avaiableCells(or2.getX() - 1, or2.getY()));

	if (or2.getY() + 1 <= thisOne->getBoundX() && thisOne->checkField(or2.getX() + 1, or2.getY(), -1) == -1)
		hereYouGo.pushBack(new avaiableCells(or2.getX() + 1, or2.getY()));

	return hereYouGo;
}
