#include<iostream>
#include <cstdlib>
#include <ctime>
#include "../include/QueueSimulator.hpp"
#include "../include/LinkQueue.hpp"
#include "../include/PriorityQueue.hpp"
using namespace std;

simulator::simulator()
{
    cout << "请输入柜台数："; 
    cin >> noOfServer;
    cout << "请输入到达时间间隔的上下界（最小间隔时间  最大间隔时间）：";
    cin >> arrivalLow >> arrivalHigh;
    cout << "请输入服务时间的上下界（服务时间下界  服务时间上界）： ";
    cin >> serviceTimeLow >> serviceTimeHigh;
    cout << "请输入模拟的顾客数：";
    cin >> customNum;
    srand(time(NULL));
}

int simulator:: avgWaitTime()
{ 
    int serverBusy = 0;  //正在工作的服务台数
    int currentTime;  //记录模拟过程中的时间
    int totalWaitTime = 0;  //模拟过程中所有顾客的等待时间的总和
    LinkQueue<eventT> waitQueue;  //顾客等待队列
    PriorityQueue<eventT> eventQueue;  //事件队列
    eventT currentEvent;
    int i;
    currentEvent.time = 0;
    currentEvent.type = 0;
    for (i = 0; i < customNum; ++i)  //生成初始的事件队列
    {
        currentEvent.time += arrivalLow + 
                            (arrivalHigh -arrivalLow +1) *
                            rand() / (RAND_MAX + 1);
        eventQueue.enQueue(currentEvent);
    }

    //模拟过程
    while (!eventQueue.isEmpty())
    {
        currentEvent = eventQueue.deQueue();
        currentTime = currentEvent.time;
        switch (currentEvent.type)
        {
        case 0:  //处理到达事件
            if (serverBusy != noOfServer)
            { 
                ++serverBusy;
                currentEvent.time += serviceTimeLow +
                                    (serviceTimeHigh - serviceTimeLow +1) *
                                    rand() / (RAND_MAX + 1);
                currentEvent.type = 1;
                eventQueue.enQueue(currentEvent);
            }
            else waitQueue.enQueue(currentEvent);
            break;
        case 1:  //处理离开事件
            if (!waitQueue.isEmpty())
            {
                currentEvent = waitQueue.deQueue();
                totalWaitTime += currentTime - currentEvent.time;
                currentEvent.time = currentTime + serviceTimeLow +
                                    (serviceTimeHigh - serviceTimeLow +1) *
                                    rand() / (RAND_MAX + 1);
                currentEvent.type = 1;
                eventQueue.enQueue(currentEvent);
            }
            else --serverBusy;
        }//switch结束
    }//while结束
    //cout << totalWaitTime << " " << customNum << endl;
    return totalWaitTime / customNum;
}
