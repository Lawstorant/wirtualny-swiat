#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include <iostream>
#include <curses.h>

using namespace std;

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	Game gra;
	gra.play();
	return 0;
}
