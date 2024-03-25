#include <iostream>
#include <utility> // for std::pair
using namespace std;

int main() {
    // Creating a pair of integers
    pair<int, int> p1 = {1, 3};
    cout << p1.first << " " << p1.second << endl;  

    // Creating a pair where the second element is another pair
    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    // Creating an array of pairs
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << arr[1].first << " " << arr[1].second << endl;

    return 0;
}
