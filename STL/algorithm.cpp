#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> // for accumulate

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    // Example vector
    vector<int> vec = {5, 3, 1, 4, 2};

    // Sorting
    sort(vec.begin(), vec.end()); // vec: {1, 2, 3, 4, 5}

    int arr[] = {5, 3, 1, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array in descending order using custom comparison function
    sort(arr, arr + n, comp);

    // Output sorted array
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

     // Permutations of a string
    string str = "abc";
    sort(str.begin(), str.end());
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
    //only work with "sorted"string or array

    // Binary search
    bool found = binary_search(vec.begin(), vec.end(), 3); // true

    // Maximum element
    int max_elem = *max_element(vec.begin(), vec.end()); // 5

    // Minimum element
    int min_elem = *min_element(vec.begin(), vec.end()); // 1

    // Count occurrences
    int count_3 = count(vec.begin(), vec.end(), 3); // 1

    // Accumulate
    int sum = accumulate(vec.begin(), vec.end(), 0); // 15 (sum of all elements)

    // Reverse
    reverse(vec.begin(), vec.end()); // vec: {2, 4, 1, 3, 5}

    // Find first occurrence
    auto it = find(vec.begin(), vec.end(), 4); // Iterator to element 4

    // Example using lambda
    int divisible_by_2_count = count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }); // 2

    // Remove element
    vec.erase(remove(vec.begin(), vec.end(), 2), vec.end()); // vec: {4, 1, 3, 5}

    // Shuffle
    random_shuffle(vec.begin(), vec.end());

    // Output vector
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // std::lower_bound:
    // Element present: Returns an iterator pointing to the first element that is not less than the given value.
    // Element not present: Returns an iterator pointing to the first element that is greater than the given value.
    // Element less than all elements: Returns an iterator pointing to the beginning of the sequence.
    // Element greater than all elements: Returns an iterator pointing to the end of the sequence.
    // std::upper_bound:
    // Element present: Returns an iterator pointing to the first element that is greater than the given value.
    // Element not present: Returns an iterator pointing to the first element that is greater than the given value.
    // Element less than all elements: Returns an iterator pointing to the beginning of the sequence.
    // Element greater than all elements: Returns an iterator pointing to the end of the sequence.

    //lower_bound and upper_bound
    vector<int> vec = {1, 2, 3, 3, 3, 4, 5};

    // Case 1: Finding lower bound of 3
    auto lb_3 = lower_bound(vec.begin(), vec.end(), 3);
    cout << "Lower bound of 3: " << *lb_3 << " at index " << distance(vec.begin(), lb_3) << endl;

    // Case 2: Finding upper bound of 3
    auto ub_3 = upper_bound(vec.begin(), vec.end(), 3);
    cout << "Upper bound of 3: " << *ub_3 << " at index " << distance(vec.begin(), ub_3) << endl;

    // Case 3: Finding lower bound of 2
    auto lb_2 = lower_bound(vec.begin(), vec.end(), 2);
    cout << "Lower bound of 2: " << *lb_2 << " at index " << distance(vec.begin(), lb_2) << endl;

    // Case 4: Finding upper bound of 2
    auto ub_2 = upper_bound(vec.begin(), vec.end(), 2);
    cout << "Upper bound of 2: " << *ub_2 << " at index " << distance(vec.begin(), ub_2) << endl;

    // Case 5: Finding lower bound of 6 (element not present)
    auto lb_6 = lower_bound(vec.begin(), vec.end(), 6);
    if (lb_6 == vec.end()) {
        cout << "Lower bound of 6: Not found (element not present)" << endl;
    } else {
        cout << "Lower bound of 6: " << *lb_6 << " at index " << distance(vec.begin(), lb_6) << endl;
    }

    // Case 6: Finding upper bound of 6 (element not present)
    auto ub_6 = upper_bound(vec.begin(), vec.end(), 6);
    if (ub_6 == vec.end()) {
        cout << "Upper bound of 6: Not found (element not present)" << endl;
    } else {
        cout << "Upper bound of 6: " << *ub_6 << " at index " << distance(vec.begin(), ub_6) << endl;
    }

    // Case 7: Finding lower bound of 0 (element less than all)
    auto lb_0 = lower_bound(vec.begin(), vec.end(), 0);
    cout << "Lower bound of 0: " << *lb_0 << " at index " << distance(vec.begin(), lb_0) << endl;

    // Case 8: Finding upper bound of 0 (element less than all)
    auto ub_0 = upper_bound(vec.begin(), vec.end(), 0);
    cout << "Upper bound of 0: " << *ub_0 << " at index " << distance(vec.begin(), ub_0) << endl;

    // Case 9: Finding lower bound of 10 (element greater than all)
    auto lb_10 = lower_bound(vec.begin(), vec.end(), 10);
    cout << "Lower bound of 10: " << *lb_10 << " at index " << distance(vec.begin(), lb_10) << endl;

    // Case 10: Finding upper bound of 10 (element greater than all)
    auto ub_10 = upper_bound(vec.begin(), vec.end(), 10);
    cout << "Upper bound of 10: " << *ub_10 << " at index " << distance(vec.begin(), ub_10) << endl;


    return 0;
}
