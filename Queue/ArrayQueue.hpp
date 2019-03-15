#ifndef ArrayQueue_hpp
#define ArrayQueue_hpp

#include "QueueInterface.hpp"
#include "../AMGArray/AMGArray.hpp"

// 数组队列继承自QueueInterface
class ArrayQueue: public QueueInterface
{
public:
    ArrayQueue();               // 构造函数/析构函数
    ArrayQueue(int capacity);
    ~ArrayQueue();

    virtual void enqueue(int e);    // 进队/出队/队首元素
    virtual int dequeue();
    virtual int getfront();
    
    virtual int getSize();          // 获取队列元素个数/容量/是否为空
    virtual bool isEmpty();
    
    virtual string toString();      // 输出在控制台的信息
private:
    AMGArray *array;
};

#endif /* ArrayQueue_hpp */