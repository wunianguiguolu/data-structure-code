cmake_minimum_required(VERSION 3.14)  # CMake 版本要求

project(HelloWorld)  # 项目名称

set(CMAKE_CXX_STANDARD 14)

# 指定可执行文件生成路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加可执行文件生成规则
# add_executable(HelloWorld HelloWorld.cpp)
# add_executable(List main.cpp List.cpp)

### SequenceList target 
# file( GLOB SRCS *.cpp *.hpp )
# add_executable(SequenceList main.cpp List.cpp SequenceList.cpp List.hpp SequenceList.hpp ${SRCS})
# target_compile_options(SequenceList PRIVATE -Wall -Wextra)            
add_executable(test main.cpp SequenceList.cpp LinkList.cpp LinkQueue.cpp utils.cpp)


find_package(Catch2 3 REQUIRED)
message ( STATUS "Catch2_FOUND      = ${Catch2_FOUND}" )

# Tests for SequenceList
add_executable(SequenceList_test UnitTests/SequenceList_test.cpp SequenceList.cpp utils.cpp)
target_link_libraries(SequenceList_test PRIVATE Catch2::Catch2WithMain)

# Tests for LinkList
add_executable(LinkList_test UnitTests/LinkList_test.cpp LinkList.cpp utils.cpp)
target_link_libraries(LinkList_test PRIVATE Catch2::Catch2WithMain)

# Tests for SequenceStack
add_executable(SequenceStack_test UnitTests/SequenceStack_test.cpp SequenceStack.cpp utils.cpp)
target_link_libraries(SequenceStack_test PRIVATE Catch2::Catch2WithMain)

# Tests for LinkStack
add_executable(LinkStack_test UnitTests/LinkStack_test.cpp LinkStack.cpp utils.cpp)
target_link_libraries(LinkStack_test PRIVATE Catch2::Catch2WithMain)

# Tests for SequenceQueue
add_executable(SequenceQueue_test UnitTests/SequenceQueue_test.cpp SequenceQueue.cpp utils.cpp)
target_link_libraries(SequenceQueue_test PRIVATE Catch2::Catch2WithMain)

# Tests for LinkQueue
add_executable(LinkQueue_test UnitTests/LinkQueue_test.cpp LinkQueue.cpp utils.cpp)
target_link_libraries(LinkQueue_test PRIVATE Catch2::Catch2WithMain)