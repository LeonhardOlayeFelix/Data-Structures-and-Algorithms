#include "UndirectedGraph.h"
#include <unordered_set>
#include <queue>
#include <iostream>
#include <stack>


UndirectedGraph::UndirectedGraph(size_t size, const std::vector<std::pair<int, int>>& connections) : TraversableGraph(size)
{
	for (const std::pair<int, int>& connection : connections)
		AddEdge(connection);
}

void UndirectedGraph::AddEdge(const std::pair<int, int>& edge)
{
	m_AdjacencyList[edge.first].push_back(edge.second);
	m_AdjacencyList[edge.second].push_back(edge.first);
}

bool UndirectedGraph::ContainsCycle()
{
	std::unordered_set<int> visited;

	for (int i = 0; i < m_AdjacencyList.size(); i++) {

		if (visited.find(i) != visited.end()) continue;

		std::stack<std::pair<int, int>> s;
		s.push({ i, -1 });
		visited.insert(i);

		while (!s.empty()) {
			auto [current, parent] = s.top();
			s.pop();

			for (const int& neighbor : m_AdjacencyList[current])
			{
				if (visited.find(neighbor) != visited.end())
				{
					if (parent != neighbor)
						return true;
				}
				else
				{
					visited.insert(neighbor);
					s.push({ neighbor, current });
				}
			}
		}

	}

	

	return false;
}
