#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <ctype.h>
#include <algorithm>
#include "Sorting/BubbleSort.h"


int main() {

	std::vector<int> v = { 0,5,7,8,6,3,4,2,1,9, 10 };

	BubbleSort::sort(v);

	for (int value : v) {
		std::cout << value << ", ";
	}

}
