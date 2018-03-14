#ifndef _MY_STACK_
#define _MY_STACK_

#include "my_singly_list.hpp"

template<typename T>
class Mystack : public Mylist<T> {

public:
	Mystack() { }

	~Mystack() { }

	void push(T value) {
		this->push_front(value);
	}

	void pop() {
		this->pop_front();
	}

	T top() {
		// check empty() before use!
		return this->list_head->data;
	}

	bool empty() {
		return this->empty();
	}

	int size() {
		return this->size();
	}
};

#endif // _MY_STACK_