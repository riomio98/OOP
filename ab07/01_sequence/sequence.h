/*
 * sequence.h
 *
 *  Created on: 19.11.2026
 *      Author: n3034770
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <cstddef>
#include <utility>

template <typename T>
class Sequence{
private:
	T* _arr;
	size_t _cap; // wenn notwendig größer machen
	size_t _size; // genau auf größe setzen
	void recap(size_t _size);
	void grow_on_demand();
public:
	Sequence(size_t cap = 1); // cap > 0
	Sequence(const Sequence&);
	Sequence& operator=(const Sequence&);
	~Sequence();
	size_t size() const;
	size_t capacity() const;
	void trim(); // nur so viele elemente wie gebraucht
	void clear();
	void is_empty() const;
	T& operator[](size_t pos);
	const T& operator[](size_t pos) const;
	void insert(size_t pos, const T& ele); // größe anpassen
	void push_back(const T& ele);
	void remove(size_t pos);
	bool remove_ele(const T& ele);



};

template<typename T>
void Sequence<T>::recap(size_t size) {

}

template<typename T>
void Sequence<T>::grow_on_demand() {
}

template<typename T>
Sequence<T>::Sequence(size_t cap)
	:_cap(cap), _size(0)
{
	_arr = new T[cap];
}

template<typename T>
Sequence<T>::Sequence(const Sequence& other)
	:_cap(other._cap), _size(other._size)
{
	_arr = new T[_cap];
	for(size_t i = 0; i < _size; i++)
	{
		_arr[i] = other._arr[i];
	}
}

template<typename T>
Sequence<T>& Sequence<T>::operator=(const Sequence& other)
{
	Sequence tmp(other);
	std::swap(_cap,tmp._cap);
	std::swap(_size,tmp._size);
	std::swap(_arr,tmp._arr);
	return *this;
}

template<typename T>
Sequence<T>::~Sequence() {
	delete [] _arr;
	_arr = nullptr;
	_size = 0;
}

template<typename T>
size_t Sequence<T>::size() const {
	return 0;
}

template<typename T>
size_t Sequence<T>::capacity() const {
	return 0;
}

template<typename T>
void Sequence<T>::is_empty() const {
	return;
}

template<typename T>
T& Sequence<T>::operator [](size_t pos) {
	return _arr[pos];
}

template<typename T>
const T& Sequence<T>::operator [](size_t pos) const {
	return _arr[pos];
}

template<typename T>
void Sequence<T>::insert(size_t pos, const T &ele) {
	return;
}

template<typename T>
void Sequence<T>::push_back(const T &ele) {
	return;
}

template<typename T>
void Sequence<T>::remove(size_t pos) {
	return;
}

template<typename T>
bool Sequence<T>::remove_ele(const T &ele) {
	return true;
}

#endif /* SEQUENCE_H_ */
