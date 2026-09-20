#pragma once
#include "Graph.h"
#include <unordered_set>
#include <queue>

class TraversableGraph : public Graph
{
	class BFSIterator {
	public:
		BFSIterator(int node, const std::vector<std::vector<int>>& adj);
		BFSIterator();
		BFSIterator& operator++();
		int operator*();
		bool operator!=(const BFSIterator& other);
		bool operator==(const BFSIterator& other);

	private:
		std::queue<int> m_Queue;
		std::vector<bool> m_Visited;
		std::vector<std::vector<int>> m_Adj;

		void pushNeighbors(int node);

	};

public:
	TraversableGraph(size_t size) : Graph(size) {};

	void Bfs(int start) override;
	void Dfs(int start) override;
	void DfsRecursive(int start) override;
	BFSIterator begin();
	BFSIterator end();
private:
	void dfsHelper(int node, std::vector<bool>& visited);
};

