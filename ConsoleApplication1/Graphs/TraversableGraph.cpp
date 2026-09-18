#include "TraversableGraph.h"
#include <queue>
#include <stack>
#include <iostream>


void TraversableGraph::Bfs(int start)
{
	std::unordered_set<int> visited;
	visited.insert(start);

	std::queue<int> q;
	q.push(start);

	std::cout << '{';

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		std::cout << current;

		for (const int& neighbor : m_AdjacencyList[current]) {
			if (visited.find(neighbor) == visited.end()) {
				visited.insert(neighbor);
				q.push(neighbor);
			}
		}

		if (!q.empty()) std::cout << ", ";
	}

	std::cout << '}' << std::endl;
}

void TraversableGraph::Dfs(int start)
{
	std::stack<int> s;
	s.push(start);

	std::unordered_set<int> visited;
	visited.insert(start);

	std::cout << '{';

	while (!s.empty()) {
		int current = s.top();
		s.pop();

		std::cout << current;

		for (const int& neighbor : m_AdjacencyList[current]) {
			if (visited.find(neighbor) == visited.end()) {
				visited.insert(neighbor);
				s.push(neighbor);
			}
		}

		if (!s.empty()) std::cout << ", ";
	}

	std::cout << '}' << std::endl;

}

void TraversableGraph::DfsRecursive(int start)
{
	std::unordered_set<int> visited;

	std::cout << '{';
	dfsHelper(start, visited);
	std::cout << '}' << std::endl;

}

void TraversableGraph::dfsHelper(int node, std::unordered_set<int>& visited)
{
	std::cout << node << ", ";

	visited.insert(node);

	for (const int& neighbor : m_AdjacencyList[node])
		if (visited.find(neighbor) == visited.end())
			dfsHelper(neighbor, visited);
}
