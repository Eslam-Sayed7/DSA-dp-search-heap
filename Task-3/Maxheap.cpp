#include <iostream> 
#include <string>
#include <vector>
#include <stack>
#include "Tree.cpp"
using namespace std;


class MaxHeap
{
private:
    Item  *array { };
	int size { };
    string sortBy;    // if want to add more propreties to the item to sort by
	int capacity { 1000 };

public:
    MaxHeap(string sortBy);
    MaxHeap(string sortBy , vector<Item> data);
    int left (int node);
    int right (int node);
    int parent (int node);
    Item top();
    int getsize();
    void addItem(Item item);
    void deleteTopItem();
    void heapify_up(int child_pos);
    void heapify_down(int parent_pos);
    void displayItemsDSC();
    vector<Item> get_items();
    ~MaxHeap();
};

MaxHeap::MaxHeap(string sortBy)
{
    this->sortBy = sortBy;
    this->array = new Item[capacity];
    this->size = 0;
}

MaxHeap::MaxHeap(string sortBy , vector<Item> data)
{
    this->sortBy = sortBy;
    this->array = new Item[capacity];
    this->size = 0;
    for (auto &item : data)
    {
        this->addItem(item);
    }
}

int MaxHeap::left(int node)
{
    int left = 2 * node + 1;
    if (left >= size)
        return -1;
    return left;
}

int MaxHeap::right(int node)
{
    int right = 2 * node + 2;
    return (right >= size) ? -1 : right;
}

int MaxHeap::parent(int node)
{
   return node == 0 ? -1 : (node - 1) / 2;
}

Item MaxHeap::top()
{
    return this->array[0];
}

int MaxHeap::getsize()
{
    return this->size;
}

void MaxHeap::addItem(Item item)
{
    array[size++] = item;
    heapify_up(size - 1);
}

void MaxHeap::deleteTopItem()
{
    if (size == 0)
        cout << "Tree is empty" << "\n";
    else
    array[0] = array[size - 1];
    size--;
    heapify_down(0);
}

void MaxHeap::heapify_up(int child_pos)
{
    int parent_pos = parent(child_pos);
    if (child_pos == 0 || !array[parent_pos].compareBy2(sortBy, array[child_pos]))
        return;
    swap(array[child_pos], array[parent_pos]);
    heapify_up(parent_pos);
}

void MaxHeap::heapify_down(int parent_pos)
{
    int left_child = left(parent_pos);
    int right_child = right(parent_pos);

    if (left_child == -1) // has no children [base case]
        return;

    if (right_child != -1 && !array[right_child].compareBy2(sortBy, array[left_child])) // has only left child
        left_child = right_child; // making the left child the smaller  one to swap with parent      
    
    if (!array[left_child].compareBy2(sortBy, array[parent_pos])) 
        swap(array[parent_pos] , array[left_child]);
        heapify_down(left_child);
}

void MaxHeap::displayItemsDSC()
{
    // Create a temporary copy of the heap
    MaxHeap tempHeap(sortBy);
    tempHeap.array = new Item[capacity];
    tempHeap.size = size;
    for (int i = 0; i < size; i++) {
        tempHeap.array[i] = array[i];
    }
    // Display elements of the temporary copy
    while (tempHeap.size > 0) {
        tempHeap.top().print();
        tempHeap.deleteTopItem();
    }
}

vector<Item> MaxHeap::get_items()
{
    vector<Item> items;
    int f_size = this->getsize();
    for(int i = 0; i < f_size; i++){
        items.push_back(this->top());
        this->deleteTopItem();
    }

    return items;
}

MaxHeap::~MaxHeap()
{
    delete [] array;
    array = nullptr;
    size = 0;
}