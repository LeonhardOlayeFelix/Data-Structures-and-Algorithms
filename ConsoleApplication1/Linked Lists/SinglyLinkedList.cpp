#include "SinglyLinkedList.h"
#include <stdexcept>

void SinglyLinkedList::append(int value)
{
	Node1* p = new Node1(value);

	if (m_Head == nullptr) {
		m_Head = p;
		m_Tail = p;
	}
	else {
		m_Tail->Next = p;
		m_Tail = p;
	}

	m_Size++;
}

void SinglyLinkedList::prepend(int value)
{
	Node1* p = new Node1(value);

	if (m_Head == nullptr) {
		m_Head = p;
		m_Tail = p;
	}
	else {
		p->Next = m_Head;
		m_Head = p;
	}
	m_Size++;
}

void SinglyLinkedList::insert(int value, int index)
{
	if (index >= m_Size)
		throw std::runtime_error("index is outside of bounds of array");

	if (index == 0) {
		prepend(value);
		return;
	}

	Node1* newNode = new Node1(value);
	Node1* current = m_Head;

	for (int i = 0; i < index - 1; i++)
		current = current->Next;

	Node1* temp = current->Next;
	current->Next = newNode;
	newNode->Next = temp;
	m_Size++;
}
