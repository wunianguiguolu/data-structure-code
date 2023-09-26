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
add_executable(SequenceList main.cpp SequenceList.cpp)


find_package(Catch2 3 REQUIRED)
message ( STATUS "Catch2_FOUND      = ${Catch2_FOUND}" )

# Tests for SequenceList
add_executable(SequenceList_test UnitTests/SequenceList_test.cpp SequenceList.cpp)
target_link_libraries(SequenceList_test PRIVATE Catch2::Catch2WithMain)

# Tests for LinkList
add_executable(LinkList_test UnitTests/LinkList_test.cpp LinkList.cpp)
target_link_libraries(LinkList_test PRIVATE Catch2::Catch2WithMain)