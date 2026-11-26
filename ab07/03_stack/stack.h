/*
 * stack.h
 *
 *  Created on: 25.11.2026
 *      Author: n3034770
 */

#ifndef STACK_H_
#define STACK_H_

#include <cstddef>
#include "sequence.h"

template<typename T>
class Stack{
private:
	Sequence<T> _seq;

public:
	bool is_empty() const;
	T top() const;
	void push(const T& ele);
	T pop();
	size_t size() const;
};

template<typename T>
bool Stack<T>::is_empty() const {
	return (_seq.is_empty());
}

template<typename T>
T Stack<T>::top() const {
	if(_seq.is_empty())
	{
		throw std::runtime_error("top(): leer");
	}
	return _seq[_seq.size()-1];
}

template<typename T>
void Stack<T>::push(const T &ele) {
	_seq.insert(_seq.size(), ele);
}

template<typename T>
T Stack<T>::pop() {
	if(_seq.is_empty())
	{
		throw std::runtime_error("pop(): leer");
	}
	T ele =_seq[_seq.size()-1];
	_seq.remove(_seq.size()-1);
	return ele;

}

template<typename T>
size_t Stack<T>::size() const {
	return _seq.size();
}

#endif /* STACK_H_ */
