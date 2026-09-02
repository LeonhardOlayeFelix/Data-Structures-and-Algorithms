#pragma once
#include "Node2.h"
#include <string>

class DoublyLinkedList
{
private:
	Node2* m_Head;
	Node2* m_Tail;
	int m_Size{ 0 };
public:
	DoublyLinkedList() = default;

	void append(int value);
	void prepend(int value);
	void insert(int value, unsigned int index);
	void pop_head();
	void pop_tail();
	void remove(unsigned int index);
	void reverse();
	std::string traverse() const;


public:
	inline const Node2* Head() { return m_Head; }
	inline const Node2* Tail() { return m_Tail; }
};

