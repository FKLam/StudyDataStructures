#ifndef QueueInterface_hpp
#define QueueInterface_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

/**
 * 虚函数：有virtual关键字，且有函数体的函数
 * 纯函数：有virtual关键字，且函数体为 = 0
 * 抽象类：包含纯虚函数的类，抽象类不能被实例化
 * */ 
class QueueInterface
{
public:
    virtual void enqueue(int e) = 0;    // 进队/出队/队首元素
    virtual int dequeue() = 0;
    virtual int getfront() = 0;
    
    virtual int getSize() = 0;          // 获取队列元素个数/容量/是否为空
    virtual bool isEmpty() = 0;
    
    virtual string toString() = 0;      // 输出在控制台的信息
private:
};

#endif /* QueueInterface_hpp */