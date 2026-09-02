#include "TreeNode.h"
#include <iostream>


void TreeNode::inOrder()
{
	if (Left != nullptr)
		Left->inOrder();

	std::cout << Value << ", ";

	if (Right != nullptr)
		Right->inOrder();
}

void TreeNode::preOrder()
{
	std::cout << Value << ", ";

	if (Left != nullptr)
		Left->preOrder();

	if (Right != nullptr)
		Right->preOrder();
}

void TreeNode::postOrder()
{
	if (Left != nullptr)
		Left->postOrder();

	if (Right != nullptr)
		Right->postOrder();

	std::cout << Value << ", ";
}

TreeNode* TreeNode::insertBST(TreeNode* node, int val)
{
	if (node == nullptr) return new TreeNode(val);

	if (val < node->Value)
		node->Left = insertBST(node->Left, val);

	if (val > node->Value)
		node->Right = insertBST(node->Right, val);

	return node;
}
