#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <sstream>
#include "../include/BTree.hpp"
#include "../include/SequenceQueue.hpp"

// test 1
TEST_CASE("BTree Test 1") {
    BTree<char> tree;
	std::istringstream input("1234567@@@@@@@@");
    std::streambuf* originalCin = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());
    tree.createTree('@');

    std::streambuf *originalCoutStream_LevelOrder = std::cout.rdbuf();
    std::stringstream outputCapture_LevelOrder;
    std::cout.rdbuf(outputCapture_LevelOrder.rdbuf());
    tree.LevelOrder();
    std::cout.rdbuf(originalCoutStream_LevelOrder);
    std::string capturedOutput_LevelOrder = outputCapture_LevelOrder.str();
    std::string sufstr_LevelOrder = "1 2 3 4 5 6 7 ";

    std::streambuf *originalCoutStream_PreOrder = std::cout.rdbuf();
    std::stringstream outputCapture_PreOrder;
    std::cout.rdbuf(outputCapture_PreOrder.rdbuf());
    tree.PreOrder();
    std::cout.rdbuf(originalCoutStream_PreOrder);
    std::string capturedOutput_PreOrder = outputCapture_PreOrder.str();
    std::string sufstr_PreOrder = "1 2 4 5 3 6 7 ";

    std::streambuf *originalCoutStream_InOrder = std::cout.rdbuf();
    std::stringstream outputCapture_InOrder;
    std::cout.rdbuf(outputCapture_InOrder.rdbuf());
    tree.InOrder();
    std::cout.rdbuf(originalCoutStream_InOrder);
    std::string capturedOutput_InOrder = outputCapture_InOrder.str();
    std::string sufstr_InOrder = "4 2 5 1 6 3 7 ";

    std::streambuf *originalCoutStream_PostOrder = std::cout.rdbuf();
    std::stringstream outputCapture_PostOrder;
    std::cout.rdbuf(outputCapture_PostOrder.rdbuf());
    tree.PostOrder();
    std::cout.rdbuf(originalCoutStream_PostOrder);
    std::string capturedOutput_PostOrder = outputCapture_PostOrder.str();
    std::string sufstr_PostOrder = "4 5 2 6 7 3 1 ";

	REQUIRE( capturedOutput_LevelOrder == sufstr_LevelOrder );
    REQUIRE( capturedOutput_PreOrder == sufstr_PreOrder );
    REQUIRE( capturedOutput_InOrder == sufstr_InOrder );
    REQUIRE( capturedOutput_PostOrder == sufstr_PostOrder );
};

// test 2
TEST_CASE("BTree Test 2") {
    BTree<char> tree;
	std::istringstream input("ALCBE@D@@@@W@@X@@");
    std::streambuf* originalCin = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());
    tree.createTree('@');

    std::streambuf *originalCoutStream_LevelOrder = std::cout.rdbuf();
    std::stringstream outputCapture_LevelOrder;
    std::cout.rdbuf(outputCapture_LevelOrder.rdbuf());
    tree.LevelOrder();
    std::cout.rdbuf(originalCoutStream_LevelOrder);
    std::string capturedOutput_LevelOrder = outputCapture_LevelOrder.str();
    std::string sufstr_LevelOrder = "A L C B E D W X ";

    std::streambuf *originalCoutStream_PreOrder = std::cout.rdbuf();
    std::stringstream outputCapture_PreOrder;
    std::cout.rdbuf(outputCapture_PreOrder.rdbuf());
    tree.PreOrder();
    std::cout.rdbuf(originalCoutStream_PreOrder);
    std::string capturedOutput_PreOrder = outputCapture_PreOrder.str();
    std::string sufstr_PreOrder = "A L B E C D W X ";

    std::streambuf *originalCoutStream_InOrder = std::cout.rdbuf();
    std::stringstream outputCapture_InOrder;
    std::cout.rdbuf(outputCapture_InOrder.rdbuf());
    tree.InOrder();
    std::cout.rdbuf(originalCoutStream_InOrder);
    std::string capturedOutput_InOrder = outputCapture_InOrder.str();
    std::string sufstr_InOrder = "B L E A C W X D ";

    std::streambuf *originalCoutStream_PostOrder = std::cout.rdbuf();
    std::stringstream outputCapture_PostOrder;
    std::cout.rdbuf(outputCapture_PostOrder.rdbuf());
    tree.PostOrder();
    std::cout.rdbuf(originalCoutStream_PostOrder);
    std::string capturedOutput_PostOrder = outputCapture_PostOrder.str();
    std::string sufstr_PostOrder = "B E L X W D C A ";

	REQUIRE( capturedOutput_LevelOrder == sufstr_LevelOrder );
    REQUIRE( capturedOutput_PreOrder == sufstr_PreOrder );
    REQUIRE( capturedOutput_InOrder == sufstr_InOrder );
    REQUIRE( capturedOutput_PostOrder == sufstr_PostOrder );
};
