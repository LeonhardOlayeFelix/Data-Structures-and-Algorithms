#include "TraversableGraph.h"
#include <queue>
#include <stack>
#include <iostream>


void TraversableGraph::Bfs(int start)
{
	std::vector<bool> visited(m_AdjacencyList.size(), false);
	visited[start] = true;

	std::queue<int> q;
	q.push(start);

	std::cout << '{';

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		std::cout << current;

		for (const int& neighbor : m_AdjacencyList[current]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}

		if (!q.empty()) std::cout << ", ";
	}

	std::cout << '}' << std::endl;
}

void TraversableGraph::Dfs(int start)
{

	std::vector<bool> visited(m_AdjacencyList.size(), false);
	visited[start] = true;

	std::stack<int> s;
	s.push(start);

	std::cout << '{';

	while (!s.empty()) {
		int current = s.top();
		s.pop();

		std::cout << current;

		for (const int& neighbor : m_AdjacencyList[current]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				s.push(neighbor);
			}
		}

		if (!s.empty()) std::cout << ", ";
	}

	std::cout << '}' << std::endl;

}

void TraversableGraph::DfsRecursive(int start)
{
	std::vector<bool> visited(m_AdjacencyList.size());

	std::cout << '{';
	dfsHelper(start, visited);
	std::cout << '}' << std::endl;

}

void TraversableGraph::dfsHelper(int node, std::vector<bool>& visited)
{
	std::cout << node << ", ";

	visited[node] = true;

	for (const int& neighbor : m_AdjacencyList[node])
		if (!visited[neighbor])
			dfsHelper(neighbor, visited);
}
