#pragma once
#include <vector>

class QuickSort
{
public:
	QuickSort() = delete;

	static void sort(std::vector<int>& list);

	static void partition(std::vector<int>& list, int left, int right);

};

