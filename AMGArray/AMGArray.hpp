#ifndef AMGArray_hpp
#define AMGArray_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class AMGArray
{
public:
    AMGArray();                     // 构造函数
    AMGArray(int capacity);
    
    ~AMGArray();                    // 析构函数
    
    int getSize();                  // 获取元素个数/容量/是否为空
    int getCapacity();
    bool isEmpty();
    
    void insert(int index, int e);  // 添加元素
    void insertLast(int e);
    void insertFirst(int e);
    
    int remove(int index);          // 删除元素
    int removeLast();
    int removeFirst();
    
    int get(int index);             // 获取元素
    int getFirst();
    int getLast();
    
    string toString();              // 打印结果
private:
    int *data;                      // 静态数组
    int size;                       // 数组中元素的个数
    int capacity;                   // 数组容量
    
    void resize(int newCapacity);   // 扩容
};

#endif /* AMGArray_hpp */