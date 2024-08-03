#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    // Create an unordered set of integers
    unordered_set<int> uset;

    // Insert elements
    uset.insert(10);
    uset.insert(20);
    uset.insert(30);
    uset.insert(40);

    // Check if an element exists
    if (uset.find(20) != uset.end())
    {
        cout << "Element 20 found" << endl;
    }
    else
    {
        cout << "Element 20 not found" << endl;
    }

    // Erase an element
    uset.erase(30);

    // Check if an element exists after erasure
    if (uset.find(30) != uset.end())
    {
        cout << "Element 30 found" << endl;
    }
    else
    {
        cout << "Element 30 not found" << endl;
    }

    // Print all elements
    cout << "Elements in the unordered set:" << endl;
    for (const int &elem : uset)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Check the size of the unordered set
    cout << "Size of unordered set: " << uset.size() << endl;

    // Check if the unordered set is empty
    if (uset.empty())
    {
        cout << "Unordered set is empty" << endl;
    }
    else
    {
        cout << "Unordered set is not empty" << endl;
    }

    // Clear all elements
    uset.clear();
    cout << "Size of unordered set after clearing: " << uset.size() << endl;

    return 0;
}
