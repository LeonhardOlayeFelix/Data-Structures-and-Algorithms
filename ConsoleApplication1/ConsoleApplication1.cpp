#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <ctype.h>
#include <algorithm>
#include "Linked Lists/SinglyLinkedList.h"


int main() {

	std::vector<int> v = { 0,5,7,8,6,6,3,4,2,1,9, 10 };

	SinglyLinkedList list;
	list.append(4);
	list.append(5);
	list.append(6);
	list.insert(7, 5);

	const Node1* current = list.Head();

	while (current != nullptr) {
		std::cout << current->Data();
		current = current->Next;
	}
}
