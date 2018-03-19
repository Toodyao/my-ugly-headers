#ifndef _MY_CIRCULAR_LIST_
#define _MY_CIRCULAR_LIST_

#include "my_singly_list.hpp"

template<typename T>
class Circularlist : public Mylist<T> {
public:
	Circularlist()  { }
	~Circularlist() { }

	typename Mylist<T>::node *next() {
	return Mylist<T>::iterator->next ? 
		Mylist<T>::iterator->next : Mylist<T>::list_head;
	}

};

#endif // _MY_CIRCULAR_LIST_
