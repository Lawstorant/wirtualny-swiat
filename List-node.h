#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <cstddef>

template <class T>
class ListNode {
protected:
	T *data;
	ListNode *next;
	ListNode *previous;

public:
	ListNode() {
		previous = NULL;
		next = NULL;
	}


	ListNode(T *newData) {
		data = newData;
		next = NULL;
		previous = NULL;
	}

	ListNode(T *newData, ListNode *newNext, ListNode *newPrevious) {
		data = newData;
		next = newNext;
		previous = newPrevious;
	}


	void setData(T *newData) { this->data = newData; }
	void setNext(ListNode *newNext) { this->next = newNext; }
	void setPrevious(ListNode *newPrevious) {this->previous = newPrevious; }
	void clearNext() { this->next = NULL; }
	void clearPrevious() {this->previous = NULL; }
	T* getData() const { return this->data; }
	ListNode* getNext() const { return this->next; }
	ListNode* getPrevious() const { return this->previous; }

};


#endif
