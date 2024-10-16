#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

// Function to print a 1D vector
void printVector(const vector<int>& vec) {
    cout << "{ ";
    for (int v : vec) {
        cout << v << " ";
    }
    cout << "}";
}

// Function to print a 2D vector (vector of vectors)
void print2DVector(const vector<vector<int>>& vec2D) {
    for (const auto& vec : vec2D) {
        printVector(vec);
        cout << endl;
    }
}

// 1. Subarrays (Best Time Complexity: O(n^2))
vector<vector<int>> generateSubarrays(const vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> subarrays;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> subarray(arr.begin() + i, arr.begin() + j + 1);
            subarrays.push_back(subarray);
        }
    }
    
    return subarrays;
}

// 2. Subsequences (Best Time Complexity: O(2^n))
void generateSubsequencesHelper(const vector<int>& arr, vector<vector<int>>& subsequences, vector<int>& current, int index) {
    if (index == arr.size()) {
        subsequences.push_back(current);
        return;
    }
    // Exclude the current element
    generateSubsequencesHelper(arr, subsequences, current, index + 1);
    
    // Include the current element
    current.push_back(arr[index]);
    generateSubsequencesHelper(arr, subsequences, current, index + 1);
    current.pop_back();
}

vector<vector<int>> generateSubsequences(const vector<int>& arr) {
    vector<vector<int>> subsequences;
    vector<int> current;
    generateSubsequencesHelper(arr, subsequences, current, 0);
    return subsequences;
}

// 3. Subsets (Power Set) using bit manipulation (Best Time Complexity: O(2^n))
vector<vector<int>> generateSubsets(const vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> subsets;
    
    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(arr[j]);
            }
        }
        subsets.push_back(subset);
    }
    
    return subsets;
}

// 4. Permutations (Best Time Complexity: O(n!))
void generateAllPermutations(int index, vector<int>& nums, vector<vector<int>>& ans) {
    if (index == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]);
        generateAllPermutations(index + 1, nums, ans);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> generatePermutations(vector<int>& nums) {
    vector<vector<int>> ans;
    generateAllPermutations(0, nums, ans);
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3};
    
    // 1. Subarrays
    vector<vector<int>> subarrays = generateSubarrays(arr);
    cout << "Subarrays:" << endl;
    print2DVector(subarrays);
    
    /*
    Output:
    { 1 }
    { 1 2 }
    { 1 2 3 }
    { 2 }
    { 2 3 }
    { 3 }
    */
    
    // 2. Subsequences
    vector<vector<int>> subsequences = generateSubsequences(arr);
    cout << "\nSubsequences:" << endl;
    print2DVector(subsequences);
    
    /*
    Output:
    { }
    { 3 }
    { 2 }
    { 2 3 }
    { 1 }
    { 1 3 }
    { 1 2 }
    { 1 2 3 }
    */
    
    // 3. Subsets (Power Set)
    vector<vector<int>> subsets = generateSubsets(arr);
    cout << "\nSubsets (Power Set):" << endl;
    print2DVector(subsets);
    
    /*
    Output:
    { }
    { 1 }
    { 2 }
    { 1 2 }
    { 3 }
    { 1 3 }
    { 2 3 }
    { 1 2 3 }
    */
    
    // 4. Permutations
    vector<vector<int>> permutations = generatePermutations(arr);
    cout << "\nPermutations:" << endl;
    print2DVector(permutations);
    
    /*
    Output:
    { 1 2 3 }
    { 1 3 2 }
    { 2 1 3 }
    { 2 3 1 }
    { 3 2 1 }
    { 3 1 2 }
    */
    
    return 0;
}
