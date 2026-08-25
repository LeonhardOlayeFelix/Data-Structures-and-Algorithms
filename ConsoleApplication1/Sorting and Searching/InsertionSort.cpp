#include "InsertionSort.h"

void InsertionSort::sort(std::vector<int>& list)
{
	for (int i = 1; i < list.size(); i++) {
		int k = i;
		while (k > 0 && list[k - 1] > list[k]) {
			int temp = list[k - 1];
			list[k - 1] = list[k];
			list[k] = temp;
			k--;
		}
	}
}
