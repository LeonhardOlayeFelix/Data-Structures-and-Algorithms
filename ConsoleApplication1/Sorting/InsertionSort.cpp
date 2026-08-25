#include "InsertionSort.h"

void InsertionSort::sort(std::vector<int>& list)
{
	for (int i = 1; i < list.size(); i++) {
		int k = i;
		while (list[k] < list[k - 1] && k > 0) {
			int temp = list[k];
			list[k] = list[k - 1];
			list[k - 1] = temp;
			k--;
		}
	}
}
