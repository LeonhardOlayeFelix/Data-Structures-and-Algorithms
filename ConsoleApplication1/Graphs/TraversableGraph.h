#pragma once
#include "Graph.h"
#include <unordered_set>

class TraversableGraph : public Graph
{
public:
	TraversableGraph(size_t size) : Graph(size) {};

	void Bfs(int start) override;
	void Dfs(int start) override;
	void DfsRecursive(int start) override;
private:
	void dfsHelper(int node, std::vector<bool>& visited);
};

