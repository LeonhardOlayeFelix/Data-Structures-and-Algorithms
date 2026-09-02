#include "BinarySearchTree.h"
#include "BinarySearchTree.h"

void BinarySearchTree::insert(int val)
{
	Root = insertHelper(Root, val);
}

TreeNode* BinarySearchTree::insertHelper(TreeNode * node, int val)
{
	if (node == nullptr) return new TreeNode(val);

	if (val < node->Value)
		node->Left = insertHelper(node->Left, val);

	if (val > node->Value)
		node->Right = insertHelper(node->Right, val);

	return node;
}
