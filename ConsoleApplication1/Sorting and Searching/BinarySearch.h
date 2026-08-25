#pragma once
#include <vector>


class BinarySearch
{
public:
	BinarySearch() = delete;

	static int search(const std::vector<int>& list, int target);

private:
	static int search(const std::vector<int>& list, int target, int left, int right);
	static int searchIterative(const std::vector<int>& list, int target);
};

