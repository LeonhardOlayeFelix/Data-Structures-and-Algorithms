#pragma once
#include "TreeNode.h"
#include <stack>

class AVLBinarySearchTree
{
public:
	class Iterator {
	public:
		Iterator(TreeNode* root);

		TreeNode* operator*() const;
		Iterator& operator++();
		bool operator!=(const Iterator& other) const;
		bool operator==(const Iterator& other) const;

	private:
		std::stack<TreeNode*> m_Stack{};

		void pushLeftTree(TreeNode* node);
	};


public:
	TreeNode* Root{ nullptr };

public:
	AVLBinarySearchTree() = default;
	AVLBinarySearchTree(TreeNode* root) : Root(root) {};

	void insert(int val);
	void remove(int val);
	Iterator begin();
	Iterator end();
	TreeNode* find(int val);
	TreeNode* lowerBound(int val) const;
	TreeNode* upperBound(int val) const;

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

