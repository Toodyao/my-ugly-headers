// singly linked list without head node
// added iterator

#ifndef _MY_SINGLY_LIST_HPP_
#define _MY_SINGLY_LIST_HPP_

#include <iostream>

// TODO: add const
template<typename T>
class Mylist {
protected:
	struct node {
		T data;
		node *next;
		node(T d) {
			data = d;
			next = nullptr;
		}
	};
	int list_size;
	node *list_curr;
	node *list_head;
	node *list_tail;

public:
	node *iterator;

	Mylist ();
	~Mylist();

	bool empty();
	int  size ();

	void push_back (T value);
	void push_front(T value);
	void pop_front ();
	void insert(T find_data, T insert_data);
	void erase (T value);
	void clear ();

	void print();

	node* begin();
	node* end  ();
	node* next ();
	node* move_to(T value);


};

// basic functions begin:
template<typename T>
Mylist<T>::Mylist() {
	list_size = 0;
	list_curr = nullptr;
	list_head = nullptr;
	list_tail = nullptr;
	iterator  = nullptr;
}

template<typename T>
Mylist<T>::~Mylist() {
	clear();
}

template<typename T>
bool Mylist<T>::empty() {
	return list_size == 0;
}

template<typename T>
void Mylist<T>::push_back(T value) {
	if (empty()) {
		list_curr = new node(value);
		list_tail = list_head = list_curr;
	} else {
		node *temp = new node(value);
		list_tail->next = temp;
		list_tail = list_tail->next;
	}
	list_size++;
}

template<typename T>
void Mylist<T>::push_front(T value) {
	list_curr = new node(value);

	if (empty()) {
		list_tail = list_head = list_curr;
	} else {
		list_curr->next = list_head;
		list_head = list_curr;
	}
	list_size++;
}

template<typename T>
void Mylist<T>::pop_front() {
	if (empty()) {
		std::cout << "list is empty!" << std::endl;
		return;
	}

	list_curr = list_head;
	list_head = list_head->next;
	delete list_curr;
	list_curr = list_head;

	list_size--;
}

template<typename T>
void Mylist<T>::insert(T find_data, T insert_data) {
	list_curr = list_head;
	while (list_curr->next != nullptr &&
	        list_curr->data != find_data) {
		list_curr = list_curr->next;
	}

	node *temp = new node(insert_data);
	if (list_curr == nullptr) {
		// if can't find find_data
		list_curr->next = temp;
		list_tail = temp;
	} else {
		temp->next = list_curr->next;
		list_curr->next = temp;
	}

	list_size++;
}

template<typename T>
void Mylist<T>::erase(T value) {
	list_curr = list_head;

	if (list_curr == nullptr) {
		std::cout << "list is empty!" << std::endl;
		return;
	}

	if (list_curr->data == value) {
		// value is in the first place

		// if iterator is on the value to be erased
		// move the iterator to the next position
		if (iterator == list_curr)
			iterator = list_curr->next;

		node *temp = list_head;
		list_head = list_head->next;
		delete temp;
		list_size--;
		return;
	}

	list_curr = list_curr->next;
	node *pre = list_head;
	while (list_curr != nullptr) {
		if (list_curr->data == value) {
			// move iterator to next
			if (iterator == list_curr)
				iterator = list_curr->next ? 
						list_curr->next : list_head;
				// iterator = next();
			
			pre->next = list_curr->next;
			delete list_curr;

			// correct tail pointer
			if (pre->next == nullptr)
				list_tail = pre;
			

			list_curr = pre->next;
			list_size--;
		} else {
			list_curr = list_curr->next;
			pre = pre->next;
		}
	}
}

template<typename T>
void Mylist<T>::clear() {
	list_curr = list_head;
	while (list_curr != nullptr) {
		list_head = list_head->next;
		delete list_curr;
		list_curr = list_head;
	}
	list_size = 0;
	list_curr = nullptr;
	list_head = nullptr;
	list_tail = nullptr;
	iterator  = nullptr;
}

template<typename T>
void Mylist<T>::print() {
	if (list_size == 0) {
		std::cout << "list is empty!" << std::endl;
		return;
	}

	list_curr = list_head;
	while (list_curr != nullptr) {
		std::cout << list_curr->data << " ";
		list_curr = list_curr->next;
	}
	std::cout << std::endl;
}

template<typename T>
int Mylist<T>::size() {
	return list_size;
}
// basic funtions end


// iterator public functions begin:
template<typename T>
typename Mylist<T>::node *Mylist<T>::begin() {
	return list_head;
}

template<typename T>
typename Mylist<T>::node *Mylist<T>::end() {
	return list_tail;
}

template<typename T>
typename Mylist<T>::node *Mylist<T>::move_to(T value) {
	iterator = begin();
	while (iterator != nullptr) {
		if (iterator->data == value)
			break;
		iterator = iterator->next;
	}
	return iterator;
}

template<typename T>
typename Mylist<T>::node *Mylist<T>::next() {
	return iterator != nullptr ? 
		iterator->next : nullptr;
}
// iterator public functions end;


#endif // _MY_SINGLY_LIST_HPP_