#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


template<typename T>
int sequentialSearchIterative(vector<T> &list, T target) {
    for (int i = 0; i < list.size(); ++i) {
        if (list[i] == target)
            return i;
    }
    return -1;  // if not found
}

template<typename T>
int sequentialSearchRecursive(vector<T> &list, T target, int i = 0) {
    if(i == list.size())
        return -1;  // if not found
    if(list[i] == target)
        return i;
    return sequentialSearchRecursive(list, target, i+1);
}



// if using binary search, the list must be sorted
template<typename T>
int binarySearchIterative(vector<T>& list, T target){
    int l = 0, r = list.size()-1;
    while(l <= r){
        int mid = l + (r - l)/2; // i using it instead (l+r)/2 to void overflow
        if(list[mid] == target)
            return mid;
        else if(list[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return -1; // if not found
}



// if using binary search, the list must be sorted
template<typename T>
int _binarySearchRecursive(vector<T>& list, T target, int l, int r){
    if(l > r)
        return -1;

    int mid = l + (r - l)/2; // i using it instead (l+r)/2 to void overflow

    if(list[mid] > target)
        return _binarySearchRecursive(list, target, l, mid-1);
    else if (list[mid] < target)
        return _binarySearchRecursive(list, target, mid + 1, r);

    return mid;
    
}

template<typename T>
int binarySearchRecursive(vector<T>& list, T target){
    return _binarySearchRecursive(list, target, 0, list.size()-1);
}

int main(){
    int numberTarget;
    string nameTarget;

    cout << "enter the target of numbers and target of names : ";
    cin >> numberTarget >> nameTarget;

    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<string> names = {"ali", "anas", "eslam", "mekkawy", "omar", "youssef"};

    // test sequentialSearchIterative once using strings and once using intgers
    cout << "Result for test Sequential Search Iterative : ";
    cout << sequentialSearchIterative(numbers, numberTarget) << " ";
    cout << sequentialSearchIterative(names, nameTarget) << '\n';

    cout << "--------------------------------------------------------------\n\n";

    // test sequentialSearchRecursive once using strings and once using intgers
    cout << "Result for test Sequential Search Recursive : ";
    cout << sequentialSearchRecursive(numbers, numberTarget) << " ";
    cout << sequentialSearchRecursive(names, nameTarget) << '\n';


    cout << "--------------------------------------------------------------\n\n";

    // test sequentialSearchRecursive once using strings and once using intgers
    cout << "Result for test Binary Search Iterative : ";
    cout << binarySearchIterative(numbers, numberTarget) << " ";
    cout << binarySearchIterative(names, nameTarget) << '\n';



    cout << "--------------------------------------------------------------\n\n";

    // test sequentialSearchRecursive once using strings and once using intgers
    cout << "Result for test Binary Search Recursive : ";
    cout << binarySearchRecursive(numbers, numberTarget) << " ";
    cout << binarySearchRecursive(names, nameTarget) << '\n';



    return 0;
}