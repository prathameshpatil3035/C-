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


    return 0;
}