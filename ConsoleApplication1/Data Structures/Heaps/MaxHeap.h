#pragma once
#include "Heap.h"

class MaxHeap : public Heap
{
public:
	MaxHeap() = default;
	MaxHeap(size_t size) : Heap(size) {};

	bool compare(int a, int b) override;
};

