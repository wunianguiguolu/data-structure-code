#include <iostream>

#include "List.hpp"
#include "SequenceList.hpp"
#include "LinkList.hpp"



int main(int argc, char* argv[])
{
	std::cout << "Now let us find sth interesting!" << std::endl;
	int initSize = 20;
	SequenceList<int> arr(initSize);

	arr.insert(0, 1);
	arr.insert(1, 2);

	std::cout << "The length of arr is " << arr.length() << " !" << std::endl;
	std::cout << "The element 1 is " << arr.search(1) << "th element in the arr !" << std::endl;

	LinkList<int> arr2;

	arr2.insert(0, 1);
	// 1

	arr2.clear();

	LinkList<int> arr3;

	arr3.insert(0, 3);
	arr3.insert(1, 2);
	arr3.insert(2, 5);
	arr3.insert(3, 4);
	arr3.insert(4, 7);
	//3 2 5 4 7
	std::cout << "right answer: 3 2 5 4 7." << std::endl;
	
	arr3.traverse();
}

