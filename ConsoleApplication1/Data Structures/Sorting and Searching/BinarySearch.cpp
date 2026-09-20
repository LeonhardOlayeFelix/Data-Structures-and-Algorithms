#include "BinarySearch.h"

int BinarySearch::search(const std::vector<int>& list, int target)
{
	return searchIterative(list, target);
}

int BinarySearch::search(const std::vector<int>& list, int target, int left, int right) {

	if (left > right) return -1;

	int middle = left + (right - left) / 2;

	if (target == list[middle]) return middle;

	else if (target < list[middle]) return search(list, target, left, middle - 1);

	else if (target > list[middle]) return search(list, target, middle + 1, right);
}

int BinarySearch::searchIterative(const std::vector<int>& list, int target) {

	int left = 0;
	int right = list.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (target == list[mid]) return mid;
		else if (target < list[mid]) right = mid - 1;
		else if (target > list[mid]) left = mid + 1;
	}

	return -1;
}


