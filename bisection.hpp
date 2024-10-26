//..bisection.cpp(main_bisection)

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double polynomial(double x, double coefficients[]) {
    return coefficients[0] * pow(x, 6) + coefficients[1] * pow(x, 5) +
           coefficients[2] * pow(x, 4) + coefficients[3] * pow(x, 3) +
           coefficients[4] * pow(x, 2) + coefficients[5] * x + coefficients[6];
}


double bisection(double a, double b, double coefficients[], double tolerance, int maxIterations) {
    double c;
    int iteration = 0;

    while ((b - a) >= tolerance && iteration < maxIterations) {
        c = (a + b) / 2; // Midpoint
        double f_a = polynomial(a, coefficients);
        double f_c = polynomial(c, coefficients);

        
        if (fabs(f_c) < tolerance) {
            return c;
        }

        if (f_a * f_c < 0) {
            b = c;
        } else {
            a = c;
        }
        
        iteration++;
    }
    return c; 
}

int main_bisection() { 
    double coefficients[7] = {0}; 
    double a, b, tolerance;
    int maxIterations;


    cout << "Enter coefficients for the polynomial (from x^6 to x^0):" << endl;
    for (int i = 0; i < 7; ++i) {
        cout << "Coefficient for x^" << (6 - i) << ": ";
        cin >> coefficients[i];
    }

    
    cout << "Enter the interval [a, b] where the function changes sign:" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;


    cout << "Enter tolerance for the root approximation: ";
    cin >> tolerance;


    cout << "Enter maximum number of iterations: ";
    cin >> maxIterations;

    
    if (polynomial(a, coefficients) * polynomial(b, coefficients) >= 0) {
        cout << "The function must have different signs at the endpoints a and b." << endl;
        return 1; // Exit if the condition is not satisfied
    }

    double root = bisection(a, b, coefficients, tolerance, maxIterations);

 
    cout << "The root of the polynomial is approximately: " << setprecision(6) << root << endl;

    return 0;
}
