#ifndef LoopQueue_hpp
#define LoopQueue_hpp

#include "QueueInterface.hpp"

// 循环队列继承自QueueInterface
class LoopQueue: public QueueInterface
{
public:
    LoopQueue();               // 构造函数/析构函数
    LoopQueue(int ncapacity);
    ~LoopQueue();

    virtual void enqueue(int e);    // 进队/出队/队首元素
    virtual int dequeue();
    virtual int getfront();
    
    virtual int getSize();          // 获取队列元素个数/容量/是否为空
    virtual bool isEmpty();
    
    virtual string toString();      // 输出在控制台的信息

    int getCapacity();
private:
    int *array;
    int size;
    int capacity;
    int head, tail;     // 头索引，尾索引

    void resize(int ncapacity);
};

#endif /* LoopQueue_hpp */