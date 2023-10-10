#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include "../SequenceStack.hpp"

// test for init isEpmty
TEST_CASE("SequenceStack VTest 1") {
	SequenceStack<int> stack;
	// None

	REQUIRE( stack.isEpmty() == 1 );
};

// test for push top
TEST_CASE("SequenceStack Test 2") {
	SequenceStack<int> stack;
    stack.push(1);
    stack.push(2);
    // Top
    // 2
    // 1
    // Bottom

	REQUIRE( stack.top() == 2 );
};

// test for pop
TEST_CASE("SequenceStack Test 3") {
	SequenceStack<int> stack;
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

// test for DoubleSpace
TEST_CASE("SequenceStack Test 4") {
	SequenceStack<int> stack(3);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    // Top
    // 5
    // 4
    // 3
    // 2
    // 1
    // Bottom

	REQUIRE( stack.top() == 5 );
};