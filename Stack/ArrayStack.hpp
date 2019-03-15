#ifndef ArrayStack_hpp
#define ArrayStack_hpp

#include <stdio.h>
#include "../AMGArray/AMGArray.hpp"

class ArrayStack
{
public:
    ArrayStack(int capacity);
    ArrayStack();
    ~ArrayStack();
    
    void push(int e);           // 入栈出栈/栈顶元素
    int pop();
    int peek();
    
    int getSize();              // 获取栈元素个数/容量/是否为空
    int getCapacity();
    bool isEmpty();
    string toString();
private:
    AMGArray *array;
};

#endif /* ArrayStack_hpp */