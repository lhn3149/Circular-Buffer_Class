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