#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <ctype.h>
#include <algorithm>
#include "Sorting/MergeSort.h"


int main() {

	std::vector<int> v = { 0,5,7,8,6,3,4,2,1,9 };

	std::vector<int> sorted = MergeSort::sort(v);

	for (int value : sorted) {
		std::cout << value << ", ";
	}

}
