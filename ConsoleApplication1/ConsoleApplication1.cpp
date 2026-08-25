#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <ctype.h>
#include <algorithm>
#include "Sorting and Searching/BinarySearch.h"
#include "Sorting and Searching/MergeSort.h"


int main() {

	std::vector<int> v = { 0,5,7,8,6,6,3,4,2,1,9, 10 };

	std::vector<int> p = MergeSort::sort(v);

	int res = BinarySearch::search(p, 40);


	for (const int& num : p) {
		std::cout << num << ", ";
	}

	std::cout << '\n' << res << std::endl;

}
