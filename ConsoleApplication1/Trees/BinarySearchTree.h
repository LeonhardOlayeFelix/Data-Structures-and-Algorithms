#pragma once
#include "TreeNode.h"

class BinarySearchTree
{
public:
	TreeNode* Root{ nullptr };

public:
	BinarySearchTree() = default;
	BinarySearchTree(TreeNode* root) : Root(root) {};

	void insert(int val);

private:
	TreeNode* insertHelper(TreeNode* node, int val);
};

