#include "DoublyLinkedList.h"
#include <stdexcept>

void DoublyLinkedList::append(int value)
{
	Node2* p = new Node2(value);

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

void DoublyLinkedList::prepend(int value)
{
	Node2* p = new Node2(value);

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

void DoublyLinkedList::insert(int value, unsigned int index)
{
	if (index >= m_Size)
		throw std::runtime_error("Index is outside of bounds of linked list.");

	if (index == 0) {
		prepend(value);
		return;
	}

	Node2* toInsert = new Node2(value);
	Node2* oneBefore = m_Head;

	for (unsigned int i = 0; i < index - 1; i++)
		oneBefore = oneBefore->Next;

	Node2* temp = oneBefore->Next;
	oneBefore->Next = toInsert;
	toInsert->Next = temp;
	m_Size++;
}

void DoublyLinkedList::pop_head()
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

	Node2* next = m_Head->Next;
	delete m_Head;
	m_Head = next;
	m_Size--;
	return;

}

void DoublyLinkedList::pop_tail() {
	if (m_Size == 0)
		throw std::runtime_error("Tail is null. Cannot be popped");

	if (m_Size == 1) {
		delete m_Head;
		m_Head = nullptr;
		m_Tail = nullptr;
		m_Size--;
		return;
	}

	Node2* t = m_Head;
	Node2* h = m_Head->Next;
	while (h->Next != nullptr) {
		t = t->Next;
		h = h->Next;
	}

	t->Next = nullptr;
	delete h;
	m_Tail = t;
	m_Size--;
}

void DoublyLinkedList::remove(unsigned int index)
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

	Node2* oneBefore = m_Head;

	for (unsigned int i = 0; i < index - 1; i++) {
		oneBefore = oneBefore->Next;
	}

	Node2* toDelete = oneBefore->Next;
	oneBefore->Next = toDelete->Next;

	delete toDelete;
	m_Size--;
}

void DoublyLinkedList::reverse()
{
	if (m_Size == 0 or m_Size == 1) return;

	if (m_Size == 2) {
		Node2* temp = m_Tail;
		m_Tail = m_Head;
		m_Tail->Next = nullptr;
		m_Head = temp;
		m_Head->Next = m_Tail;
		return;
	}

	Node2* prev = nullptr;
	Node2* current = m_Head;

	while (current != nullptr) {
		Node2* next = current->Next;
		current->Next = prev;
		prev = current;
		current = next;
	}

	m_Tail = m_Head;
	m_Head = prev;
}

std::string DoublyLinkedList::traverse() const
{
	std::string result = "{";

	Node2* current = m_Head;

	while (current != nullptr && current->Next != nullptr) {
		result += std::to_string(current->Data()) + ", ";
		current = current->Next;
	}

	result += (current != nullptr) ? std::to_string(current->Data()) : "";

	result += "}";

	return result;
}