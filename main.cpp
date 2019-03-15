#include <iostream>
#include "AMGArray/AMGArray.hpp"
#include "Stack/ArrayStack.hpp"
#include "Queue/ArrayQueue.hpp"
#include "Queue/LoopQueue.hpp"

using namespace std;

void testArray();

void testArrayStack();

void testArrayQueue();

void testLoopQueue();

int main(int argc, char* argv[]) {
    // testArrayStack();
    // testArrayQueue();
    testLoopQueue();
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