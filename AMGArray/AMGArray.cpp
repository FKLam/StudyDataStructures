#include "AMGArray.hpp"

// 默认构造函数
AMGArray::AMGArray()  {
    AMGArray(10);   // 默认10个空间
}

// 传入容量的构造函数
AMGArray::AMGArray(int capacity) {
    if ( 0 >= capacity ) {
        capacity = 10;
        cout << "capacity 必须大于0的整数" << endl;
    }
    data = new int[capacity];
    this->capacity = capacity;
    size = 0;
}

// 析构函数 释放资源
AMGArray::~AMGArray()  {
    cout << "AMGArray::~AMGArray() 析构函数" << endl;
    delete[] data;
    capacity = 0;
    size = 0;
}

// 获取元素个数
int AMGArray::getSize() {
    return size;
}

// 获取容量
int AMGArray::getCapacity() {
    return capacity;
}

// 数组是否为空
bool AMGArray::isEmpty() {
    return 0 == size;
}

// 在指定位置添加元素
void AMGArray::insert(int index, int e) {
    if ( index < 0 || index > size ) {
        cout << "Index 不合法" << endl;
        return;
    }
    // 是否容量已满/扩容
    if ( size == capacity ) {
        resize(capacity * 2);
    }
    // 从后往前赋值
    for (int i = size; i >= index; i--) {
        data[i + 1] = data[i];
    }
    // 腾出来的位置放入e元素
    data[index] = e;
    size++;
}

// 在尾部添加元素
void AMGArray::insertLast(int e) {
    insert(size, e);
}

// 在开始位置添加元素
void AMGArray::insertFirst(int e) {
    insert(0, e);
}

// 删除某个位置上的元素
int AMGArray::remove(int index) {
    if ( index < 0 || index >= size ) {
        cout << "remove Index 不合法 " << index << endl;
        return -1;
    }
    // 从index位置开始往后赋值
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    int res = data[index];
    data[size - 1] = 0;  // 游荡元素
    size--;
    // 缩容
    if ( size == capacity / 4 && 0 != capacity / 2 ) {
        resize(capacity / 2);
    }
    return res;
}

// 删除尾部元素
int AMGArray::removeLast() {
    return remove(size - 1);
}

// 删除第一个元素
int AMGArray::removeFirst() {
    return remove(0);
}

// 获取index位置上的元素
int AMGArray::get(int index) {
    if ( index < 0 || index >= size ) {
        cout << "Index 不合法" << endl;
        return -1;
    }
    return data[index];
}

// 更新index位置上的元素
void AMGArray::set(int index, int e) {
    if ( index < 0 || index >= size ) {
        cout << "Index 不合法" << endl;
    }
    data[index] = e;
}

// 获取最后一个元素
int AMGArray::getLast() {
    return get(size - 1);
}

// 获取第一个元素
int AMGArray::getFirst() {
    return get(0);
}

// 是否包含某个元素
bool AMGArray::contains(int e) {
    for ( int i = 0; i < size; i++ ) {
        if ( data[i] != e ) {
            continue;
        }
        return true;
    }
    return false;
}

// 查找数组中元素所在的索引，如果不存在元素e，则返回-1
int AMGArray::find(int e) {
    for ( int i = 0; i < size; i++ ) {
        if ( data[i] != e ) {
            continue;
        }
        return i;
    }
    return -1;
}

// 从数组中删除元素e
void AMGArray::removeElement(int e) {
    int index = find(e);
    if ( -1 == index ) {
        return;
    }
    remove(index);
}       

// 打印数组内元素
string AMGArray::toString() {
    char pre[100] = "0";
    sprintf(pre, "AMGArray size:%d, capacity:%d\n", size, capacity);
    string res = "";
    res.append(pre);
    res.append("[");
    for (int i = 0; i < size; i++) {
        char s[20] = "";
        if ( i != size - 1 ) {
            sprintf(s, "%d，", data[i]);
        } else {
            sprintf(s, "%d", data[i]);
        }
        res.append(s);
    }
    res.append("]");
    return res;
}

// 扩容
void AMGArray::resize(int newCapacity) {
    if ( 0 >= newCapacity ) {
        cout << "newCapacity 不合法" << endl;
        return;
    }
    // 开辟新的空间
    int *newData = new int[newCapacity];
    // 将元素逐个赋值到新的空间
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    // 是否旧的空间
//    delete data;
    // 将旧的指向新空间
    data = newData;
    // 维护容量
    capacity = newCapacity;
}