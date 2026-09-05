#pragma once
class TreeNode
{
private:
	int m_Height{ 0 };
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
	void levelByLevel();
	void UpdateHeight();
	int BalanceFactor();

	TreeNode* inOrderSuccessor();

	inline bool hasLeft() const { return Left != nullptr; };
	inline bool hasRight() const { return Right != nullptr; };
	inline bool hasChildren() const { return hasLeft() || hasRight(); };
	inline int Height() const { return m_Height; };
};

