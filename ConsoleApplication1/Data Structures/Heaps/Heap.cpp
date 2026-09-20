#include "Heap.h"
#include <iostream>
#include <utility>


Heap::Heap(size_t size)
{
	m_Heap.reserve(size);
}

void Heap::Heapify(std::vector<int> vec)
{
	m_Heap = std::move(vec);
	int size = m_Heap.size();

	for (int i = size - 1; i >= 0; i--) {
		bubbleDown(i);
	}
}

void Heap::Push(int element)
{
	m_Heap.push_back(element);

	bubbleUp(m_Heap.size() - 1);
}

void Heap::Pop()
{
	std::swap(m_Heap[0], m_Heap[m_Heap.size() - 1]);

	m_Heap.pop_back();

	bubbleDown(0);
}

int Heap::Front()
{
	if (m_Heap.empty()) return -1;

	return m_Heap[0];
}

void Heap::PopAndPrint()
{
	std::cout << "{";
	while (!m_Heap.empty()) {
		std::cout << Front();
		Pop();
		
		if (!m_Heap.empty()) std::cout << ", ";
	}

	std::cout << "}" << std::endl;
}

void Heap::bubbleUp(int index)
{
	int curr = index;
	
	while (curr > 0 && compare(m_Heap[parent(curr)], m_Heap[curr])) {

		std::swap(m_Heap[parent(curr)], m_Heap[curr]);
		curr = parent(curr);
	}
}

void Heap::bubbleDown(int index)
{
	int curr = index;
	int size = m_Heap.size();

	while (leftChild(curr) < size) {
		int left = leftChild(curr);
		int right = rightChild(curr);
		
		int toSwap = left;

		if (right < size && compare(m_Heap[left], m_Heap[right]))
			toSwap = right;

		if (compare(m_Heap[curr], m_Heap[toSwap])) {

			std::swap(m_Heap[curr], m_Heap[toSwap]);
			curr = toSwap;

		}
		else
			break;
	}
}
