#include<iostream>
#include"Maxheap.cpp"
using namespace std;


class Priority_Queue{
    private: 
        MaxHeap *heap; 

    public:
    Priority_Queue();
    void insert(int num);
    void pop();
    int top();
    bool empty();
};

Priority_Queue::Priority_Queue()
{
    string sortby = "value";
    heap = new MaxHeap(sortby);
}

void Priority_Queue::insert(int num)
{
    Item itm = Item(num);
    heap->addItem(num);
}

void Priority_Queue::pop(){
    heap->deleteTopItem();
}

int Priority_Queue::top()
{
    return heap->top().getvalue();
}

bool Priority_Queue::empty()
{
    return !heap->getsize();
}
