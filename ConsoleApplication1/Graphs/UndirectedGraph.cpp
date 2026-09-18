#include "UndirectedGraph.h"
#include <unordered_set>
#include <queue>
#include <iostream>
#include <stack>

UndirectedGraph::UndirectedGraph(size_t size, const std::vector<std::pair<int, int>>& connections) : TraversableGraph(size)
{
	m_AdjacencyList.resize(size);
	for (const std::pair<int, int>& connection : connections)
		AddEdge(connection);
}

void UndirectedGraph::AddEdge(const std::pair<int, int>& edge)
{
	m_AdjacencyList[edge.first].push_back(edge.second);
	m_AdjacencyList[edge.second].push_back(edge.first);
}
