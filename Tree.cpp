#pragma once
#include <iostream>
using namespace std;

class Item
{
private:
    int value;

public:
    Item();
    Item(int value);
    bool operator<(const Item &anotherItem);
    bool operator>(const Item &anotherItem);
    void print();
    int getvalue();
    bool compareBy2(string by, Item &anotherItem);
};

Item::Item()
{
    this->value = 1;
}

Item::Item(int value)
{
    this->value = value;
}

bool Item::operator<(const Item &anotherItem)
{
    return this->value < anotherItem.value;
}

bool Item::operator>(const Item &anotherItem)
{
    return this->value > anotherItem.value;
}

void Item::print()
{
    // freopen("output.txt", "a", stdout);
    cout << "Value: " << this->value << '\n';
    cout << "-----------------------------------\n";
}

int Item::getvalue()
{
    return this->value;
}

bool Item::compareBy2(string by, Item &anotherItem)
{
    return this->value < anotherItem.value;
}