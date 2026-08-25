#pragma once
#include "Node2.h"

class DoublyLinkedList
{
private:
	Node2* m_Head;
	Node2* m_Tail;
	int m_Size{ 0 };
public:

public:
	inline const Node2* Head() { return m_Head; }
	inline const Node2* Tail() { return m_Tail; }
};

