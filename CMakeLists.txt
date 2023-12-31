cmake_minimum_required(VERSION 3.14)  # CMake 版本要求

project(HelloWorld)  # 项目名称

set(CMAKE_CXX_STANDARD 14)

# 指定可执行文件生成路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加可执行文件生成规则
add_executable(HelloWorld HelloWorld.cpp)

### SequenceList target 
# file( GLOB SRCS *.cpp *.hpp )
# add_executable(SequenceList main.cpp List.cpp SequenceList.cpp List.hpp SequenceList.hpp ${SRCS})
# target_compile_options(SequenceList PRIVATE -Wall -Wextra)            
add_executable(test main.cpp src/SequenceList.cpp src/LinkList.cpp src/LinkQueue.cpp src/utils.cpp)


find_package(Catch2 3 REQUIRED)
message ( STATUS "Catch2_FOUND      = ${Catch2_FOUND}" )

# Tests for SequenceList
add_executable(SequenceList_test UnitTests/SequenceList_test.cpp src/SequenceList.cpp src/utils.cpp)
target_link_libraries(SequenceList_test PRIVATE Catch2::Catch2WithMain)

# Tests for LinkList
add_executable(LinkList_test UnitTests/LinkList_test.cpp src/LinkList.cpp src/utils.cpp)
target_link_libraries(LinkList_test PRIVATE Catch2::Catch2WithMain)

# Tests for SequenceStack
add_executable(SequenceStack_test UnitTests/SequenceStack_test.cpp src/SequenceStack.cpp src/utils.cpp)
target_link_libraries(SequenceStack_test PRIVATE Catch2::Catch2WithMain)

# Tests for LinkStack
add_executable(LinkStack_test UnitTests/LinkStack_test.cpp src/LinkStack.cpp src/utils.cpp)
target_link_libraries(LinkStack_test PRIVATE Catch2::Catch2WithMain)

# Tests for SequenceQueue
add_executable(SequenceQueue_test UnitTests/SequenceQueue_test.cpp src/SequenceQueue.cpp src/utils.cpp)
target_link_libraries(SequenceQueue_test PRIVATE Catch2::Catch2WithMain)

# Tests for LinkQueue
add_executable(LinkQueue_test UnitTests/LinkQueue_test.cpp src/LinkQueue.cpp src/utils.cpp)
target_link_libraries(LinkQueue_test PRIVATE Catch2::Catch2WithMain)

# Tests for BTree
add_executable(BTree_test UnitTests/BTree_test.cpp src/BTree.cpp src/SequenceQueue.cpp src/SequenceStack.cpp src/SequenceList.cpp src/utils.cpp)
target_link_libraries(BTree_test PRIVATE Catch2::Catch2WithMain)

# Tests for ParenMatch
add_executable(ParenMatch_test UnitTests/ParenMatch_test.cpp src/ParenMatch.cpp src/LinkStack.cpp)
target_link_libraries(ParenMatch_test PRIVATE Catch2::Catch2WithMain)

# Tests for InToSufForm
add_executable(InToSufForm_test UnitTests/InToSufForm_test.cpp src/InToSufForm.cpp src/LinkStack.cpp)
target_link_libraries(InToSufForm_test PRIVATE Catch2::Catch2WithMain)

# Tests for HfTree
add_executable(HfTree_test UnitTests/HfTree_test.cpp src/HfTree.cpp src/utils.cpp)
target_link_libraries(HfTree_test PRIVATE Catch2::Catch2WithMain)

# Tests for ExpressionTree
add_executable(ExpressionTree src/ExpressionTree.cpp)
target_link_libraries(ExpressionTree PRIVATE Catch2::Catch2WithMain)

# Tests for PriorityQueue
add_executable(PriorityQueue_test UnitTests/PriorityQueue_test.cpp src/PriorityQueue.cpp src/utils.cpp)
target_link_libraries(PriorityQueue_test PRIVATE Catch2::Catch2WithMain)

# Tests for QueueSimulator
add_executable(QueueSimulator src/Simulator src/QueueSimulator.cpp src/LinkQueue.cpp src/PriorityQueue.cpp src/utils.cpp)
target_link_libraries(QueueSimulator PRIVATE Catch2::Catch2WithMain)

# Tests for StaticSearch_test
add_executable(StaticSearch_test UnitTests/StaticSearch_test.cpp src/StaticSearch.cpp)
target_link_libraries(StaticSearch_test PRIVATE Catch2::Catch2WithMain)

# Tests for oj4_1
add_executable(oj4_1 oj4_1.cpp)
target_link_libraries(oj4_1 PRIVATE Catch2::Catch2WithMain)

# Tests for oj4_2
add_executable(oj4_2 oj4_2.cpp)
target_link_libraries(oj4_2 PRIVATE Catch2::Catch2WithMain)