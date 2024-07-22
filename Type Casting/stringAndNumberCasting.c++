#include <iostream>
#include <string>

using namespace std;

int main() {
    // String to int
    string strInt = "123";
    int numInt = stoi(strInt);
    cout << "Integer: " << numInt << endl; // Output: Integer: 123

    // String to float
    string strFloat = "123.45";
    float numFloat = stof(strFloat);
    cout << "Float: " << numFloat << endl; // Output: Float: 123.45

    // String to double
    string strDouble = "123.456";
    double numDouble = stod(strDouble);
    cout << "Double: " << numDouble << endl; // Output: Double: 123.456

    // String to long
    string strLong = "123456789";
    long numLong = stol(strLong);
    cout << "Long: " << numLong << endl; // Output: Long: 123456789

    // String to long long
    string strLongLong = "123456789012345";
    long long numLongLong = stoll(strLongLong);
    cout << "Long long: " << numLongLong << endl; // Output: Long long: 123456789012345

    // int to string
    int numToStrInt = 123;
    string strFromInt = to_string(numToStrInt);
    cout << "String from int: " << strFromInt << endl; // Output: String from int: 123

    // float to string
    float numToStrFloat = 123.45f;
    string strFromFloat = to_string(numToStrFloat);
    cout << "String from float: " << strFromFloat << endl; // Output: String from float: 123.450000

    // double to string
    double numToStrDouble = 123.456;
    string strFromDouble = to_string(numToStrDouble);
    cout << "String from double: " << strFromDouble << endl; // Output: String from double: 123.456000

    // long to string
    long numToStrLong = 123456789;
    string strFromLong = to_string(numToStrLong);
    cout << "String from long: " << strFromLong << endl; // Output: String from long: 123456789

    // long long to string
    long long numToStrLongLong = 123456789012345;
    string strFromLongLong = to_string(numToStrLongLong);
    cout << "String from long long: " << strFromLongLong << endl; // Output: String from long long: 123456789012345

    return 0;
}
