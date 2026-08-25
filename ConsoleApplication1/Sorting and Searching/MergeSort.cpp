#include "MergeSort.h"

std::vector<int> MergeSort::sort(const std::vector<int> vec)
{
	if (vec.size() == 1) 
		return vec;

	std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
	std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());

	return merge(sort(left), sort(right));
}

std::vector<int> MergeSort::merge(const std::vector<int> left, const std::vector<int> right)
{
	std::vector<int> res(left.size() + right.size());

	int l = 0;
	int r = 0;

	int index = 0;
	while (l < left.size() && r < right.size()) {
		res[index++] = left[l] < right[r] ? left[l++] : right[r++];
	}

	while (l < left.size()) {
		res[index++] = left[l++];
	}

	while (r < right.size()) {
		res[index++] = right[r++];
	}

	return res;
}
