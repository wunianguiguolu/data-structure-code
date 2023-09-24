#include <iostream>

#include "List.hpp"
#include "SequenceList.hpp"



int main(int argc, char* argv[])
{
	std::cout << "Now let us find sth interesting!" << std::endl;
	int initSize = 20;
	SequenceList<int> arr(initSize);

	arr.insert(0, 1);
	arr.insert(1, 2);

	std::cout << "The length of arr is " << arr.length() << " !" << std::endl;
	std::cout << "The element 1 is " << arr.search(1) << "th element in the arr !" << std::endl;


}

