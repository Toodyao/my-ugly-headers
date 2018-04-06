#ifndef _MY_STACK_
#define _MY_STACK_

#include "my_singly_list.hpp"

template<typename T>
class Mystack : public Mylist<T> {

public:
	Mystack() { }

	~Mystack() { }

	inline void push(T value) {
		Mylist<T>::push_front(value);
	}

	inline void pop() {
		Mylist<T>::pop_front();
	}

	inline T front() {
		// check empty() before use!
		return Mylist<T>::list_head->data;
	}

	inline bool empty() {
		return Mylist<T>::empty();
	}

	inline int size() {
		return Mylist<T>::size();
	}
};

#endif // _MY_STACK_