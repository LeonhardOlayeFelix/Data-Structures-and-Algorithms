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


int main() {

	TreeNode* one = new TreeNode(1);
	TreeNode* three = new TreeNode(3);
	TreeNode* two = new TreeNode(2, one, three);

	TreeNode* five = new TreeNode(5);
	TreeNode* seven = new TreeNode(7);
	TreeNode* six = new TreeNode(6, five, seven);

	TreeNode* four = new TreeNode(4, two, six);

	AVLBinarySearchTree tree;
	tree.insert(17);
	tree.insert(12);
	tree.insert(8);
	tree.insert(6);
	tree.insert(5);
	tree.insert(9);
	tree.insert(2);
	tree.insert(1);

	tree.remove(8);
	tree.remove(17);

	tree.Root->levelByLevel();

	std::cout << "Tree Height: " << tree.Height();

}
