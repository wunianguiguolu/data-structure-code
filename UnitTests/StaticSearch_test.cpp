#include <catch2/catch_test_macros.hpp>

#include<iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "../include/StaticSearch.hpp"

using namespace std;

// test for seqSearch_unordered
TEST_CASE("seqSearch_unordered Test 1") {
	
    srand(time(NULL));
    //无序表
    SET<int, char> s[11];  //牺牲0位作为哨兵
    int *k = new int[11];
    for (int i = 1; i <= 10; i++) {
        k[i] = i;
    }
    random_shuffle(k + 1, k + 11);  //对1~10进行随机排序
    for (int i = 1; i <= 10; i++){
        s[i].key = k[i];
        char c = '0';
        c += i - 1;
        s[i].other= c;
    }
    
    REQUIRE( seqSearch_unordered<int, char>(s, 10, s[2].key) == 2 );
    REQUIRE( seqSearch_unordered<int, char>(s, 10, s[5].key) == 5 );
    REQUIRE( seqSearch_unordered<int, char>(s, 10, s[8].key) == 8 );
    REQUIRE( seqSearch_unordered<int, char>(s, 10, 100) == 0 );
};

// test for seqSearch_ordered
TEST_CASE("seqSearch_ordered Test 2") {
	
    //有序表
    SET<int, char> ss[11];  //牺牲0位作为哨兵
    for (int i = 1; i <= 10; i++){
        ss[i].key = i;
        char c = '0';
        c += i - 1;
        ss[i].other= c;
    }
    
    REQUIRE( seqSearch_ordered<int, char>(ss, 10, 8) == 8 );
    REQUIRE( seqSearch_ordered<int, char>(ss, 10, 11) == 0 );
};

// test for binarySearch
TEST_CASE("binarySearch Test 3") {
	
    //有序表
    SET<int, char> ss[11];  //牺牲0位作为哨兵
    for (int i = 1; i <= 10; i++){
        ss[i].key = i;
        char c = '0';
        c += i - 1;
        ss[i].other= c;
    }
    
    REQUIRE( binarySearch<int, char>(ss, 10, 8) == 8 );
    REQUIRE( binarySearch<int, char>(ss, 10, 11) == 0 );
};