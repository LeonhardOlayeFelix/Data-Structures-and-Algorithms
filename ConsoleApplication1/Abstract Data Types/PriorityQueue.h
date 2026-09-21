#pragma once
#include "../Data Structures/Heaps/Includes.h"
#include <type_traits>

template<typename HeapType>
class PriorityQueue
{
	static_assert(std::is_base_of<Heap, HeapType>::value, "T must derive from Heap");
	static_assert(!std::is_abstract<HeapType>::value, "T must be a concrete implementation");
	
private:
	HeapType m_Heap;

public:
	PriorityQueue() = default;
	PriorityQueue(std::vector<int> vec);

	void Push(int element);
	void Pop();
	int Front();
	inline size_t Size() { return m_Heap.Size(); };
	inline bool Empty() { return m_Heap.Empty(); };
};

template<typename HeapType>
inline PriorityQueue<HeapType>::PriorityQueue(std::vector<int> vec)
{
	m_Heap.Heapify(vec);
}

template<typename HeapType>
inline void PriorityQueue<HeapType>::Push(int element)
{
	m_Heap.Push(element);
}

template<typename HeapType>
inline void PriorityQueue<HeapType>::Pop()
{
	m_Heap.Pop();
}

template<typename HeapType>
inline int PriorityQueue<HeapType>::Front()
{
	return m_Heap.Front();
}
