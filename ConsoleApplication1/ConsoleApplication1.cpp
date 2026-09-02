#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <ctype.h>
#include <algorithm>
#include "Linked Lists/LinkedListIncludes.h"
#include "Trees/TreeNode.h"
#include "Trees/BinarySearchTree.h"

int main() {

	TreeNode* one = new TreeNode(1);
	TreeNode* three = new TreeNode(3);
	TreeNode* two = new TreeNode(2, one, three);

	TreeNode* five = new TreeNode(5);
	TreeNode* seven = new TreeNode(7);
	TreeNode* six = new TreeNode(6, five, seven);

	TreeNode* four = new TreeNode(4, two, six);

	BinarySearchTree tree;
	tree.insert(8);
	tree.insert(12);
	tree.insert(3);
	tree.insert(17);
	tree.insert(6);
	tree.insert(5);

	tree.Root->inOrder();

}
