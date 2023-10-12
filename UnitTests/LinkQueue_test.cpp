#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include "../include/LinkQueue.hpp"

// test for init isEmpty
TEST_CASE("LinkQueue Test 1") {
	LinkQueue<int> queue;
	// None

	REQUIRE( queue.isEmpty() == 1 );
};

// test for enQueue getHead
TEST_CASE("LinkQueue Test 2") {
	LinkQueue<int> queue;
    queue.enQueue(1);
    queue.enQueue(2);
    // rear 2 1 front

	REQUIRE( queue.getHead() == 1 );
};

// test for deQueue
TEST_CASE("LinkQueue Test 3") {
	LinkQueue<int> queue;
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    // rear 3 2 1front
	REQUIRE( queue.getHead() == 1 );
    
    REQUIRE( queue.deQueue() == 1 );
    // rear 3 2 front
    REQUIRE( queue.getHead() == 2 );

    REQUIRE( queue.deQueue() == 2 );
    // rear 3 front
    REQUIRE( queue.getHead() == 3 );
};