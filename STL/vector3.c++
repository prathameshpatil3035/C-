#include <iostream>
#include <vector>
#include <algorithm> // For algorithms like find, transform, etc.
#include <numeric>   // For accumulate
#include <iterator>  // For std::back_inserter
#include <sstream>   // For string stream to create join-like behavior
using namespace std;

// Join function to mimic JavaScript's array.join(separator)
string join(const vector<int> &v, const string &separator = ", ")
{
    stringstream ss;
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (i != 0)
            ss << separator;
        ss << v[i];
    }
    return ss.str();
}

// toString function to mimic JavaScript's array.toString()
string toString(const vector<int> &v)
{
    return join(v, ", ");
}

int main()
{
    vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // max_element
    auto maxIt = max_element(numbers.begin(), numbers.end());
    cout << "Max element: " << *maxIt << endl; // Output: Max element: 9

    // min_element
    auto minIt = min_element(numbers.begin(), numbers.end());
    cout << "Min element: " << *minIt << endl; // Output: Min element: 1

    // minmax_element
    auto [minElem, maxElem] = minmax_element(numbers.begin(), numbers.end());
    cout << "MinMax elements: (" << *minElem << ", " << *maxElem << ")" << endl;
    // Output: MinMax elements: (1, 9)

    // find
    auto findIt = find(numbers.begin(), numbers.end(), 9);
    if (findIt != numbers.end())
        cout << "Found element: " << *findIt << endl; // Output: Found element: 9
    else
        cout << "Element not found!" << endl;

    // count
    int countResult = count(numbers.begin(), numbers.end(), 1);
    cout << "Count of 1: " << countResult << endl; // Output: Count of 1: 2

    // all_of, any_of, none_of
    bool allEven = all_of(numbers.begin(), numbers.end(), [](int n)
                          { return n % 2 == 0; });
    bool anyEven = any_of(numbers.begin(), numbers.end(), [](int n)
                          { return n % 2 == 0; });
    bool noneNegative = none_of(numbers.begin(), numbers.end(), [](int n)
                                { return n < 0; });

    cout << "All even? " << allEven << endl;           // Output: All even? 0 (false)
    cout << "Any even? " << anyEven << endl;           // Output: Any even? 1 (true)
    cout << "None negative? " << noneNegative << endl; // Output: None negative? 1 (true)

    // copy
    vector<int> copiedNumbers;
    copy(numbers.begin(), numbers.end(), back_inserter(copiedNumbers));
    cout << "Copied numbers: ";
    for (int n : copiedNumbers)
        cout << n << " ";
    cout << endl; // Output: Copied numbers: 3 1 4 1 5 9 2 6 5

    // transform (C++ equivalent to JavaScript's map)
    vector<int> squaredNumbers(numbers.size());
    transform(numbers.begin(), numbers.end(), squaredNumbers.begin(), [](int n)
              { return n * n; });
    cout << "Squared numbers: ";
    for (int n : squaredNumbers)
        cout << n << " ";
    cout << endl; // Output: Squared numbers: 9 1 16 1 25 81 4 36 25

    // unique
    sort(numbers.begin(), numbers.end()); // unique requires sorted range
    auto last = unique(numbers.begin(), numbers.end());
    numbers.erase(last, numbers.end());
    cout << "Unique numbers: ";
    for (int n : numbers)
        cout << n << " ";
    cout << endl; // Output: Unique numbers: 1 2 3 4 5 6 9

    // replace
    replace(copiedNumbers.begin(), copiedNumbers.end(), 5, 42);
    cout << "Replaced 5 with 42: ";
    for (int n : copiedNumbers)
        cout << n << " ";
    cout << endl; // Output: Replaced 5 with 42: 3 1 4 1 42 9 2 6 42

    // remove
    auto removeIt = remove(copiedNumbers.begin(), copiedNumbers.end(), 42);
    copiedNumbers.erase(removeIt, copiedNumbers.end());
    cout << "Removed 42: ";
    for (int n : copiedNumbers)
        cout << n << " ";
    cout << endl; // Output: Removed 42: 3 1 4 1 9 2 6

    // accumulate (similar to reduce in JavaScript)
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum of numbers: " << sum << endl; // Output: Sum of numbers: 30

    // Join function (JavaScript-like join)
    cout << "Joined numbers: " << join(numbers, ", ") << endl; // Output: Joined numbers: 1, 2, 3, 4, 5, 6, 9

    // toString function (JavaScript-like toString)
    cout << "Numbers toString: " << toString(numbers) << endl; // Output: Numbers toString: 1, 2, 3, 4, 5, 6, 9

    return 0;
}
