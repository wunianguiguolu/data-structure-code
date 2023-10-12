#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include "../include/SequenceList.hpp"

// test for init
TEST_CASE("SequenceList Test 1") {
	SequenceList<int> arr;
	// None

	REQUIRE( arr.length() == 0 );

};

// test for function (insert length search)
TEST_CASE("SequenceList Test 2") {
	int initSize = 5;
	SequenceList<int> arr(initSize);
	arr.insert(0, 1);
	arr.insert(1, 2);
	arr.insert(2, 3);
	arr.insert(3, 4);
	arr.insert(4, 5);
	// 1 2 3 4 5

	REQUIRE( arr.length() == 5 );
	REQUIRE( arr.search(1) == 0 );
	REQUIRE( arr.search(3) == 2 );
};

// test for function (clear)
TEST_CASE("SequenceList Test 3") {
	int initSize = 15;
	SequenceList<int> arr(initSize);
	arr.insert(0, 3);
	arr.insert(1, 6);
	arr.insert(2, 8);
	arr.insert(3, 1);
	arr.insert(4, 5);
	arr.insert(5, 10);
	// 3 6 8 1 5 10

	REQUIRE( arr.length() == 6 );
	REQUIRE( arr.search(1) == 3 );
	REQUIRE( arr.search(5) == 4 );
	
	arr.clear();
	// None

	REQUIRE( arr.length() == 0);
};

// test for function (remove)
TEST_CASE("SequenceList Test 4") {
	int initSize = 15;
	SequenceList<int> arr(initSize);
	arr.insert(0, 3);
	arr.insert(1, 6);
	arr.insert(2, 8);
	arr.insert(3, 5);
	arr.insert(4, 10);
	// 3 6 8 5 10

	REQUIRE( arr.length() == 5 );
	REQUIRE( arr.search(3) == 0 );
	REQUIRE( arr.search(5) == 3 );
	
	arr.remove(2); 
	// 3 6 5 10

	REQUIRE( arr.length() == 4 );
	REQUIRE( arr.search(3) == 0 );
	REQUIRE( arr.search(5) == 2 );
};

// test for function (visit)
TEST_CASE("SequenceList Test 5") {
	int initSize = 15;
	SequenceList<int> arr(initSize);
	arr.insert(0, 5);
	arr.insert(1, 3);
	arr.insert(2, 15);
	arr.insert(3, 2);
	arr.insert(4, 10);
	// 5 3 15 2 10

	REQUIRE( arr.length() == 5 );
	REQUIRE( arr.search(3) == 1 );
	REQUIRE( arr.search(2) == 3 );
	REQUIRE( arr.visit(4) == 10 );
};