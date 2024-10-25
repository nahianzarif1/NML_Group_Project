//…false position.cpp..(main_falseposition)

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to evaluate the polynomial at a given x
double evaluatePolynomial(double x, double coefficients[]) {
    return coefficients[0] * pow(x, 6) + coefficients[1] * pow(x, 5) +
           coefficients[2] * pow(x, 4) + coefficients[3] * pow(x, 3) +
           coefficients[4] * pow(x, 2) + coefficients[5] * x + coefficients[6];
}

// False Position Method to find the root of the polynomial
double falsePosition(double a, double b, double coefficients[], double tolerance) {
    double c;
    
    while (true) {
        // Calculate the root using the false position formula
        c = b - (evaluatePolynomial(b, coefficients) * (a - b)) / 
              (evaluatePolynomial(a, coefficients) - evaluatePolynomial(b, coefficients));
        
        // Check if c is a root or if the error is within the tolerance
        if (fabs(evaluatePolynomial(c, coefficients)) < tolerance || fabs(b - a) < tolerance) {
            break; // Found a root or the interval is sufficiently small
        }

        // Decide the side to repeat the steps
        if (evaluatePolynomial(c, coefficients) * evaluatePolynomial(a, coefficients) < 0) {
            b = c; // The root is in the left half
        } else {
            a = c; // The root is in the right half
        }
    }
    
    return c; // Return the root
}

int main_false_position() {
    double coefficients[7]; // Array to store coefficients for x^6 to x^0
    double a, b, tolerance;

    // Input coefficients from the user
    cout << "Enter coefficients for the polynomial (from x^6 to x^0):" << endl;
    for (int i = 0; i < 7; ++i) {
        cout << "Coefficient for x^" << (6 - i) << ": ";
        cin >> coefficients[i];
    }

    // Input interval [a, b] for the false position method
    cout << "Enter the interval [a, b] where the function changes sign:" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    // Input tolerance for the root approximation
    cout << "Enter tolerance for the root approximation: ";
    cin >> tolerance;

    // Check if the function has different signs at the endpoints
    if (evaluatePolynomial(a, coefficients) * evaluatePolynomial(b, coefficients) >= 0) {
        cout << "The function must have different signs at the endpoints a and b." << endl;
        return 1; // Exit if the condition is not satisfied
    }

    // Call the false position method
    double root = falsePosition(a, b, coefficients, tolerance);

    // Output the result
    cout << "The root of the polynomial is approximately: " << setprecision(6) << root << endl;

    return 0;
}