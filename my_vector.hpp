// simple version of vector

#ifndef _MY_VECTOR_HPP_
#define _MY_VECTOR_HPP_

#include <iostream>

template<typename T>
class Myvector {
private:
	int size;
	int max_size;
	T *arr;
	T *tail;
public:
	// Myvector();
	Myvector(int n);
	~Myvector();
	
	void push_back(T data);
	void erase(T data);
	int find(T data);
	bool empty();
	void clear();
	void print();

	T& operator[](int n);
	// Myvector<T>& operator=(const Myvector<T>& v);
};

// template<typename T>
// Myvector<T>::Myvector() {
// 	tail = arr = new T[10];
// 	size = 10;
// }

template<typename T>
Myvector<T>::Myvector(int n) {
	// tail = arr = new T[(int)(n*1.5)];
	tail = arr = new T[n];
	size = n;
	max_size = n;
}

template<typename T>
Myvector<T>::~Myvector() {
	delete [] arr;
	arr = tail = nullptr;
	size = 0;
	max_size = 0;
}

template<typename T>
void Myvector<T>::push_back(T data) {
	if (tail-arr >= max_size) {
		std::cout << "vector full" << std::endl;
		return;
	}

	*tail = data;
	tail++;
	size++;
	// if (size >= max_size) {
	// 	reallocate()
	// 	size++;
	// }
}

template<typename T>
void Myvector<T>::erase(T data) {
	if (empty()) {
		std::cout << "vector empty" << std::endl;
		return;
	}

	int index = -1;
	for (int i = 0; i < size; ++i) {
		if (arr[i] == data) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		std::cout << "can't find data" << std::endl;
		return;
	}

	for (int i = index; i < size-1; ++i)
		arr[i] = arr[i+1];

	size--;
	tail--;
}

template<typename T>
bool Myvector<T>::empty() {
	return size == 0;
}

template<typename T>
void Myvector<T>::clear() {
	// delete [] arr;
	tail = &arr[0];
	size = 0;
}

template<typename T>
void Myvector<T>::print() {
	if (empty()) {
		std::cout << "vector empty" << std::endl;
		return;
	}

	T *temp = arr;
	while (temp != tail) {
		std::cout << *temp << " ";
		temp++;
	}
	std::cout << std::endl;
}

template<typename T>
T& Myvector<T>::operator[](int n) {
	return arr[n];
}

// template<typename T>
// Myvector<T>& Myvector<T>::operator=(T data) {
// 	if (&v == this)
// 		return *this;
// 	this.arr[] // unfinished, return what?
// }

#endif // _MY_VECTOR_HPP_