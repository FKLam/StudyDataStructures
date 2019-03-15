#include "ArrayStack.hpp"

ArrayStack::ArrayStack(int capacity) {
    array = new AMGArray(capacity);
}

ArrayStack::ArrayStack()  {
    ArrayStack(10);
}

ArrayStack::~ArrayStack()  {
    cout << "ArrayStack~ArrayStack() 析构函数" << endl;
    delete array;
    array = NULL;
}

// 入栈
void ArrayStack::push(int e) {
    array->insertLast(e);
}

// 出栈
int ArrayStack::pop() {
    return array->removeLast();
}

// 获取栈顶元素
int ArrayStack::peek() {
    return array->getLast();
}

// 获取栈中元素个数
int ArrayStack::getSize() {
    return array->getSize();
}

// 获取栈容量
int ArrayStack::getCapacity() {
    return array->getCapacity();
}

// 栈是否为空
bool ArrayStack::isEmpty() {
    return array->isEmpty();
}

// 打印栈内元素
string ArrayStack::toString() {
    char pre[100] = "0";
    int size = array->getSize();
    sprintf(pre, "ArrayStack size:%d, capacity:%d\n", size, array->getCapacity());
    string res = "";
    res.append(pre);
    res.append("[");
    for (int i = 0; i < size; i++) {
        char s[20] = "";
        if ( i != size - 1 ) {
            sprintf(s, "%d，", array->get(i));
        } else {
            sprintf(s, "%d", array->get(i));
        }
        res.append(s);
    }
    res.append("] top");
    return res;
}