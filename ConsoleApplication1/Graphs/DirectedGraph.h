#pragma once
#include "TraversableGraph.h"
#include <utility>

class DirectedGraph : public TraversableGraph
{

public:
	DirectedGraph(size_t size, const std::vector<std::pair<int, int>>& connections);

	void AddEdge(const std::pair<int, int>& edge) override;
};

