#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include "Sorting and Searching/SortingIncludes.h"
#include "Linked Lists/LinkedListIncludes.h"
#include "Trees/TreeNode.h"
#include "Trees/AVLBinarySearchTree.h"
#include "Data Structures/OrderedSet.h"
#include "Graphs/Includes.h"


int main() {

	int n = 10;

	std::vector<std::pair<int, int>> connections = 
	{	{0, 1}, {0, 2}, {0, 3},
		{1, 5}, 
		{2, 8}, 
		{3, 7}, {3, 8},
		{4, 5}, {4, 6},
		{5, 6}, 
		{6, 7}, {6, 9},
		{8, 9} 
	};

	DirectedGraph graph(10, connections);

	graph.Bfs(0);
	graph.Dfs(0);
	graph.DfsRecursive(0);
}
