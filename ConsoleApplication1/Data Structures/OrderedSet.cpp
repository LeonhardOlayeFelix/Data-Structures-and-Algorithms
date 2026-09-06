#include "OrderedSet.h"


int OrderedSet::Iterator::operator*()
{
	return (*m_TreeIterator)->Value;
}

OrderedSet::Iterator& OrderedSet::Iterator::operator++() {

	++m_TreeIterator;

	return *this;
}

bool OrderedSet::Iterator::operator!=(const Iterator& other)
{
	return m_TreeIterator != other.m_TreeIterator;
}

void OrderedSet::insert(int val)
{
	m_Tree.insert(val);
}
void OrderedSet::remove(int val)
{
	return m_Tree.remove(val);
}

bool OrderedSet::contains(int val)
{
	return m_Tree.find(val) != nullptr;
}

int OrderedSet::lowerBound(int val) {
	return m_Tree.lowerBound(val)->Value;
}
int OrderedSet::upperBound(int val) {
	return m_Tree.upperBound(val)->Value;
}

OrderedSet::Iterator OrderedSet::begin()
{
	return Iterator(m_Tree.begin());
}

OrderedSet::Iterator OrderedSet::end()
{
	return Iterator(m_Tree.end());
}


