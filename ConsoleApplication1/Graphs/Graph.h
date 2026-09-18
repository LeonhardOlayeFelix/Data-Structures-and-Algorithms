#pragma once
#include <vector>

class Graph
{
protected:
	std::vector<std::vector<int>> m_AdjacencyList{};

public:
	Graph(size_t size) { m_AdjacencyList.resize(size); };
	virtual void AddEdge(const std::pair<int, int>& edge) = 0;
	virtual bool ContainsCycle() = 0;

	virtual void Bfs(int start) = 0;
	virtual void Dfs(int start) = 0;
	virtual void DfsRecursive(int start) = 0;

};

