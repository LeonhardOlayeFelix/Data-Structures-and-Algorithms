#include "TreeNode.h"
#include <iostream>
#include <queue>

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

void TreeNode::levelByLevel()
{
	std::queue<TreeNode*> q;

	q.push(this);

	std::cout << "{";

	while (!q.empty()) {
		int levelSize = q.size();

		std::cout << "{";
		for (int i = 0; i < levelSize; i++) {
			TreeNode* node = q.front();
			q.pop();

			std::cout << node->Value << ((i == levelSize - 1) ? "" : ", " );

			if (node->hasLeft()) q.push(node->Left);
			if (node->hasRight()) q.push(node->Right);
		}
		std::cout << "}" << (q.empty() ? "" : ", ");
	}
	std::cout << "}" << std::endl;

}

void TreeNode::UpdateHeight()
{
	int leftHeight = Left ? Left->m_Height : 0;
	int rightHeight = Right ? Right->m_Height : 0;

	m_Height = 1 + std::max(leftHeight, rightHeight);
}

int TreeNode::BalanceFactor()
{
	int leftHeight = Left ? Left->m_Height : 0;
	int rightHeight = Right ? Right->m_Height : 0;

	return leftHeight - rightHeight;
}

TreeNode* TreeNode::inOrderSuccessor()
{
	if (Right == nullptr) return nullptr;

	TreeNode* curr = Right;

	while (curr->Left != nullptr) {
		curr = curr->Left;
	}

	return curr;
}


