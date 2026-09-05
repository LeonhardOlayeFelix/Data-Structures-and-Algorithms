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

	TreeNode* one = new TreeNode(1);
	TreeNode* three = new TreeNode(3);
	TreeNode* two = new TreeNode(2, one, three);

	TreeNode* five = new TreeNode(5);
	TreeNode* seven = new TreeNode(7);
	TreeNode* six = new TreeNode(6, five, seven);

	TreeNode* four = new TreeNode(4, two, six);

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
	set.insert(3);
	set.insert(120);
	set.insert(2);
	set.insert(90);
	set.insert(1);

	for (auto elem : set) {
		std::cout << elem << ", ";
	}

}
