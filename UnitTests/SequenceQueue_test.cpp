#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include "../include/SequenceQueue.hpp"

// test for init isEmpty
TEST_CASE("SequenceQueue Test 1") {
	SequenceQueue<int> queue;
	// None

	REQUIRE( queue.isEmpty() == 1 );
};

// test for enQueue getHead
TEST_CASE("SequenceQueue Test 2") {
	SequenceQueue<int> queue;
    queue.enQueue(1);
    queue.enQueue(2);
    // rear 2 1 front

	REQUIRE( queue.getHead() == 1 );
};

// test for deQueue
TEST_CASE("SequenceQueue Test 3") {
	SequenceQueue<int> queue;
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

// test for DoubleSpace
TEST_CASE("SequenceQueue Test 4") {
	SequenceQueue<int> queue(3);
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    queue.enQueue(5);
    // rear 5 4 3 2 1 front

	REQUIRE( queue.getHead() == 1 );

    REQUIRE( queue.deQueue() == 1 );
    REQUIRE( queue.deQueue() == 2 );
    REQUIRE( queue.deQueue() == 3 );
    REQUIRE( queue.deQueue() == 4 );
    // rear 5 front
    REQUIRE( queue.getHead() == 5 );
};