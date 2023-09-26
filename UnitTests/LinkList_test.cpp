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
	
};

// test for function (remove)
TEST_CASE("LinkList Test 4") {
	
};

// test for function (visit)
TEST_CASE("LinkList Test 5") {
	
};