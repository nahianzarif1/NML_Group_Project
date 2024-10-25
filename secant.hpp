//..secant…(main_secant)
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to evaluate the polynomial at a given x
double polygamy(double x, double coefficients[]) {
    return coefficients[0] * pow(x, 6) + coefficients[1] * pow(x, 5) +
           coefficients[2] * pow(x, 4) + coefficients[3] * pow(x, 3) +
           coefficients[4] * pow(x, 2) + coefficients[5] * x + coefficients[6];
}

// Secant Method to find the root of the polynomial
double secant(double x0, double x1, double coefficients[], double tolerance) {
    double x2;
    
    while (true) {
        // Calculate the next approximation using the secant formula
        x2 = x1 - (polygamy(x1, coefficients) * (x1 - x0)) / 
              (polygamy(x1, coefficients) - polygamy(x0, coefficients));

        // Check if the error is within the tolerance
        if (fabs(x2 - x1) < tolerance) {
            break; // Root found or sufficiently close
        }

        // Update for the next iteration
        x0 = x1;
        x1 = x2;
    }
    
    return x2; // Return the root
}

int main_secant() {
    double coefficients[7]; // Array to store coefficients for x^6 to x^0
    double x0, x1, tolerance;

    // Input coefficients from the user
    cout << "Enter coefficients for the polynomial (from x^6 to x^0):" << endl;
    for (int i = 0; i < 7; ++i) {
        cout << "Coefficient for x^" << (6 - i) << ": ";
        cin >> coefficients[i];
    }

    // Input initial guesses for the secant method
    cout << "Enter two initial guesses for the root (x0, x1):" << endl;
    cout << "x0: ";
    cin >> x0;
    cout << "x1: ";
    cin >> x1;

    // Input tolerance for the root approximation
    cout << "Enter tolerance for the root approximation: ";
    cin >> tolerance;

    // Call the secant method
    double root = secant(x0, x1, coefficients, tolerance);

    // Output the result
    cout << "The root of the polynomial is approximately: " << setprecision(6) << root << endl;

    return 0;
}