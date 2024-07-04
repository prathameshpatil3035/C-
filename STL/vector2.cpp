#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector < pair <int, int >> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    vector <int> v1 (5, 100); // {100, 100, 100, 100, 100}
    vector <int> v2(5); // empty vector of size 5
    vector <int> v3 = {1, 2, 3, 4, 5};

    vector <int> :: iterator it = v.begin();
    it++;
    it = it + 2;
    cout<< *it << " ";

    for (vector <int> :: iterator it = v.begin(); it != v.end(); it++){
        cout<< *it << " ";
    }

    for (auto it = v.begin(); it != v.end(); it++){
        cout<< *it << " ";
    }

    for(auto it : v){
        cout << it << " ";      // it is the vale here
    }

    for(auto& it : v){
        cout << it << " ";      // it is a pointer here
    }

    // Declare a 2D vector of integers
    vector<vector<int>> vect;

    // Declare and initialize a 2D vector using list initialization
    vector<vector<int>> vect = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Initialize with specific sizes and default values
    int rows = 3, cols = 4, defaultValue = 0;
    vect = vector<vector<int>>(rows, vector<int>(cols, defaultValue));
    // vector<vector<int>> vec(rows, vector<int>(cols, defaultValue));

    // Assign values using the assign method
    int rows = 3, cols = 4, defaultValue = 0;
    vect.assign(rows, vector<int>(cols, defaultValue));

    // Specify the size and dynamically initialize it
    int rows = 3, cols = 4;
    vect.resize(rows);
    for (int i = 0; i < rows; ++i) {
        vect[i].resize(cols, 0); // initializing with 0
    }

    vect.resize(rows, vector<int>(cols, defaultValue));

    // Print the 2D vector
    for (const auto& row : vect) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Allocate memory for a 2D array
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    // Initialize the 2D array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = 0; // example initialization
        }
    }

    return 0;
}