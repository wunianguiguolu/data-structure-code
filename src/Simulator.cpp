#include<iostream>
#include <cstdlib>
#include <ctime>
#include "../include/QueueSimulator.hpp"
#include "../include/PriorityQueue.hpp"
using namespace std;

//输入：
//4
//0 2
//2 7
//1000
int main()
{
    //test priorityQueue
    PriorityQueue<int> q;
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) 
    {
        int num = rand() % 1000;
        cout << "插入：" << num << "  ";
        q.enQueue(num);
    }
    cout << endl;
    while (!q.isEmpty()) 
    {
        cout << q.deQueue() << "出队\n";
    }
    //test simulator
    simulator sim;
    cout << "平均等待时间："
        << sim.avgWaitTime() << endl;
    return 0;
}