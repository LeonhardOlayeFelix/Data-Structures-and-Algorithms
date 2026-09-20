#pragma once
#include "Heap.h"

class MinHeap : public Heap
{
public:
	MinHeap() = default;
	MinHeap(size_t size) : Heap(size) {};

	bool compare(int a, int b) override;
};

