#include "BinarySearch.h"

int BinarySearch::search(const std::vector<int> list, int target)
{
	return searchIterative(list, target);
}

int BinarySearch::search(const std::vector<int> list, int target, int left, int right)
{
	if (left >= right) return -1;

	int middle = left + (right - left) / 2;

	if (target == list[middle]) return middle;

	if (target < list[middle]) return search(list, target, left, middle - 1);

	if (target > list[middle]) return search(list, target, middle + 1, right);
}

int BinarySearch::searchIterative(const std::vector<int> list, int target)
{
	int left = 0;
	int right = list.size() - 1;

	while (left <= right) {
		int middle = left + (right - left) / 2;

		if (target == list[middle]) return middle;
		
		if (target < list[middle]) right = middle - 1;

		if (target > list[middle]) left = middle + 1;
	}

	return -1;
}
