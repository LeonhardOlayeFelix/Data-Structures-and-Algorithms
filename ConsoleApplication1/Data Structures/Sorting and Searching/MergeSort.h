#pragma once
#include <vector>

class MergeSort
{
public:
	MergeSort() = delete;

	static std::vector<int> sort(const std::vector<int>& vec);

private:
	static std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right);
};

