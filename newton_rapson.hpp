//…newtonraphson(main_newton_raphson)
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to evaluate the polynomial at a given x
double ev_poly(double x, double coefficients[]) {
    return coefficients[0] * pow(x, 6) + coefficients[1] * pow(x, 5) +
           coefficients[2] * pow(x, 4) + coefficients[3] * pow(x, 3) +
           coefficients[4] * pow(x, 2) + coefficients[5] * x + coefficients[6];
}

// Function to evaluate the derivative of the polynomial at a given x
double evaluateDerivative(double x, double coefficients[]) {
    return 6 * coefficients[0] * pow(x, 5) + 5 * coefficients[1] * pow(x, 4) +
           4 * coefficients[2] * pow(x, 3) + 3 * coefficients[3] * pow(x, 2) +
           2 * coefficients[4] * x + coefficients[5];
}

// Newton-Raphson Method to find the root of the polynomial
double newtonRaphson(double x0, double coefficients[], double tolerance) {
    double x1;

    while (true) {
        double f_x0 = ev_poly(x0, coefficients);
        double f_prime_x0 = evaluateDerivative(x0, coefficients);

        // Check if the derivative is zero (to avoid division by zero)
        if (fabs(f_prime_x0) < tolerance) {
            cout << "Derivative is too small; no solution found." << endl;
            return NAN; // Return NaN to indicate failure
        }

        // Update x1 using the Newton-Raphson formula
        x1 = x0 - f_x0 / f_prime_x0;

        // Check if the error is within the tolerance
        if (fabs(x1 - x0) < tolerance) {
            break; // Root found or sufficiently close
        }

        // Update for the next iteration
        x0 = x1;
    }

    return x1; // Return the root
}

int main_newton_raphson() {
    double coefficients[7]; // Array to store coefficients for x^6 to x^0
    double x0, tolerance;

    // Input coefficients from the user
    cout << "Enter coefficients for the polynomial (from x^6 to x^0):" << endl;
    for (int i = 0; i < 7; ++i) {
        cout << "Coefficient for x^" << (6 - i) << ": ";
        cin >> coefficients[i];
    }

    // Input initial guess for the Newton-Raphson method
    cout << "Enter initial guess for the root (x0): ";
    cin >> x0;

    // Input tolerance for the root approximation
    cout << "Enter tolerance for the root approximation: ";
    cin >> tolerance;

    // Call the Newton-Raphson method
    double root = newtonRaphson(x0, coefficients, tolerance);

    // Output the result
    if (!isnan(root)) {
        cout << "The root of the polynomial is approximately: " << setprecision(6) << root << endl;
    }

    return 0;
}