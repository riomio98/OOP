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
#include <stdexcept>

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
	bool is_empty() const;
	bool is_full() const;
	T& operator[](size_t pos);
	const T& operator[](size_t pos) const;
	bool operator==(const Sequence& other) const;
	void insert(size_t pos, const T& ele); // größe anpassen
	void push_back(const T& ele);
	void remove(size_t pos);
	bool remove_ele(const T& ele);

	class iterator {
	friend class Sequence<T>;
	T* _current;
	iterator(T* current) : _current{current} {
	}
	public:
	iterator& operator++() {
		_current++;
		return *this;
	}
	T& operator*() {
		return *_current;
	}
	bool operator!=(iterator it) {
		return _current != it._current;
	}
	};
	iterator begin() {
		return iterator(_arr);
	}
	iterator end() {
		return iterator(_arr + _size);
	}


	};


template<typename T>
void Sequence<T>::recap(size_t size) {
	if(_cap == size)
	{
		return;
	}
	T* tmp = new T[size];
	if(size == 0)
	{
		throw std::runtime_error("cap must be > 0");
	}
	size_t i = 0;
	while(i < size && i < _size)
	{
		tmp[i] = _arr[i];
		i++;
	}
	delete [] _arr;
	_arr = tmp;
	_cap = size;
	if(_size > _cap)
	{
		_size = _cap;
	}
}

template<typename T>
void Sequence<T>::grow_on_demand() {
	if(is_full())
	{
		recap(_cap*2);
	}
}

template<typename T>
Sequence<T>::Sequence(size_t cap)
	:_size(0)
{
	if(cap == 0)
	{
		throw std::runtime_error("cap must be > 0");
	}
	_cap = cap;
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
	return _size;
}

template<typename T>
size_t Sequence<T>::capacity() const {
	return _cap;
}

template<typename T>
bool Sequence<T>::is_empty() const {
	return (_size == 0);
}
template<typename T>
bool Sequence<T>::is_full() const {
	return (_size == _cap);
}

template<typename T>
T& Sequence<T>::operator[](size_t pos) {
	if(pos >= _size)
	{
		throw std::runtime_error("Sequence::operator[]: pos out of bounds");
	}

	return _arr[pos];
}

template<typename T>
const T& Sequence<T>::operator[](size_t pos) const {
	if(pos >= _size)
	{
		throw std::runtime_error("Sequence::operator[]: pos out of bounds");
	}
	return _arr[pos];
}

template<typename T>
void Sequence<T>::insert(size_t pos, const T &ele) {
	if(pos > _size)
	{
		throw std::runtime_error("insert(): out of bounds");
	}
	if(is_full())
	{
		grow_on_demand();
	}
	for(size_t i = _size; i > pos; i--)
	{
		_arr[i] = _arr[i-1];
	}
	_size++; // nachher erhöhen
	_arr[pos] = ele;
}

template<typename T>
void Sequence<T>::push_back(const T &ele) {
	insert(_size,ele);
}

template<typename T>
void Sequence<T>::remove(size_t pos) {
	if(is_empty())
	{
		throw std::runtime_error("remove(): empty, underflow");
	}
	if(pos >= _size)
	{
		throw std::runtime_error("remove(): out of bounds");
	}
	_size--; // vorher erniedrigen
	for(size_t i = pos; i < _size; i++)
	{
		_arr[i] = _arr[i+1];
	}
}

template<typename T>
void Sequence<T>::trim() {
	if(_size < _cap && _size > 0)
	{
		recap(_size);
	}
}

template<typename T>
void Sequence<T>::clear() {
	_size = 0;
}

template<typename T>
bool Sequence<T>::operator ==(const Sequence &other) const {

	if(_size == other._size)
	{
		size_t idx = 0;
		while(idx < _size and _arr[idx] == other._arr[idx])
		{
			idx++;
		}
		if(idx == _size)
		{
			return true;
		}
	}
	return false;
}

template<typename T>
bool Sequence<T>::remove_ele(const T &ele) {
	for(size_t i= 0; i<_size; i++)
	{
		if(_arr[i] == ele)
		{
			remove(i);
			return true;
		}
	}
	return false;
}

#endif /* SEQUENCE_H_ */
