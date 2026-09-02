#pragma once
class TreeNode
{
public:
	TreeNode* Left;
	TreeNode* Right;
	int Value;

public:
	TreeNode() = default;
	TreeNode(int value) : Value(value), Left(nullptr), Right(nullptr) {};
	TreeNode(int value, TreeNode* left, TreeNode* right) : Value(value), Left(left), Right(right) {};

	void inOrder();
	void preOrder();
	void postOrder();

	TreeNode* insertBST(TreeNode* node, int val);

	inline bool hasLeft() const { return Left != nullptr; };
	inline bool hasRight() const { return Right != nullptr; };
};

