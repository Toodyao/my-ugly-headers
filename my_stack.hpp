#ifndef _MY_STACK_
#define _MY_STACK_

#include "my_singly_list.hpp"

template<typename T>
class Mystack : public Mylist<T> {

public:
	Mystack() { }

	~Mystack() { }

	void push(T value) {
		Mylist<T>::push_front(value);
	}

	void pop() {
		Mylist<T>::pop_front();
	}

	T top() {
		// check empty() before use!
		return Mylist<T>::list_head->data;
	}

	bool empty() {
		return Mylist<T>::empty();
	}

	int size() {
		return Mylist<T>::size();
	}
};

#endif // _MY_STACK_