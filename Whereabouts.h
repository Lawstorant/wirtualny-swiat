#ifndef WHEREABOUTS_H
#define WHEREABOUTS_H

class Whereabouts {
protected:
	int x;
	int y;

public:
	Whereabouts(int newX, int newY) {
		this->x = newX;
		this->y = newY;
	}


	const int getX() const {
		return this->x;
	}


	const int getY() const {
		return this->y;
	}


	void setX(int &newX) {
		this->x = newX;
	}


	void setY(int &newY) {
		this->y = newY;
	}


	bool equals(Whereabouts &checking) const {
		return ( getX() == checking.getX() && getY() == checking.getY());
	}
};

#endif
