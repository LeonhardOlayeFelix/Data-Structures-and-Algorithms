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

void SinglyLinkedList::insert(int value, unsigned int index)
{
	if (index >= m_Size)
		throw std::runtime_error("Index is outside of bounds of linked list.");

	if (index == 0) {
		prepend(value);
		return;
	}

	Node1* toInsert = new Node1(value);
	Node1* oneBefore = m_Head;

	for (unsigned int i = 0; i < index - 1; i++)
		oneBefore = oneBefore->Next;

	Node1* temp = oneBefore->Next;
	oneBefore->Next = toInsert;
	toInsert->Next = temp;
	m_Size++;
}

void SinglyLinkedList::pop_head()
{
	if (m_Size == 0)
		throw std::runtime_error("Head is null. Cannot be popped.");

	if (m_Size == 1) {
		delete m_Head;
		m_Head = nullptr;
		m_Tail = nullptr;
		m_Size--;
		return;
	}

	Node1* next = m_Head->Next;
	delete m_Head;
	m_Head = next;
	m_Size--;
	return;

}

void SinglyLinkedList::pop_tail() {
	if (m_Size == 0)
		throw std::runtime_error("Tail is null. Cannot be popped");

	if (m_Size == 1) {
		delete m_Head;
		m_Head = nullptr;
		m_Tail = nullptr;
		m_Size--;
		return;
	}

	Node1* t = m_Head;
	Node1* h = m_Head->Next;
	while (h->Next != nullptr) {
		t = t->Next;
		h = h->Next;
	}

	t->Next = nullptr;
	delete h;
	m_Tail = t;
	m_Size--;
}

void SinglyLinkedList::remove(unsigned int index)
{
	if (index >= m_Size)
		throw std::runtime_error("Index is outside of bounds of linked list.");

	if (index == 0) {
		pop_head();
		return;
	}

	if (index == m_Size - 1) {
		pop_tail();
		return;
	}

	Node1* oneBefore = m_Head;

	for (unsigned int i = 0; i < index - 1; i++) {
		oneBefore = oneBefore->Next;
	}

	Node1* toDelete = oneBefore->Next;
	oneBefore->Next = toDelete->Next;

	delete toDelete;
	m_Size--;
}

std::string SinglyLinkedList::Traverse()
{
	std::string result = "{";

	Node1* current = m_Head;

	while (current != nullptr && current->Next != nullptr) {
		result += std::to_string(current->Data()) + ", ";
		current = current->Next;
	}
	
	result += (current != nullptr) ? std::to_string(current->Data()) : "";

	result += "}";

	return result;
}

