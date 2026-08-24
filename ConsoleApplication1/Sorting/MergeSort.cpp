#include "MergeSort.h"

std::vector<int> MergeSort::sort(const std::vector<int> vec)
{
	if (vec.size() == 1)
		return vec;

	std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
	std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());

	std::vector<int> L = sort(left);
	std::vector<int> R = sort(right);

	return merge(L, R);
}

std::vector<int> MergeSort::merge(const std::vector<int> left, const std::vector<int> right) {
	std::vector<int> res(left.size() + right.size());


	int leftPtr = 0;
	int rightPtr = 0;

	int index = 0;

	while (leftPtr < left.size() && rightPtr < right.size()) {
		res[index++] = left[leftPtr] < right[rightPtr] ? left[leftPtr++] : right[rightPtr++];
	}

	while (leftPtr < left.size()) {
		res[index++] = left[leftPtr++];
	}

	while (rightPtr < right.size()) {
		res[index++] = right[rightPtr++];
	}

	return res;
}