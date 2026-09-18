#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(size_t size, const std::vector<std::pair<int, int>>& connections) : TraversableGraph(size)
{
	for (const std::pair<int, int>& connection : connections)
		AddEdge(connection);
}

void DirectedGraph::AddEdge(const std::pair<int, int>& edge)
{
	m_AdjacencyList[edge.first].push_back(edge.second);
}

bool DirectedGraph::ContainsCycle()
{
	return false;
}

void DirectedGraph::TopologicalSort()
{}
