// singly linked list without head node
#ifndef _MYLIST_HPP_
#define _MYLIST_HPP_

#include <iostream>

// TODO: add const
// TODO: finish list_tail
// TODO: add head node
template<class T>
class mylist {
private:
	struct node {
		T data;
		node *next;
		node(T d) {
			next = nullptr;
			data = d;
		}
	};
	int list_size;
	node *list_curr;
	node *list_head;
	node *list_tail;

public:
	mylist() {
		list_size = 0;
		list_curr = nullptr;
		list_head = nullptr;
		list_tail = nullptr;
	}

	~mylist() {
		clear();
	};
	
	bool empty() {
		return list_size == 0;
	}

	void push_back(T value) {
		if (list_size == 0) {
			list_curr = new node(value);
			list_tail = list_head = list_curr;
			list_size++;
		} else {
			node *temp = new node(value);
			list_tail->next = temp;
			list_tail = list_tail->next;
			list_size++;
		}
	}

	void insert(T find_data, T insert_data) {
		list_curr = list_head;
		while (list_curr->next != nullptr && 
				list_curr->data != find_data) {
			list_curr = list_curr->next;
		}
		
		node *temp = new node(insert_data);
		if (list_curr == nullptr) {
			// if can't find find_data
			list_curr->next = temp;
		} else {
			temp->next = list_curr->next;
			list_curr->next = temp;
		}

		list_size++;
	}

	void erase(T value) {
		list_curr = list_head;

		if (list_curr == nullptr) {
			std::cout << "list is empty!" << std::endl;
			return;
		}

		if (list_curr->data == value) {
			// value is in the first place
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
				pre->next = list_curr->next;
				delete list_curr;
				list_curr = pre->next;
				list_size--;
			} else {
				list_curr = list_curr->next;
				pre = pre->next;
			}
		}
	}

	void clear() {
		list_curr = list_head;
		while (list_curr != nullptr) {
			list_head = list_head->next;
			delete list_curr;
			list_curr = list_head;
		}
		list_size = 0;
	}

	int size() {
		return list_size;
	}

	void next();
	T front();
	T end();
	void move_to(T value);

	void print() {
		if(list_size == 0) {
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

};

#endif