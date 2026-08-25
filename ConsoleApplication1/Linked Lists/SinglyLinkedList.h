#pragma once
#include "Node1.h"

class SinglyLinkedList
{
private:
	Node1* m_Head{};
	Node1* m_Tail{};
	int m_Size{ 0 };

public:
	SinglyLinkedList() = default;

	void append(int value);
	void prepend(int value);
	void insert(int value, int index);

	inline const Node1* Head() const { return m_Head; }
	inline const Node1* Tail() const { return m_Tail; }
};

