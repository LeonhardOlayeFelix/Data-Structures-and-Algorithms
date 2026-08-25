#include "BubbleSort.h"

void BubbleSort::sort(std::vector<int>& list)
{
	bool changed = true;

	while (changed) {
		changed = false;
		for (int i = 0; i < list.size() - 1; i++) {
			if (list[i] > list[i + 1]) {
				int temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				changed = true;
			}
		}
	}
}
