#pragma once
#include "../Trees/AVLBinarySearchTree.h"

class OrderedSet
{

public:
	class Iterator {
	public:
		Iterator(AVLBinarySearchTree::Iterator it) : m_TreeIterator(it) {};

		int operator*();
		Iterator& operator++();
		bool operator!=(const Iterator& other);

	private:
		AVLBinarySearchTree::Iterator m_TreeIterator;
	};

private:
	AVLBinarySearchTree m_Tree{};

public:
	OrderedSet() = default;

	void insert(int val);
	void remove(int val);
	bool contains(int val);
	Iterator begin();
	Iterator end();


	inline bool empty() { return m_Tree.Root == nullptr; }

};

