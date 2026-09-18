#pragma once
#include "TraversableGraph.h"
#include <utility>
#include <vector>
#include <unordered_set>

class UndirectedGraph : public TraversableGraph
{
public:
	UndirectedGraph(size_t size, const std::vector<std::pair<int, int>>& connections);

	void AddEdge(const std::pair<int, int>& edge) override;
	bool ContainsCycle() override;

};

