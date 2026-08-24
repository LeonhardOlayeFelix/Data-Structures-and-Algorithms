#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <ctype.h>
#include <algorithm>
#include "Sorting/QuickSort.h"


int main() {

	std::vector<int> v = { 0,5,7,8,6,3,4,2,1,9, 10 };

	QuickSort::sort(v);

	for (int value : v) {
		std::cout << value << ", ";
	}

}
