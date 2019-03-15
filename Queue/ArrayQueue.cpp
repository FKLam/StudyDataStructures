#include "ArrayQueue.hpp"

ArrayQueue::ArrayQueue() {
    array = new AMGArray();
}

ArrayQueue::ArrayQueue(int capacity) {
    array = new AMGArray(capacity);
}

ArrayQueue::~ArrayQueue() {
    cout << "ArrayQueue::~ArrayQueue() 析构函数" << endl;
    delete array;
    array = NULL;
}

// 入队 O(1)
void ArrayQueue::enqueue(int e) {
    array->insertLast(e);
}

// 出队 O(n)
int ArrayQueue::dequeue() {
    return array->removeFirst();
}

// 获取队首元素 O(1)
int ArrayQueue::getfront() {
    return array->getFirst();
}

// 获取元素个数
int ArrayQueue::getSize() {
    return array->getSize();
}

// 队列是否为空
bool ArrayQueue::isEmpty() {
    return array->isEmpty();
}

// 输出日志
string ArrayQueue::toString() {
    char pre[100] = "0";
    int size = array->getSize();
    sprintf(pre, "ArrayQueue size:%d, capacity:%d\n", size, array->getCapacity());
    string res = "";
    res.append(pre);
    res.append("Front [");
    for (int i = 0; i < size; i++) {
        char s[20] = "";
        if ( i != size - 1 ) {
            sprintf(s, "%d，", array->get(i));
        } else {
            sprintf(s, "%d", array->get(i));
        }
        res.append(s);
    }
    res.append("] Tail");
    return res;
}