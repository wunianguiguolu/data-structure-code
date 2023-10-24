#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <iostream>
#include "../include/InToSufForm.hpp"

// test for InToSufForm
TEST_CASE("InToSufForm Test 1") {
	const char *instr = "1+2"; 
	char *sufstr = (char*)malloc(strlen(instr));  // Allocate memory for sufstr
	InToSufForm(instr, sufstr);
	REQUIRE( std::strcmp(sufstr, "12+") == 0 );
	free(sufstr);
};

// test for InToSufForm
TEST_CASE("InToSufForm Test 2") {
	const char *instr = "5*(7-2*3)+8/2"; 
	char *sufstr = (char*)malloc(strlen(instr));  // Allocate memory for sufstr
	InToSufForm(instr, sufstr);
	REQUIRE( std::strcmp(sufstr, "5723*-*82/+") == 0 );
	free(sufstr);
};



