#include "OrderedSet.h"

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


