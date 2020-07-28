#ifndef LOGGING_H
#define LOGGING_H

#include <string>
#include <iostream>
#include "List.h"

class Logger {
protected:
	List<std::string> *buffer;
public:
	Logger() {
		this->buffer = new List<std::string>();
	}

	void log(std::string newPost) {
		buffer->pushBack(newPost);
	}

	void printBuffer() {
		int len = buffer->getLength();

		for (int i = 0; i < len; ++i) {
			std::cout << *buffer->getCell(i) << std::endl;
		}
	}

	void clearBuffer() {
		delete this->buffer;
		this->buffer = new List<std::string>();
	}
};

#endif
