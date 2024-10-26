#include <iostream>
#include "Tree.cpp"
#include "Maxheap.cpp"
#include <vector>
#include <fstream>
using namespace std;


MaxHeap *Maxheap_By_value = nullptr;

int dataStructureType ;
char HeapType = 'n';
int systemStatus;
// systemStatus = -1 ----> exist
// systemStatus = 1  ----> Home screen
// systemStatus = 2  ----> Data structure options

vector<Item> ReadDataFromFiles(){
    ifstream readFile("input.txt");
    vector<Item> data;
    string line;

    while (getline(readFile, line))
    {
        int value = atoi(line.c_str());
        Item item(value);
        data.push_back(item);
    }
    return data;
}

void useHeap(vector<Item> data){
    if (HeapType != '1' && HeapType != '2')
    {
        HeapType = '2';
        Maxheap_By_value = new MaxHeap("value", data);
    }
    
}

void HeapOptions(){
    if (HeapType == '2') {
        cout << "1. Add Item data\n"
            <<"2. Remove Top Item\n"
            <<"3. Display Items in Descending order (from input.txt file)\n"
            <<"4. Exit\n";
    } 
    char choose;
    cin >> choose; 
    if (choose == '1') // Add item
    {
        int value;
        cout << "Enter the value of the Item you to add\n";
        cin >> value;
        Item tmp(value);
        Maxheap_By_value->addItem(tmp);
        cout << "The Item has been added successfully :)\n";

    } else if (choose == '2') // Remove Item
    {
        Maxheap_By_value->deleteTopItem();
        cout << "The Item has been deleted successfully :)\n";
    }
    else if (choose =='3') // Display Name Descending
    {
        Maxheap_By_value->displayItemsDSC();
    }
    else if (choose == '4')
    {
        cout<<"Salam :)";
        systemStatus = -1;
    }
    else{
        cout << "You Typed a wrong number\n";
    }
}

vector<Item> heapSort( vector<int> data) {
    vector<Item> Itemized;
    for(int i = 0 ; i < data.size(); i++){
        Item itm = Item(data[i]);
        Itemized.push_back(itm);
    }

    MaxHeap *heap = new MaxHeap("value" , Itemized);
    return heap->get_items();
}

void SecondScreen() {
    while (systemStatus == 2)
    {
        if(dataStructureType == 1){
                HeapOptions();
        } else if (dataStructureType == 2) {
                HeapOptions();
        } else{
          return;
        }
    }
}

void HomeScreen(vector<Item> data) {

    while (systemStatus == 1)
    {
        cout << "Choose which data structure you would like to use:\n";
        cout << "1. Heap sort\n"
            <<"2. priority queue\n";
        char choice;
        cin >> choice;
        if (choice == '1') // Heap sort
        {
            dataStructureType = 1;
            systemStatus = 2;

            vector<Item> newcleandata;
            data = newcleandata; 

            int NumberOfItems;
            cout << "Enter the number of items you want to sort: ";   
            cin >> NumberOfItems;

            int value;
            for (int i = 0 ; i < NumberOfItems; i++){
                cin >> value;
                data.push_back(Item(value));                
            }
            
            useHeap(data);
            SecondScreen();
        }
        else if (choice == '2') // Heap (priority queue)
        {
            dataStructureType = 2;
            systemStatus = 2;
            useHeap(data);
            SecondScreen();
        }
        else // not exist
        {
            cout << "You Entered a choose not Exist in the System :\\\n";
        }
    }
}

int main()
{

    // vector<Item> data = ReadDataFromFiles();
    // systemStatus = 1;
    // while (systemStatus != -1)
    // {
    //     cout<< "-----Welcome------\n";
    //     HomeScreen(data);
    // }

    // you can use heapsort externally in you program as the following
    vector<int> items {657, 600, 60 ,78 , 500 , 20 , 60 , 150};
    vector<Item> sorted = heapSort(items);
    for(int i = 0; i < sorted.size(); i++) {
        cout << sorted[i].getvalue() << " ";
    }
    return 0;
}