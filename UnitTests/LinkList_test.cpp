#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include "../LinkList.hpp"

// test for function (init length)
TEST_CASE("LinkList Test 1") {
	LinkList<int> arr;

	REQUIRE( arr.length() == 0 );
};

// test for function (insert length search)
TEST_CASE("LinkList Test 2") {
	LinkList<int> arr;

	REQUIRE( arr.length() == 0 );

	arr.insert(0, 1);
	// 1

	REQUIRE( arr.length() == 1 );
	REQUIRE( arr.search(1) == 0 );
	REQUIRE( arr.search(2) == -1 );

	arr.insert(1, 3);
	arr.insert(2, 2);
	//1 3 2

	REQUIRE( arr.length() == 3 );
	REQUIRE( arr.search(2) == 2 );
};

// test for function (clear)
TEST_CASE("LinkList Test 3") {
	LinkList<int> arr;

	REQUIRE( arr.length() == 0 );

	arr.insert(0, 1);
	// 1

	REQUIRE( arr.length() == 1 );

	arr.clear();

	REQUIRE( arr.length() == 0 );

	arr.insert(0, 3);
	arr.insert(1, 2);
	arr.insert(2, 5);
	arr.insert(3, 4);
	//3 2 5 4

	REQUIRE( arr.length() == 4 );

	arr.clear();

	REQUIRE( arr.length() == 0 );
};

// test for function (remove)
TEST_CASE("LinkList Test 4") {
	LinkList<int> arr;

	REQUIRE( arr.length() == 0 );

	arr.insert(0, 1);
	// 1

	REQUIRE( arr.length() == 1 );

	arr.remove(0);

	REQUIRE( arr.length() == 0 );

	arr.insert(0, 3);
	arr.insert(1, 2);
	arr.insert(2, 5);
	arr.insert(3, 4);
	//3 2 5 4

	REQUIRE( arr.length() == 4 );
	REQUIRE( arr.search(4) == 3 );
	
	arr.remove(1);

	REQUIRE( arr.length() == 3 );
	REQUIRE( arr.search(4) == 2 );
};

// test for function (reverse)
TEST_CASE("LinkList Test 5") {
	LinkList<int> arr;

	arr.insert(0, 3);
	arr.insert(1, 2);
	arr.insert(2, 5);
	arr.insert(3, 4);
	arr.insert(4, 7);
	//3 2 5 4 7

	REQUIRE( arr.length() == 5 );
	REQUIRE( arr.search(2) == 1 );
	REQUIRE( arr.search(7) == 4 );
	
	arr.reverse();
	//7 4 5 2 3

	REQUIRE( arr.length() == 5 );
	REQUIRE( arr.search(2) == 3 );
	REQUIRE( arr.search(7) == 0 );
	
};

// test for function (traverse)
TEST_CASE("LinkList Test 6") {
	LinkList<int> arr;

	arr.insert(0, 3);
	arr.insert(1, 2);
	arr.insert(2, 5);
	arr.insert(3, 4);
	arr.insert(4, 7);
	//3 2 5 4 7
	std::cout << "right answer: 3 2 5 4 7." << std::endl;
	
	arr.traverse();

	arr.clear();
	std::cout << "right answer: There's nothing in the array!." << std::endl;
	arr.traverse();
};

// test for function (visit)
TEST_CASE("LinkList Test 7") {
	LinkList<int> arr;

	arr.insert(0, 3);
	arr.insert(1, 2);
	arr.insert(2, 5);
	arr.insert(3, 4);
	arr.insert(4, 7);
	//3 2 5 4 7

	REQUIRE( arr.length() == 5 );
	REQUIRE( arr.visit(1) == 2 );
	REQUIRE( arr.visit(3) == 4 );
	
};

// test for function (quick insert)
TEST_CASE("LinkList Test 8") {
	LinkList<int> arr;
	int a[5] = {3, 2, 5, 4, 7};
	arr.insert(a, 5);
	//7 4 5 2 3

	REQUIRE( arr.length() == 5 );
	REQUIRE( arr.visit(1) == 4 );
	REQUIRE( arr.visit(3) == 2 );
	
};