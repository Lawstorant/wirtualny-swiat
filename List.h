#ifndef LIST_H
#define LIST_H

#include <cstddef>
#include <stdio.h>
#include "List-node.h"

template <class T>
class List {
protected:
	int listLength;
	ListNode<T> *start;
	ListNode<T> *end;

	ListNode<T> *getStart() const { return start; }
	ListNode<T> *getEnd() const { return end; }
	void setStart(ListNode<T> *newStart) { this->start = newStart; }
	void setEnd(ListNode<T> *newEnd) {this->end = newEnd; }
	void increaseLength() { ++this->listLength; }
	void decreaseLength() { --this->listLength; }

public:
	List() {
		this->listLength = 0;
		this->start = NULL;
		this->end = NULL;
	}


	int getLength() const { return listLength; }


	T* getCell(int cell)  {
		int len = getLength();
		if (cell < len && cell >= 0) {
			if (cell <= len / 2) {
				ListNode<T> *tmp = getStart();

				for (int i = 0; i < cell; ++i) {
					tmp = tmp->getNext();
				}
				return tmp->getData();
			}
			else {
				ListNode<T> *tmp = this->getEnd();

				for (int i = 0; i < len - cell - 1; ++i) {
					tmp = tmp->getPrevious();
				}
				return tmp->getData();
			}
		}
		else return NULL;
	}


	void pushStart(T *newData)  {
		int len = getLength();
		if (len != 0) {
			ListNode<T> *tmp = getStart();
			ListNode<T> *newNode = new ListNode<T>(newData);
			newNode->setNext(tmp);
			tmp->setPrevious(newNode);
			this->setStart(newNode);
			increaseLength();
		}
		else {
			ListNode<T> *tmp = new ListNode<T>(newData);
			this->setStart(tmp);
			this->setEnd(tmp);
			increaseLength();
		}
	}


	void pushBack(T *newData) {
		int len = getLength();
		if (len != 0) {
			ListNode<T> *tmp = getEnd();

			ListNode<T> *newNode = new ListNode<T>(newData);
			newNode->setPrevious(tmp);
			tmp->setNext(newNode);
			this->setEnd(newNode);
			increaseLength();
		}
		else {
			ListNode<T> *tmp = new ListNode<T>(newData);
			this->setStart(tmp);
			this->setEnd(tmp);
			this->increaseLength();
		}
	}


	void pushBack(T newData) {
		int len = getLength();
		if (len != 0) {
			ListNode<T> *tmp = getEnd();

			T *dat = new T;
			*dat = newData;

			ListNode<T> *newNode = new ListNode<T>(dat);
			newNode->setPrevious(tmp);
			tmp->setNext(newNode);
			this->setEnd(newNode);
			increaseLength();
		}
		else {
			T *dat = new T;
			*dat = newData;
			ListNode<T> *tmp = new ListNode<T>(dat);
			this->setStart(tmp);
			this->setEnd(tmp);
			this->increaseLength();
		}
	}


	void pushAfter(T *newData, int index) {
		int len = getLength();
		if (len == 0 && index == -1) {
			this->pushBack(newData);
		}
		else if (index == -1) {
			this->pushStart(newData);
		}
		else if (index < len - 1) {
			ListNode<T> *tmp = getStart();

			for (int i = 0; i < index; ++i) {
				tmp = tmp->getNext();
			}

			ListNode<T> *newNode = new ListNode<T>(newData, tmp->getNext(), tmp);
			tmp->getNext()->setPrevious(newNode);
			tmp->setNext(newNode);
			this->increaseLength();
		}
		else
			this->pushBack(newData);
	}


	void popBack() {
		int len = getLength();

		if (len > 0) {
			ListNode<T> *tmp = getStart();

			for (int i = 0; i < len - 1; ++i) {
				tmp = tmp->getNext();
			}

			delete tmp->getNext();
			tmp->clearNext();
			decreaseLength();
		}
	}


	void popStart() {
		int len = getLength();
		if (len > 0) {
			ListNode<T> *tmp = getStart();
			if (len > 1) {
				setStart(tmp->getNext());
				this->getStart()->clearPrevious();
			}
			else setStart(NULL);
			delete tmp;
			decreaseLength();
		}
	}


	void popSelected(int index) {
		int len = this->getLength();
		if (index >= 0 && index < len) {
			ListNode<T> *tmp = this->getStart();

			for (int i = 0; i < index; ++i) {
				tmp = tmp->getNext();
			}

			if (index > 0) tmp->getPrevious()->setNext(tmp->getNext());
			else this->start = tmp->getNext();
			if (index < len - 1) tmp->getNext()->setPrevious(tmp->getPrevious());
			else this->end = tmp->getPrevious();
			delete tmp;
			decreaseLength();
		}
	}


	T operator[] (int index) {
		return this->getCell(index);
	}


	~List() {
		int len = getLength();

		ListNode<T> *tmp = getStart();
		ListNode<T> *tmp2;
		if (len > 1) tmp2 = tmp->getNext();

		for (int i = 1; i <= len; ++i) {
			delete tmp;
			if (i < len) {
				tmp = tmp2;
				tmp2 = tmp->getNext();
			}
		}
	}


};


#endif
