#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main() {
    // Create a tuple
    tuple<int, string, double> myTuple(1, "Hello", 3.14);

    // Access elements using std::get
    cout << "First element: " << get<0>(myTuple) << endl; // First element: 1
    cout << "Second element: " << get<1>(myTuple) << endl; // Second element: Hello
    cout << "Third element: " << get<2>(myTuple) << endl; // Third element: 3.14

    // Modify elements
    get<1>(myTuple) = "World";
    cout << "Modified second element: " << get<1>(myTuple) << endl; // Modified second element: World

    // Tuple size
    cout << "Tuple size: " << tuple_size<decltype(myTuple)>::value << endl; // Tuple size: 3

    // Create a tuple using make_tuple
    auto anotherTuple = make_tuple(2, "Goodbye", 2.71);

    // Tuple concatenation
    auto concatenatedTuple = tuple_cat(myTuple, anotherTuple);

    // Access concatenated tuple elements
    cout << "Concatenated tuple first element: " << get<0>(concatenatedTuple) << endl; // Concatenated tuple first element: 1
    cout << "Concatenated tuple second element: " << get<1>(concatenatedTuple) << endl; // Concatenated tuple second element: World
    cout << "Concatenated tuple fourth element: " << get<3>(concatenatedTuple) << endl; // Concatenated tuple fourth element: 2
    cout << "Concatenated tuple fifth element: " << get<4>(concatenatedTuple) << endl; // Concatenated tuple fifth element: Goodbye

    // Tuple comparison
    if (myTuple < anotherTuple) {
        cout << "myTuple is less than anotherTuple" << endl; // This will not print
    } else {
        cout << "myTuple is not less than anotherTuple" << endl; // myTuple is not less than anotherTuple
    }

    // Unpacking tuple using std::tie
    int i;
    string s;
    double d;
    tie(i, s, d) = myTuple;
    cout << "Unpacked values: " << i << ", " << s << ", " << d << endl; // Unpacked values: 1, World, 3.14

    // Ignoring tuple elements
    tie(i, ignore, d) = myTuple;
    cout << "Partially unpacked values: " << i << ", " << d << endl; // Partially unpacked values: 1, 3.14

    // Using std::tuple_element to get the type of a specific element
    using SecondElementType = tuple_element<1, decltype(myTuple)>::type;
    SecondElementType secondElement = get<1>(myTuple);
    cout << "Second element type and value: " << secondElement << endl; // Second element type and value: World

    // Tuple with reference wrapper
    int a = 10;
    double b = 20.5;
    tuple<int&, double&> refTuple(a, b);

    get<0>(refTuple) = 15;
    get<1>(refTuple) = 25.5;
    cout << "Modified values via tuple: " << a << ", " << b << endl; // Modified values via tuple: 15, 25.5

    return 0;
}
