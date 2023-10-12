#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include "../include/LinkStack.hpp"

// test for init isEmpty
TEST_CASE("LinkStack Test 1") {
	LinkStack<int> stack;
	// None

	REQUIRE( stack.isEmpty() == 1 );
};

// test for push top
TEST_CASE("LinkStack Test 2") {
	LinkStack<int> stack;
    stack.push(1);
    stack.push(2);
    // Top
    // 2
    // 1
    // Bottom

	REQUIRE( stack.top() == 2 );
};

// test for pop
TEST_CASE("LinkStack Test 3") {
	LinkStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    // Top
    // 3
    // 2
    // 1
    // Bottom

	REQUIRE( stack.top() == 3 );
    
    REQUIRE( stack.pop() == 3 );
    // Top
    // 2
    // 1
    // Bottom
    REQUIRE( stack.top() == 2 );
};

