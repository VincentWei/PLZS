#include <iostream>
#include <cassert>

using namespace std;

// returns the nth Fibonacci number
unsigned fibonacci(unsigned n)
{
    if (n < 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    unsigned max;
    cin >> max;                     // Gets the maximal integer from user.

    cout << "1, 1";                 // Prints the first two Fibonacci numbers.
    unsigned n = 3;                 // Starts from the 3rd Fibonacci numbers.
    while (true) {
        unsigned c = fibonacci(n);  // Gets the nth Fibonacci number.
        if (c >= max)               // Breaks the loop if the number
            break;                  //      larger than the maximum.

        cout << ", " << c;          // Prints the Fibonacci number.
        n++;                        // Forwards to the next Fibonacci number.
    }

    // Prints the dot and the end of the line character.
    cout << "." << endl;
}

