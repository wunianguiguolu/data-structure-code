#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include "../include/PriorityQueue.hpp"

// test for enQueue
TEST_CASE("PriorityQueue Test 1") {
	PriorityQueue<int> q;
	q.enQueue(2);
	q.enQueue(1);
	q.enQueue(3);
	q.enQueue(5);
	q.enQueue(4);
	q.enQueue(10);
	q.enQueue(23);
	q.enQueue(29);
	q.enQueue(60);
	q.enQueue(7);

	REQUIRE( q.getHead() == 1 );
	q.deQueue();
	REQUIRE( q.getHead() == 2 );
	q.deQueue();
	REQUIRE( q.getHead() == 3 );
	q.deQueue();
	REQUIRE( q.getHead() == 4 );
	q.deQueue();
	REQUIRE( q.getHead() == 5 );
	q.deQueue();
	REQUIRE( q.getHead() == 7 );
	q.deQueue();
	REQUIRE( q.getHead() == 10 );
	q.deQueue();
	REQUIRE( q.getHead() == 23 );
	q.deQueue();
	REQUIRE( q.getHead() == 29 );
	q.deQueue();
	REQUIRE( q.getHead() == 60 );
	q.deQueue();
	REQUIRE( q.isEmpty() == 1 );
};

// test for PriorityQueue
TEST_CASE("PriorityQueue Test 2") {
	
	const int items[10] = {2, 1, 3, 5, 4, 10, 23, 29, 60 ,7};
	PriorityQueue<int> q(items, 10);

	REQUIRE( q.getHead() == 1 );
	q.deQueue();
	REQUIRE( q.getHead() == 2 );
	q.deQueue();
	REQUIRE( q.getHead() == 3 );
	q.deQueue();
	REQUIRE( q.getHead() == 4 );
	q.deQueue();
	REQUIRE( q.getHead() == 5 );
	q.deQueue();
	REQUIRE( q.getHead() == 7 );
	q.deQueue();
	REQUIRE( q.getHead() == 10 );
	q.deQueue();
	REQUIRE( q.getHead() == 23 );
	q.deQueue();
	REQUIRE( q.getHead() == 29 );
	q.deQueue();
	REQUIRE( q.getHead() == 60 );
	q.deQueue();
	REQUIRE( q.isEmpty() == 1 );
};

