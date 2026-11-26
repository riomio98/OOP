/*
 * queue_temp.h
 *
 *  Created on: 26.11.2026
 *      Author: n3034770
 */

#ifndef QUEUE_TEMP_H_
#define QUEUE_TEMP_H_

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <utility>

template<typename T>
class Queue{
private:
	struct Node{
		T val;
		Node* next;
	};

	Node* head;
	Node* tail;

public:
	Queue();
	Queue(const Queue& other);
	Queue<T>& operator=(const Queue& other);
	~Queue();
	void enter(const T& t);
	T leave();
	bool is_empty() const;
	size_t size() const;
};

template<typename T>
Queue<T>::Queue()
	:head(nullptr), tail(nullptr)
{

}

template<typename T>
Queue<T>::Queue(const Queue &other)
	:head(nullptr), tail(nullptr)
{
	Node* i = other.head;
	while(i != nullptr)
	{
		enter(i->val);
		i = i->next;
	}
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue &other) {

//	if(this != &other)
//	{
//		while(!is_empty())
//		{
//			leave();
//		}
//		Node* i = other.head;
//		while(i != nullptr)
//		{
//			enter(i->val);
//			i = i->next;
//		}
//	}
	Queue<T> tmp = other;
	std::swap(head, tmp.head);

	std::swap(tail, tmp.tail);

	return *this;
}

template<typename T>
Queue<T>::~Queue() {

	while(!is_empty())
	{
		leave();
	}
}

template<typename T>
void Queue<T>::enter(const T& value) {


	Node* new_entry = new Node;
	new_entry->val = value;
	new_entry->next = nullptr;

	if(is_empty())
	{

		head = new_entry;
		tail = new_entry;
 	}
	else{

		tail->next = new_entry;
		tail = new_entry;

	}
}

template<typename T>
T Queue<T>::leave() {


	if(is_empty())
	{
		throw std::runtime_error("leave(): leer");
	}

	Node* i = head;

	T tmp = head->val;
	head = i->next;
	delete i;


	if(head == nullptr)
	{
		tail = nullptr;
	}

	return tmp;


}

template<typename T>
bool Queue<T>::is_empty() const {
	return (head==nullptr);
}

template<typename T>
size_t Queue<T>::size() const {
	Node* i = head;
	size_t cnt = 0;
	while(i != nullptr)
	{
		cnt++;
		i = i->next;
	}
	return cnt;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& q)
{
    Queue<T> tmp(q);
    size_t i = 0;

    while (!tmp.is_empty())
    {
        out << "(" << i << ":" << tmp.leave() << ") ";
        i++;
    }

    return out;
}
template<typename T>
void is_empty_print(Queue<T>& s)
{
	if(s.is_empty())
	{
		std::cout << "Status: empty" << std::endl;
	}
	else{
		std::cout << "Status: not empty" << std::endl;
	}
}


#endif /* QUEUE_TEMP_H_ */
