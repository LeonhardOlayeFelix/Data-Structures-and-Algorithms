#include "MergeSort.h"

std::vector<int> MergeSort::sort(const std::vector<int>& vec)
{
	if (vec.empty()) return vec;

	if (vec.size() == 1) return vec;

	std::vector<int> Left (vec.begin(), vec.begin() + vec.size() / 2);
	std::vector<int> Right (vec.begin() + vec.size() / 2, vec.end());

	std::vector<int> L = sort(Left);
	std::vector<int> R = sort(Right);

	return merge(L, R);
}

std::vector<int> MergeSort::merge(const std::vector<int>& left, const std::vector<int>& right)
{
	std::vector<int> res(left.size() + right.size());
	int a = 0;
	int b = 0;

	int i = 0;
	while (a < left.size() && b < right.size()) {
		res[i++] = left[a] < right[b] ? left[a++] : right[b++];
	}

	while (a < left.size()) {
		res[i++] = left[a++];
	}

	while (b < right.size()) {
		res[i++] = right[b++];
	}

	return res;
}
