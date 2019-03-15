#include "LoopQueue.hpp"

// 默认构造函数
LoopQueue::LoopQueue() {
    array = new int[10 + 1];
    size = 0;
    capacity = 10;
    head = tail = 0;
}

// 带参数构造函数
LoopQueue::LoopQueue(int ncapacity) {
    array = new int[ncapacity + 1];
    size = 0;
    capacity = ncapacity + 1;
    head = tail = 0;
}

// 析构函数
LoopQueue::~LoopQueue() {
    cout << "LoopQueue::~LoopQueue() 析构函数" << endl;
    delete[] array;
    array = NULL;
    size = 0;
    capacity = 0;
    head = tail = 0;
}

// 入队
void LoopQueue::enqueue(int e) {
    // 队列已满
    if ( (tail + 1) % capacity == head ) {
        resize(getCapacity() * 2);
    }

    array[tail] = e;
    tail = (tail + 1) % capacity;
    size++;
}

// 出队
int LoopQueue::dequeue() {
    if ( head == tail ) {
        cout << "LoopQueue 是空队列" << endl;
        return -1;
    }
    int result = array[head];
    head = (head + 1) % capacity;
    size--;
    // 缩容
    if ( size <= getCapacity() / 4 && 0 != getCapacity() / 2 ) {
        resize(getCapacity() / 2);
    }
    return result;
}

// 获取队首元素
int LoopQueue::getfront() {
    return array[head];
}

// 获取队列元素个数
int LoopQueue::getSize() {
    return size;
}

// 获取队列容量
int LoopQueue::getCapacity() {
    return capacity - 1;
}

// 队列是否为空
bool LoopQueue::isEmpty() {
    return head == tail;
}

// 重置容量
void LoopQueue::resize(int ncapacity) {
    int *narray = new int[ncapacity + 1];
    for ( int i = 0; i < size; i++ ) {
        narray[i] = array[(i + head) % capacity];
    }
    delete[] array;
    array = narray;
    capacity = ncapacity + 1;
    head = 0;
    tail = size;
}

// 输出日志
string LoopQueue::toString() {
    char pre[100] = "0";
    sprintf(pre, "ArrayQueue size:%d, capacity:%d\n", size, getCapacity());
    string res = "";
    res.append(pre);
    res.append("Head [");
    for ( int i = head; i != tail; i = (i + 1) % capacity ) {
        char s[20] = "";
        sprintf(s, "%d", array[i]);
        res.append(s);
        if ( (i + 1) % capacity != tail ) {
            res.append(", ");
        }
    }
    res.append("] Tail");
    return res;
}