// simple version of vector

#ifndef _MY_VECTOR_HPP_
#define _MY_VECTOR_HPP_

#include <iostream>

// TODO: perfect dynamic array & tail pointer
template<typename T>
class Myvector {
private:
	int arr_size;
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
	inline int size();
	inline bool empty();
	void clear();
	void print();

	inline T& operator[](int n);
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
	arr = new T[n];
	tail = arr+n;
	arr_size = n;
	max_size = n;
}

template<typename T>
Myvector<T>::~Myvector() {
	delete [] arr;
	arr = tail = nullptr;
	arr_size = 0;
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
	arr_size++;
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
	for (int i = 0; i < arr_size; ++i) {
		if (arr[i] == data) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		std::cout << "can't find data" << std::endl;
		return;
	}

	for (int i = index; i < arr_size-1; ++i)
		arr[i] = arr[i+1];

	arr_size--;
	tail--;
}

template<typename T>
inline bool Myvector<T>::empty() {
	return arr_size == 0;
}

template<typename T>
inline int Myvector<T>::size() {
	return arr_size;
}

template<typename T>
void Myvector<T>::clear() {
	// delete [] arr;
	tail = &arr[0];
	arr_size = 0;
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

inline template<typename T>
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