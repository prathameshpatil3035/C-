#include <iostream>
#include <cmath>

#include <cstdlib> // For std::rand() and std::srand()
#include <ctime>   // For std::time()

using namespace std;

int main()
{
    // Trigonometric Functions
    double angle = 45.0;
    double radians = angle * M_PI / 180.0;

    // min and max
    int a = min(23, 24);
    a = max(23, 24);

    cout << "sin(45 degrees) = " << sin(radians) << endl;
    // Output: sin(45 degrees) = 0.707107
    cout << "cos(45 degrees) = " << cos(radians) << endl;
    // Output: cos(45 degrees) = 0.707107
    cout << "tan(45 degrees) = " << tan(radians) << endl;
    // Output: tan(45 degrees) = 1

    // Remainder function
    cout << "remainder(10, 3) = " << remainder(10, 3) << endl;
    // Output: remainder(10, 3) = 1

    // Exponential and Logarithmic Functions
    cout << "log(10) = " << log(10) << endl;
    // Output: log(10) = 2.30259
    cout << "exp(2) = " << exp(2) << endl;
    // Output: exp(2) = 7.38906
    cout << "sqrt(16) = " << sqrt(16) << endl;
    // Output: sqrt(16) = 4
    cout << "pow(2, 3) = " << pow(2, 3) << endl;
    // Output: pow(2, 3) = 8
    cout << "exp2(3) = " << exp2(3) << endl;
    // Output: exp2(3) = 8
    cout << "log2(16) = " << log2(16) << endl;
    // Output: log2(16) = 4
    double result = log10(1833);
    // Output: log10(result) = 3.263849
    cout << "ln(2) = " << M_LN2 << endl;
    // Output: ln(2) = 0.693147
    cout << "ln(10) = " << M_LN10 << endl;
    // Output: ln(10) = 2.30259
    cout << "log2(e) = " << M_LOG2E << endl;
    // Output: log2(e) = 1.4427
    cout << "log10(e) = " << M_LOG10E << endl;
    // Output: log10(e) = 0.434294

    // Rounding and Remainder Functions
    cout << "Ceiling of 3.14 = " << ceil(3.14) << endl;
    // Output: Ceiling of 3.14 = 4
    cout << "Floor of 3.14 = " << floor(3.14) << endl;
    // Output: Floor of 3.14 = 3
    cout << "trunc(3.5) = " << trunc(3.5) << endl;
    // Output: trunc(3.5) = 3
    cout << "round(3.7) = " << round(3.7) << endl;
    // Output: round(3.7) = 4 or for round(3.3) = 3

    // Constants
    cout << "Pi (π) = " << M_PI << endl;
    // Output: Pi (π) = 3.14159
    cout << "Euler's number (e) = " << M_E << endl;
    // Output: Euler's number (e) = 2.71828
    cout << "Natural logarithm of 2 = " << M_LN2 << endl;
    // Output: Natural logarithm of 2 = 0.693147
    cout << "Natural logarithm of 10 = " << M_LN10 << endl;
    // Output: Natural logarithm of 10 = 2.30259
    cout << "Base 2 logarithm of e = " << M_LOG2E << endl;
    // Output: Base 2 logarithm of e = 1.4427
    cout << "Base 10 logarithm of e = " << M_LOG10E << endl;
    // Output: Base 10 logarithm of e = 0.434294

    // Floating-point Manipulation Functions
    cout << "abs(-5) = " << abs(-5) << endl;
    // Output: abs(-5) = 5
    cout << "fabs(-5.5) = " << fabs(-5.5) << endl;
    // Output: fabs(-5.5) = 5.5
    cout << "fmod(10, 3) = " << fmod(10, 3) << endl;
    // Output: fmod(10, 3) = 1
    cout << "remainder(10, 3) = " << remainder(10, 3) << endl;
    // Output: remainder(10, 3) = 1
    cout << "fmin(2.5, 5.7) = " << fmin(2.5, 5.7) << endl;
    // Output: fmin(2.5, 5.7) = 2.5
    cout << "fmax(2.5, 5.7) = " << fmax(2.5, 5.7) << endl;
    // Output: fmax(2.5, 5.7) = 5.7
    cout << "fdim(5.7, 2.5) = " << fdim(5.7, 2.5) << endl;
    // Output: fdim(5.7, 2.5) = 3.2
    cout << "fma(2, 3, 4) = " << fma(2, 3, 4) << endl;
    // Output: fma(2, 3, 4) = 10

    // #include <cstdlib> // For std::rand() and std::srand()
    // #include <ctime>   // For std::time()
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0))); // timestamp no. e.g. 92882718191

    // Define the range
    int lower_bound = 1;
    int upper_bound = 10;

    // Generate a random number within the range
    int random_number = lower_bound + rand() % (upper_bound - lower_bound + 1);

    // Output the random number
    cout << "Random number between " << lower_bound << " and " << upper_bound << ": " << random_number << endl;

    // No. of digits in a number
    int number = 191827272;
    int count = static_cast<int>(log10(abs(number))) + 1;

    // type casting

    string str = "12345";

    int num = stoi(str);          // Converts to int
    long lnum = stol(str);        // Converts to long
    long long llnum = stoll(str); // Converts to long long

    string floatStr = "123.45";
    float fnum = stof(floatStr);         // Converts to float
    double dnum = stod(floatStr);        // Converts to double
    long double ldnum = stold(floatStr); // Converts to long double

    int num = 12345;
    double dnum = 123.45;

    string str = to_string(num);
    string dstr = to_string(dnum);

    double pi = 3.14;
    int intPi = static_cast<int>(pi); // Converts double to int

    return 0;
}
