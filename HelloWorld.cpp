#include <iostream>
#include <cstring>
#include <sstream>
#include "include/BTree.hpp"
#include "include/SequenceQueue.hpp"
using namespace std;

int main()
{
	// 保存原始的标准输出流
    std::streambuf *originalCoutStream = std::cout.rdbuf();
    
    // 创建一个字符串流，用于捕获输出
    std::stringstream outputCapture;
    
    // 重定向标准输出到字符串流
    std::cout.rdbuf(outputCapture.rdbuf());

    // 执行需要捕获输出的操作
    std::cout << "这是一段需要捕获的输出" << std::endl;

    // 恢复原始标准输出流
    std::cout.rdbuf(originalCoutStream);

    // 从字符串流中获取捕获的输出
    std::string capturedOutput = outputCapture.str();

    // 输出捕获的内容
    std::cout << "捕获的输出内容: " << capturedOutput;

    return 0;
}
