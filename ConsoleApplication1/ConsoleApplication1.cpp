#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <ctype.h>
#include <algorithm>
#include "Linked Lists/SinglyLinkedList.h"
#include "Sorting and Searching/SortingIncludes.h"
#include "Sorting and Searching/BinarySearch.h"

int main() {

	SinglyLinkedList list;
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);

	list.reverse();

	std::cout << list.traverse();
}
