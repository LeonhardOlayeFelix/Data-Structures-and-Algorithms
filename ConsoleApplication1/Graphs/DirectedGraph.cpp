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
	std::vector<bool> beingVisited(m_AdjacencyList.size(), false);
	std::vector<bool> fullyVisited(m_AdjacencyList.size(), false);

	for (int i = 0; i < m_AdjacencyList.size(); i++) {
		if (fullyVisited[i]) continue;

		else if (containsCycle(i, beingVisited, fullyVisited))
			return true;
	}

	return false;
}

void DirectedGraph::TopologicalSort()
{}

bool DirectedGraph::containsCycle(int node, std::vector<bool>&beingVisited, std::vector<bool>&fullyVisited)
{

	beingVisited[node] = true;

	for (int neighbor : m_AdjacencyList[node]) {
		if (beingVisited[neighbor]) {
			return true;
		}
		else if (!fullyVisited[neighbor] && containsCycle(neighbor, beingVisited, fullyVisited)) {
			return true;
		}
	}

	beingVisited[node] = false;
	fullyVisited[node] = true;

	return false;
}
