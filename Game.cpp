#include "Game.h"

void Game::printMenu() const {
	std::cout << "[1] Dodaj zwierzę" << std::endl;
	std::cout << "[2] Dodaj roślinę" << std::endl;
	std::cout << "[3] Wyświetl listę organizmów" << std::endl;
	std::cout << "[4] Wczytaj grę z pliku (ignoruje podane wymiary)" << std::endl;
	std::cout << "[5] Zacznij grę" << std::endl;
}


void Game::addAnimal() {
	system("clear");
	char w;
	std::cout << "[1] Dodaj Wilka" << std::endl;
	std::cout << "[2] Dodaj Lisa" << std::endl;
	std::cout << "[3] Dodaj Owcę" << std::endl;
	std::cout << "[4] Dodaj Żółwia" << std::endl;
	std::cout << "[5] Dodaj Antylopę" << std::endl << std::endl << ">";
	std::cin >> w;

	bool f1 = false;

	while (!f1) {
		int newX = rand() % this->gameWorld->getBoundX() + 1;
		int newY = rand() % this->gameWorld->getBoundY() + 1;
		switch (w) {
		case '1':
			f1 = this->gameWorld->makeNew(new Wolf(newX, newY, this->gameWorld));
			break;
		case '2':
			f1 = this->gameWorld->makeNew(new Fox(newX, newY, this->gameWorld));
			break;
		case '3':
			f1 = this->gameWorld->makeNew(new Sheep(newX, newY, this->gameWorld));
			break;
		case '4':
			f1 = this->gameWorld->makeNew(new Tortoise(newX, newY, this->gameWorld));
			break;
		case '5':
			f1 = this->gameWorld->makeNew(new Antelope(newX, newY, this->gameWorld));
			break;
		}
	}
}


void Game::addPlant() {
	system("clear");
	char w;
	std::cout << "[1] Dodaj Trawę" << std::endl;
	std::cout << "[2] Dodaj Guaranę" << std::endl;
	std::cout << "[3] Dodaj Mlecz" << std::endl;
	std::cout << "[4] Dodaj Wilcze jagody" << std::endl;
	std::cout << "[5] Dodaj barszcz sosnowskiego" << std::endl << std::endl << ">";
	std::cin >> w;

	bool f1 = false;

	while (!f1) {
		int newX = rand() % this->gameWorld->getBoundX() + 1;
		int newY = rand() % this->gameWorld->getBoundY() + 1;
		switch (w) {
		case '1':
			f1 = this->gameWorld->makeNew(new Grass(newX, newY, this->gameWorld));
			break;
		case '2':
			f1 = this->gameWorld->makeNew(new Guarana(newX, newY, this->gameWorld));
			break;
		case '3':
			f1 = this->gameWorld->makeNew(new Dandelion(newX, newY, this->gameWorld));
			break;
		case '4':
			f1 = this->gameWorld->makeNew(new Nightshade(newX, newY, this->gameWorld));
			break;
		case '5':
			f1 = this->gameWorld->makeNew(new Hogweed(newX, newY, this->gameWorld));
			break;
		}
	}
}


void Game::printNextHumanMove() const {
	std::cout << "Kolejny ruch człowieka: ";
	switch (this->gameWorld->getHumanDirection()) {
	case UP:
		std::cout << "W Górę";
		break;
	case DOWN:
		std::cout << "W Dół";
		break;
	case LEFT:
		std::cout << "W Lewo";
		break;
	case RIGHT:
		std::cout << "W Prawo";
		break;
	}
	std::cout << std::endl;
}


void Game::humanMoves() const {
	char w;
	std::cin >> w;
	std::cin >> w;

	switch (w) {
	case 'A':
		this->gameWorld->setHumanDirection(UP);
		break;
	case 'B':
		this->gameWorld->setHumanDirection(DOWN);
		break;
	case 'D':
		this->gameWorld->setHumanDirection(LEFT);
		break;
	case 'C':
		this->gameWorld->setHumanDirection(RIGHT);
		break;
	}
}


void Game::printLegend() const {
	std::cout << "n - kolejna tura" << std::endl;
	std::cout << "a - aktywacja zdolności" << std::endl;
	std::cout << "strzałki - zmiana kierunku człowieka" << std::endl;
	std::cout << "s - zapis gry" << std::endl;
	std::cout << "l - wczytanie gry" << std::endl;
}


void Game::saveGame() const {
	std::ofstream file;
	system("clear");
	std::cout << "Podaj nazwę pliku do zapisu gry" << std::endl << ">";
	std::string tmp;
	std::cin >> tmp;
	file.open(tmp);
	if (file) {
		file << std::to_string(this->turn) << std::endl;
		file << this->myMan->isPowerActivated() << " " << std::to_string(this->myMan->getCooldown()) << std::endl;
		this->gameWorld->redirectToFile(file);
		file.close();
	}
	else {
		std::cout << "nie udało się zapisać gry :(" << std::endl;
		std::cin >> tmp;
	}
}


bool Game::loadSavedGame() {
	std::ifstream file;
	system("clear");
	std::cout << "Podaj nazwę pliku do wczytania gry" << std::endl << ">";
	std::string tmp;
	std::cin >> tmp;
	file.open(tmp);
	bool f1 = false;

	if (file) {
		int x, y, z, activated, cooldown;
		file >> x;
		this->turn = x;
		file >> activated >> cooldown;
		file >> x >> y;
		World *newWorld = new World(x, y, &this->commentary);
		file >> x >> y >> z;
		if(x == 1) newWorld->setGameOver();
		newWorld->setHumanDirection((Directions)y);

		int t, s, a, X, Y;
		for (int i = 0; i < z; ++i) {
			file >> t >> s >> a >> X >> Y;

			Organism *newOrganism;
			switch (t) {
				case WOLF:
					newOrganism = new Wolf(X, Y, newWorld);
					break;
				case SHEEP:
					newOrganism = new Sheep(X, Y, newWorld);
					break;
				case FOX:
					newOrganism = new Fox(X, Y, newWorld);
					break;
				case TORTOISE:
					newOrganism = new Tortoise(X, Y, newWorld);
					break;
				case ANTELOPE:
					newOrganism = new Antelope(X, Y, newWorld);
					break;
				case HUMAN: {
					Human *newHuman = new Human(X, Y, newWorld);
					this->myMan = newHuman;
					if(activated == 1) this->myMan->activatePower();
					this->myMan->setCooldown(cooldown);
					this->myMan->increaseStrength(s-this->myMan->getStrength());
					f1 = !newWorld->makeNew(newHuman);
					continue;
					break;
				}
				case GRASS:
					newOrganism = new Grass(X, Y, newWorld);
					break;
				case DANDELION:
					newOrganism = new Dandelion(X, Y, newWorld);
					break;
				case GUARANA:
					newOrganism = new Guarana(X, Y, newWorld);
					break;
				case NIGHTSHADE:
					newOrganism = new Nightshade(X, Y, newWorld);
					break;
				case HOGWEED:
					newOrganism = new Hogweed(X, Y, newWorld);
					break;
			}

			newOrganism->increaseStrength(s - newOrganism->getStrength());
			newOrganism->setAge(a);
			f1 = !newWorld->makeNew(newOrganism);
		}
		if(!f1) {
			delete this->gameWorld;
			this->gameWorld = newWorld;
			this->commentary.clearBuffer();
		} else {
			delete newWorld;
			this->turn = 0;
		}
	} else {
		f1 = true;
	}

	return f1;
}


Game::Game() {
	char w;
	int newX, newY, count = 0;

	system("clear");
	std::cout << "Podaj wymiary nowego świata:" << std::endl;
	std::cout << "X: ";
	std::cin >> newX;
	std::cout << std::endl << "Y: ";
	std::cin >> newY;
	this->gameWorld = new World(newX, newY, &this->commentary);

	do {
		system("clear");
		printMenu();
		std:: cout << ">";
		std::cin >> w;
		switch (w) {
		case '1':
			if (count < this->gameWorld->getBoundX() * this->gameWorld->getBoundY() - 1) {
				addAnimal();
				++count;
			}
			else {
				system("clear");
				std::cout << "Nie można dodać więcej organizmów" << std::endl;
				std::cin >> w;
			}
			break;

		case '2':
			if (count < this->gameWorld->getBoundX() * this->gameWorld->getBoundY() - 1) {
				addPlant();
				++count;
			}
			else {
				system("clear");
				std::cout << "Nie można dodać więcej organizmów" << std::endl;
				std::cin >> w;
			}
			break;

		case '3':
			system("clear");
			for (int i = 0; i < count; ++i) {
				this->gameWorld->getOrganism(i)->draw();
				printf(" ");
				if (i % 12 == 11) printf("\n");
			}
			std::cin >> w;
			break;

		case '4':
			if (!loadSavedGame()) w = '6';
			else {
				std::cout << "Nie udało się wczytać gry!" << std::endl;
				std::cin >> w;
			}
			break;
		}

	} while (w != '5' && w != '6');

	if(w == '5') {
		bool f1 = false;

		Human *xd;
		while (!f1) {
			int newX = rand() % this->gameWorld->getBoundX() + 1;
			int newY = rand() % this->gameWorld->getBoundY() + 1;
			xd = new Human(newX, newY, this->gameWorld);
			f1 = this->gameWorld->makeNew(xd);
		}
		this->myMan = xd;
		this->turn = 0;
	}
}


void Game::play() {
	char w;
	while (!this->gameWorld->isGameOver() && this->gameWorld->getOrganismCount() > 1) {
		do {
			system("clear");
			std::cout << "Tomasz Pakuła 172064" << std::endl;
			std::cout << "Tura: " << this->turn << std::endl;
			this->printNextHumanMove();
			std::cout << "Całopalenie: ";
			if (myMan->isPowerActivated()) {
				std::cout << "Aktywne" << std::endl;
				std::cout << "Pozostały tury: " << myMan->getCooldown() << std::endl;
			}
			else if (myMan->getCooldown() > 0) {
				std::cout << "Nieaktywne" << std::endl;
				std::cout << "Czas oczekiwania: " << myMan->getCooldown() << std::endl;
			}
			else {
				std::cout << "Gotowe" << std::endl << std::endl;
			}

			printLegend();
			std::cout << std::endl;
			this->gameWorld->drawWorld();
			std::cout << std::endl;
			commentary.printBuffer();

			std::cin >> w;
			switch (w) {
			case '\033':
				humanMoves();
				w = 'n';
				break;

			case 'a':
				if (myMan->getCooldown() == 0)
					myMan->activatePower();
				break;

			case 's':
				this->saveGame();
				break;

			case 'l':
				this->loadSavedGame();
				break;
			}

		} while (w != 'n');
		commentary.clearBuffer();
		if (myMan->isPowerActivated()) {
			myMan->burnThemAll();
		}
		this->gameWorld->executeTurn();
		if (myMan->isPowerActivated()) {
			myMan->burnThemAll();
		}
		myMan->cool();
		++turn;
	}
	system("clear");
	std::cout << "Koniec gry!" << std::endl;
	if (this->gameWorld->isGameOver())
		std::cout << "Przegrana!" << std::endl;
	else
		std::cout << "Wygrana!" << std::endl;
}


Game::~Game() {
	delete this->gameWorld;
}
