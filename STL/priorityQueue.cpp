#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Constructor
    priority_queue<int> myPriorityQueue;

    // push
    myPriorityQueue.push(30);
    myPriorityQueue.push(10);
    myPriorityQueue.push(50);

    // Output: Priority queue elements after push: 50 30 10
    cout << "Priority queue elements after push: ";
    while (!myPriorityQueue.empty()) {
        cout << myPriorityQueue.top() << " ";
        myPriorityQueue.pop();
    }
    cout << endl;

    // push with custom comparator
    auto cmp = [](int a, int b) { return a > b; }; // Min-heap comparator
    priority_queue<int, vector<int>, decltype(cmp)> myMinPriorityQueue(cmp);

    myMinPriorityQueue.push(30);
    myMinPriorityQueue.push(10);
    myMinPriorityQueue.push(50);

    // Output: Min-heap priority queue elements after push: 10 30 50
    cout << "Min-heap priority queue elements after push: ";
    while (!myMinPriorityQueue.empty()) {
        cout << myMinPriorityQueue.top() << " ";
        myMinPriorityQueue.pop();
    }
    cout << endl;

    // empty
    cout << "Is priority queue empty? " << (myPriorityQueue.empty() ? "Yes" : "No") << endl; // Output: Is priority queue empty? Yes

    // size
    cout << "Size of priority queue: " << myPriorityQueue.size() << endl; // Output: Size of priority queue: 0


    // To declare a minimal priority queue 
    auto cmp = [](int a, int b) { return a > b; }; // Min-heap comparator
    priority_queue<int, vector<int>, decltype(cmp)> minPriorityQueue1(cmp);

    priority_queue<int, vector<int>, greater<int>> myMinPriorityQueue;

    myMinPriorityQueue.push(30);
    myMinPriorityQueue.push(10);
    myMinPriorityQueue.push(50);

    // Output: Min-heap priority queue elements after push: 10 30 50
    cout << "Min-heap priority queue elements after push: ";
    while (!myMinPriorityQueue.empty()) {
        cout << myMinPriorityQueue.top() << " ";
        myMinPriorityQueue.pop();
    }
    cout << endl;

    // empty
    cout << "Is priority queue empty? " << (myPriorityQueue.empty() ? "Yes" : "No") << endl; // Output: Is priority queue empty? Yes

    // size
    cout << "Size of priority queue: " << myPriorityQueue.size() << endl; // Output: Size of priority queue: 0

    priority_queue<int, vector<int>, decltype(cmp)> minPriorityQueue(cmp);

    // Push elements into the min-heap
    minPriorityQueue.push(10);
    minPriorityQueue.push(30);
    minPriorityQueue.push(20);

    // Output: Min-heap priority queue elements after push: 10 20 30

    return 0;
}
