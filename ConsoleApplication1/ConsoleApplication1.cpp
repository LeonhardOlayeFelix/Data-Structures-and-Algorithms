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

	AVLBinarySearchTree tree;
	tree.insert(170);
	tree.insert(120);
	tree.insert(80);
	tree.insert(60);
	tree.insert(50);
	tree.insert(90);
	tree.insert(20);
	tree.insert(10);
	tree.insert(9);
	tree.insert(8);
	tree.insert(7);
	tree.insert(6);
	tree.insert(5);
	tree.insert(4);
	tree.insert(3);
	tree.insert(2);
	tree.insert(1);

	//tree.Root->inOrder();

	for (auto node : tree) {
		std::cout << node->Value << ", ";
	}


}
