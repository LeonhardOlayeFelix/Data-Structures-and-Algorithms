#pragma once
#include "../Trees/AVLBinarySearchTree.h"

class OrderedSet
{
private:
	AVLBinarySearchTree m_Tree;
	int m_Size{};
public:
	OrderedSet() = default;

	void insert(int val);
	void remove(int val);
	bool contains(int val);


};

