#include <iostream>
#include <algorithm> // For sort, min_element, max_element
#include <numeric>   // For accumulate
#include <iterator>  // For begin(), end()
#include <vector>
using namespace std;

int main()
{
    int arr[] = {5, 2, 9, 1, 7};

    // iterator (int*) and reverse iterator = reverse_iterator<int*>

    auto it = begin(arr);
    it = end(arr);
    auto reverseit = rbegin(arr);
    reverseit = rend(arr);

    // 1. Finding the size of the array
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Size of array: " << size << endl; // 5

    // 2. Sorting the array
    sort(begin(arr), end(arr));
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " "; // 1 2 5 7 9
    cout << endl;

    // 3. min_element
    int minElement = *min_element(begin(arr), end(arr));
    cout << "Min element: " << minElement << endl; // 1

    // 4. max_element
    int maxElement = *max_element(begin(arr), end(arr));
    cout << "Max element: " << maxElement << endl; // 9

    // 6. minmax_element
    auto minmax = minmax_element(begin(arr), end(arr));
    cout << "Min element: " << *minmax.first << ", Max element: " << *minmax.second << endl; // 1, 9

    // 7. Calculating the sum of elements
    int sum = accumulate(begin(arr), end(arr), 0);
    cout << "Sum of elements: " << sum << endl; // 24

    // 8. Searching for an element (binary search requires a sorted array)
    bool found = binary_search(begin(arr), end(arr), 5);
    cout << "Element 5 found: " << (found ? "Yes" : "No") << endl; // Yes

    // 9. Reversing the array
    reverse(begin(arr), end(arr));
    cout << "Reversed array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " "; // 9 7 5 2 1
    cout << endl;

    // 10. find
    auto it = find(begin(arr), end(arr), 7);
    if (it != end(arr))
        cout << "Element 7 found at position: " << distance(begin(arr), it) << endl; // 4

    // 11. count
    int countOf7 = count(begin(arr), end(arr), 7);
    cout << "Count of 7: " << countOf7 << endl; // 2

    // 12. all_of
    bool allPositive = all_of(begin(arr), end(arr), [](int x)
                              { return x > 0; });
    cout << "All elements positive: " << (allPositive ? "Yes" : "No") << endl; // Yes

    // 13. any_of
    bool anyGreaterThan10 = any_of(begin(arr), end(arr), [](int x)
                                   { return x > 10; });
    cout << "Any element greater than 10: " << (anyGreaterThan10 ? "Yes" : "No") << endl; // No

    // 14. none_of
    bool noneNegative = none_of(begin(arr), end(arr), [](int x)
                                { return x < 0; });
    cout << "None negative: " << (noneNegative ? "Yes" : "No") << endl; // Yes

    // 15. copy
    int arrCopy[size];
    copy(begin(arr), end(arr), arrCopy);
    cout << "Copied array: ";
    for (int i : arrCopy)
        cout << i << " "; // 5 2 9 1 7 7 9 3
    cout << endl;

    // 16. transform (doubling each element)
    transform(begin(arr), end(arr), arrCopy, [](int x)
              { return x * 2; });
    cout << "Transformed array (doubled): ";
    for (int i : arrCopy)
        cout << i << " "; // 10 4 18 2 14 14 18 6
    cout << endl;

    // 17. unique (only works on sorted arrays)
    sort(begin(arr), end(arr)); // Need to sort before unique
    auto uniqueEnd = unique(begin(arr), end(arr));
    cout << "Unique elements: ";
    for (auto it = begin(arr); it != uniqueEnd; ++it)
        cout << *it << " "; // 1 2 3 5 7 9
    cout << endl;

    // 18. replace (replace all 7s with 0)
    replace(begin(arr), end(arr), 7, 0);
    cout << "Array after replacing 7 with 0: ";
    for (int i : arr)
        cout << i << " "; // 1 2 3 5 0 9
    cout << endl;

    // 19. remove (remove all 0s)
    auto removeEnd = remove(begin(arr), end(arr), 0);
    cout << "Array after removing 0s: ";
    for (auto it = begin(arr); it != removeEnd; ++it)
        cout << *it << " "; // 1 2 3 5 9
    cout << endl;

    // 20. remove_if (remove all elements less than 5)
    removeEnd = remove_if(begin(arr), end(arr), [](int x)
                          { return x < 5; });
    cout << "Array after removing elements < 5: ";
    for (auto it = begin(arr); it != removeEnd; ++it)
        cout << *it << " "; // 5 9
    cout << endl;

    // 21. accumulate (sum of all elements)
    int sum = accumulate(begin(arr), end(arr), 0);
    cout << "Sum of elements: " << sum << endl; // 14

    // 22. front
    cout << "Front element: " << arr[0] << endl; // 5 or *begin(arr)

    // 23. back
    cout << "Back element: " << *(removeEnd - 1) << endl; // 9 or *end(arr)

    // 24. data (pointer to the first element of the array)
    cout << "Pointer to the first element: " << arr << endl; // (Address of first element)

    // 25. lower_bound (find first position not less than 5)
    auto lb = lower_bound(begin(arr), end(arr), 5);
    cout << "Lower bound for 5: " << (lb != removeEnd ? *lb : -1) << endl; // 5

    // 26. upper_bound (find first position greater than 5)
    auto ub = upper_bound(begin(arr), end(arr), 5);
    cout << "Upper bound for 5: " << (ub != removeEnd ? *ub : -1) << endl; // 9

    // 27. Filling the array with a value
    fill(begin(arr), end(arr), 0);
    cout << "Array after filling with 0: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " "; // 0 0 0 0 0
    cout << endl;

    // 28. copy_if like filter
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> evenNumbers; // Vector to store filtered results

    // Use copy_if to filter even numbers into evenNumbers vector
    copy_if(numbers, numbers + size, back_inserter(evenNumbers), [](int n)
            {
                return n % 2 == 0; // Condition to filter even numbers
            });

    return 0;
}
