#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <ctype.h>
#include <algorithm>
#include "Sorting and Searching/SortingIncludes.h"
#include "Linked Lists/LinkedListIncludes.h"
#include "Trees/TreeNode.h"
#include "Trees/AVLBinarySearchTree.h"
#include "Data Structures/OrderedSet.h"

int main() {

	OrderedSet set;
	set.insert(80);
	set.insert(50);
	set.insert(20);
	set.insert(9);
	set.insert(4);
	set.insert(60);
	set.insert(8);
	set.insert(7);
	set.insert(170);
	set.insert(6);
	set.insert(5);
	set.insert(10);
	set.insert(10);
	set.insert(3);
	set.insert(120);
	set.insert(2);
	set.insert(90);
	set.insert(1);

	for (auto elem : set) {
		std::cout << elem << ", ";
	}

	//set.Root->levelByLevel();

	std::cout << "\n" << set.upperBound(20);

}
