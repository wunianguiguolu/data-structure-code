#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include "../include/HfTree.hpp"

// test 1
TEST_CASE("HfTree Test 1") {
    //哈夫曼树
    char ch[] = {"aeistdn"};
    int w[] = {10,15,12,3,4,13,1};

    HfTree<char> Hftree(ch, w, 7);
    HfTree<char>::HfCode result[7];  //hfCode定义在hfTree中
    Hftree.getCode(result);

    REQUIRE( result[0].code == "000" );
    REQUIRE( result[1].code == "01" );
    REQUIRE( result[2].code == "11" );
    REQUIRE( result[3].code == "00110" );
    REQUIRE( result[4].code == "0010" );
    REQUIRE( result[5].code == "10" );
    REQUIRE( result[6].code == "00111" );
};