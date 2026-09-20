#pragma once
#include <vector>

class Heap
{
private:
	std::vector<int> m_Heap{};

public:
	Heap() = default;
	Heap(size_t size);

	void Heapify(std::vector<int> vec);
	void Push(int element);
	void Pop();
	int Front();
	inline size_t Size() { return m_Heap.size(); }
	inline bool Empty() { return m_Heap.size() == 0; }
	void PopAndPrint();

private:
	void bubbleUp(int index);
	void bubbleDown(int index);
	inline int parent(int index) { return (index - 1) / 2; };
	inline int leftChild(int index) { return 2 * index + 1; };
	inline int rightChild(int index) { return 2 * index + 2; };

	/// <summary>
	/// MAX heap should be Compare(a, b) <=> a < b; 
	/// MIN heap should be Compare(a, b) <=> a > b;
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>true if 'a' should appear below 'b' in the heap</returns>
	virtual bool compare(int a, int b) = 0; 

};

