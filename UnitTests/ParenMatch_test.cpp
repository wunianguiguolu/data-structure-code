#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include "../ParenMatch.hpp"

// test for ParenMatch
TEST_CASE("ParenMatch Test 1") {
	const char *str = "( 1 + 2 )"; 

	REQUIRE( parenMatch(str) == true );
};

// test for ')' expected problem
TEST_CASE("ParenMatch Test 2") {
	const char *str = "( 3 + (4 )"; 

	REQUIRE( parenMatch(str) == false );
};

// test for '(' expected problem
TEST_CASE("ParenMatch Test 3") {
	const char *str = "( 5 + )6 )"; 

	REQUIRE( parenMatch(str) == false );
};
