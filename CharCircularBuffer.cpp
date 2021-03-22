#include <memory>
#include <iostream>
#include "CharCircularBuffer.h"
using namespace std;

CharCircularBuffer::CharCircularBuffer(int capacity)
    : capacity(capacity), buffer(unique_ptr<char[]>(new char[capacity]))
{
    reset();
}

void CharCircularBuffer::printStatus() const
{
    cout << "------------------------------------\n";
    cout << "Buffer Capacity: " <<  getCapacity() << endl;
    cout << "Buffer Size: " <<  getSize() << endl;
    cout << "Buffer isEmpty: " << isEmpty() << endl;
    cout << "Buffer isFull: " << isFull() << endl;
    cout << "------------------------------------\n";
}

bool CharCircularBuffer:: isEmpty() const{
    if((not isFull()) && (head == tail)){
        return true;
    }else{
        return false;
    }
}
bool CharCircularBuffer:: isFull() const{
    return full;
}

void CharCircularBuffer:: reset(){
    tail = 0;
    head = tail ;
    full = false;
}

int CharCircularBuffer:: getCapacity() const{
    return capacity;
}

int CharCircularBuffer::getSize() const{
    if (isFull()){
        return capacity;
    }else {
        return head - tail;
    }
}

void CharCircularBuffer::put(const char ch)
{
    buffer[head] = ch;
    if (isFull()) {
        tail = (tail +1)%capacity ;
    }
    head = (head + 1) % capacity;
    if (head == tail ){
        full = true;
    }
}

char CharCircularBuffer:: get(){
    if (isEmpty()){
        return char();
    } else{
        char temp;
        temp = buffer[tail];
        tail = (tail + 1) % capacity;
        full = false;
        return temp;
    }

}

