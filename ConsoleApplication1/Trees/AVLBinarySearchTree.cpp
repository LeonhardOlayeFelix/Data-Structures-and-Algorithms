#include "AVLBinarySearchTree.h"
#include "../debug.h"
#include <iostream>

void AVLBinarySearchTree::insert(int val)
{
	Root = insertRecursive(Root, val);
}

void AVLBinarySearchTree::remove(int val)
{
	Root = removeRecursive(Root, val);
}

TreeNode* AVLBinarySearchTree::insertRecursive(TreeNode * node, int val)
{
	if (node == nullptr) 
	{
		TreeNode* newNode = new TreeNode(val);
		newNode->UpdateHeight();
		return newNode;
	} 

	if (val < node->Value)
		node->Left = insertRecursive(node->Left, val);
	else if (val > node->Value)
		node->Right = insertRecursive(node->Right, val);
	else
		return node;

	node->UpdateHeight();

	node = performRotationIfNeeded(node);

	return node;
}

TreeNode* AVLBinarySearchTree::removeRecursive(TreeNode* node, int val)
{
	if (node == nullptr) return nullptr;

	if (val < node->Value) {
		node->Left = removeRecursive(node->Left, val);
	}
	else if (val > node->Value) {
		node->Right = removeRecursive(node->Right, val);
	}
	else {

		//case1: no children
		if (!node->hasChildren()) return nullptr;

		//case2: one left child
		if (node->hasLeft() && !node->hasRight()) {
			TreeNode* temp = node->Left;
			delete node;
			return temp;
		}

		//case3: one right child
		if (node->hasRight() && !node->hasLeft()) {
			TreeNode* temp = node->Right;
			delete node;
			return temp;
		}

		//case4: two children
		TreeNode* inOrderSuccessor = node->inOrderSuccessor();
		node->Value = inOrderSuccessor->Value;
		node->Right = removeRecursive(node->Right, inOrderSuccessor->Value);
	}

	node->UpdateHeight();

	node = performRotationIfNeeded(node);

	return node;

}

TreeNode* AVLBinarySearchTree::findRecursive(TreeNode* node, int val)
{
	if (node == nullptr) return nullptr;

	if (node->Value == val) return node;

	if (val < node->Value) return findRecursive(node->Left, val);

	if (val > node->Value) return findRecursive(node->Right, val);

	return nullptr;
}

TreeNode* AVLBinarySearchTree::performRotationIfNeeded(TreeNode* node)
{
	int bf = node->BalanceFactor();

	//Left heavy
	if (bf > 1) {
		if (node->Left->BalanceFactor() < 0) //Left-Right rotation needed?
			node->Left = rotateLeft(node->Left);
		node = rotateRight(node);
	}
	//Right heavy
	else if (bf < -1) {
		if (node->Right->BalanceFactor() > 0) //Right-Left rotation needed?
			node->Right = rotateRight(node->Right);
		node = rotateLeft(node);
	}

	return node;
}

TreeNode* AVLBinarySearchTree::rotateLeft(TreeNode* node)
{
	#ifdef DEBUG
	std::cout << "Rotate Left on node: " << node->Value << std::endl;
	#endif

	TreeNode* newRoot = node->Right;
	TreeNode* orphan = newRoot->Left;

	newRoot->Left = node;
	node->Right = orphan;

	node->UpdateHeight();
	newRoot->UpdateHeight();

	return newRoot;
}

TreeNode* AVLBinarySearchTree::rotateRight(TreeNode* node)
{

	#ifdef DEBUG
	std::cout << "Rotate right on node: " << node->Value << std::endl;
	#endif

	TreeNode* newRoot = node->Left;
	TreeNode* orphan = newRoot->Right;

	newRoot->Right = node;
	node->Left = orphan;

	node->UpdateHeight();
	newRoot->UpdateHeight();

	return newRoot;
}
