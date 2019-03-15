#include <iostream>
#include <ctime>
#include "AMGArray/AMGArray.hpp"
#include "Stack/ArrayStack.hpp"
#include "Queue/ArrayQueue.hpp"
#include "Queue/LoopQueue.hpp"

#define KQUEUETEST_NUMBER 1000

using namespace std;

void testArray();

void testArrayStack();

void testArrayQueue();

void testLoopQueue();

void testArrayQueueNum(int num);

void testLoopQueueNum(int num);

int main(int argc, char* argv[]) {
    // testArrayStack();
    // testArrayQueue();
    // testLoopQueue();

    // testArrayQueueNum(KQUEUETEST_NUMBER);
    // testLoopQueueNum(KQUEUETEST_NUMBER);

    cout << "测试测试！！！" << endl;

    return 0;
}

// 测试自定义数组
void testArray() {
    // 初始化数组类
    AMGArray *array = new AMGArray(100);
    for ( int i = 0; i < 100; i++ ) {
        array->insertLast(i);
    }
    cout << array->toString() << endl;
    // 释放创建的内存
    delete array;
    array = NULL;
}

// 测试数组栈
void testArrayStack() {
    // 初始化数组栈
    ArrayStack *stack = new ArrayStack(10);
    for ( int i = 0; i < 20; i++ ) {
        if ( i % 4 == 3 ) {
            // 出栈
            stack->pop();
        } else {
            // 入栈
            stack->push(i);
        }
        cout << stack->toString() << endl;
    }
    // 释放创建的内存
    delete stack;
    stack = NULL;
}

// 测试数组队列
void testArrayQueue() {
    // 初始化数组队列
    ArrayQueue *queue = new ArrayQueue(10);
    for ( int i = 0; i < 20; i++ ) {
        if ( i % 4 == 3 ) {
            // 出栈
            queue->dequeue();
        } else {
            // 入栈
            queue->enqueue(i);
        }
        cout << queue->toString() << endl;
    }
    // 释放创建的内存
    delete queue;
    queue = NULL;
}

// 测试循环队列
void testLoopQueue() {
    // 初始化数组队列
    LoopQueue *queue = new LoopQueue(10);
    for ( int i = 0; i < 20; i++ ) {
        // 入栈
        queue->enqueue(i);
        cout << queue->toString() << endl;
        if ( i % 4 == 3 ) {
            // 出栈
            queue->dequeue();
            cout << queue->toString() << endl;
        }
    }
    // 释放创建的内存
    delete queue;
    queue = NULL;
}

// 测试数组队列性能
void testArrayQueueNum(int num) {
    clock_t startTime, endTime;
    startTime = clock();    // 计时开始
    ArrayQueue *queue = new ArrayQueue(10);
    for ( int i = 0; i < num; i++ ) {
        // 入队
        queue->enqueue(i);
    }
    for ( int i = 0; i < num; i++ ) {
        // 出队
        queue->dequeue();
    }
    endTime = clock();  // 结束时间
    cout << "ArrayQueue: time " << (double)(endTime - startTime) / 1000 << " s" << endl;
    // 释放创建的内存
    delete queue;
    queue = NULL;
}

// 测试循环队列性能
void testLoopQueueNum(int num) {
    clock_t startTime, endTime;
    startTime = clock();    // 计时开始
    LoopQueue *queue = new LoopQueue(10);
    for ( int i = 0; i < num; i++ ) {
        // 入队
        queue->enqueue(i);
    }
    for ( int i = 0; i < num; i++ ) {
        // 出队
        queue->dequeue();
    }
    endTime = clock();  // 结束时间
    cout << "LoopQueue: time " << (double)(endTime - startTime) / 1000 << " s" << endl;
    // 释放创建的内存
    delete queue;
    queue = NULL;
}