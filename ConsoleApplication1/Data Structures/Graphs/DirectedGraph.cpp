#include "DirectedGraph.h"
#include <stack>
#include <iostream>

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
{

	std::vector<int> result;
	result.reserve(m_AdjacencyList.size());

	std::vector<int> inDegrees(m_AdjacencyList.size(), 0);

	for (int u = 0; u < m_AdjacencyList.size(); u++) {
		for (int v : m_AdjacencyList[u])
			inDegrees[v]++;
	}

	std::stack<int> s;

	for (int i = 0; i < inDegrees.size(); i++) {
		if (inDegrees[i] == 0)
			s.push(i);
	}

	while (!s.empty()) {
		int current = s.top();
		s.pop();

		result.push_back(current);

		for (int neighbor : m_AdjacencyList[current]) {
			inDegrees[neighbor]--;
			if (inDegrees[neighbor] == 0)
				s.push(neighbor);
		}
	}

	if (result.size() != m_AdjacencyList.size())
	{
		std::cout << "Cycle detected";
		return;
	}

	std::cout << "{";
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i];
		if (i != result.size() - 1) std::cout << ", ";
	}
	std::cout << "}";

}

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
