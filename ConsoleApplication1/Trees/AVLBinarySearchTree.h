#pragma once
#include "TreeNode.h"

class AVLBinarySearchTree
{
public:
	TreeNode* Root{ nullptr };

public:
	AVLBinarySearchTree() = default;
	AVLBinarySearchTree(TreeNode* root) : Root(root) {};

	void insert(int val);
	void remove(int val);

	inline int Height() const { return Root->Height(); };
	inline int BalanceFactor() const { return Root->BalanceFactor(); };

private:
	TreeNode* insertRecursive(TreeNode* node, int val);
	TreeNode* removeRecursive(TreeNode* node, int val);
	TreeNode* findRecursive(TreeNode* node, int val);
	TreeNode* performRotationIfNeeded(TreeNode* node);
	TreeNode* rotateLeft(TreeNode* node);
	TreeNode* rotateRight(TreeNode* node);
};

