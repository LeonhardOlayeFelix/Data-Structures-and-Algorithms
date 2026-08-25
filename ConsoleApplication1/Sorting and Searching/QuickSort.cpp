#include "QuickSort.h"

void QuickSort::sort(std::vector<int>& list)
{
	partition(list, 0, list.size() - 1);
}

void QuickSort::partition(std::vector<int>& list, int left, int right)
{
	if (list.empty()) return; //edge case

	if (left == right) return; //base case

	int boundary = left;

	for (int i = left; i < right; i++) {
		if (list[i] < list[right]) {
			int temp = list[boundary];
			list[boundary] = list[i];
			list[i] = temp;
			boundary++;
		}
	}

	int temp = list[boundary];
	list[boundary] = list[right];
	list[right] = temp;

	partition(list, left, std::max(left, boundary - 1));
	partition(list, std::min(right, boundary + 1), right);
}
