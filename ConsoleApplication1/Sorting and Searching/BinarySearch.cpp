#include "BinarySearch.h"

int BinarySearch::search(const std::vector<int> list, int target)
{
    return search(list, target, 0, list.size() - 1);
}

int BinarySearch::search(const std::vector<int> list, int target, int left, int right)
{
    int middle = left + (right - left) / 2;

    if (target == list[middle]) return middle;

    if (left >= right) return -1;

    if (target > list[middle]) return search(list, target, middle + 1, right);

    if (target < list[middle]) return search(list, target, left, middle - 1);

    return 0;
}
