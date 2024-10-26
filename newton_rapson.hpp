//…newtonraphson(main_newton_raphson)
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double ev_poly(double x, double coefficients[]) {
    return coefficients[0] * pow(x, 6) + coefficients[1] * pow(x, 5) +
           coefficients[2] * pow(x, 4) + coefficients[3] * pow(x, 3) +
           coefficients[4] * pow(x, 2) + coefficients[5] * x + coefficients[6];
}


double evaluateDerivative(double x, double coefficients[]) {
    return 6 * coefficients[0] * pow(x, 5) + 5 * coefficients[1] * pow(x, 4) +
           4 * coefficients[2] * pow(x, 3) + 3 * coefficients[3] * pow(x, 2) +
           2 * coefficients[4] * x + coefficients[5];
}


double newtonRaphson(double x0, double coefficients[], double tolerance) {
    double x1;

    while (true) {
        double f_x0 = ev_poly(x0, coefficients);
        double f_prime_x0 = evaluateDerivative(x0, coefficients);

       
        if (fabs(f_prime_x0) < tolerance) {
            cout << "Derivative is too small; no solution found." << endl;
            return NAN;
        }


        x1 = x0 - f_x0 / f_prime_x0;


        if (fabs(x1 - x0) < tolerance) {
            break; 
        }


        x0 = x1;
    }

    return x1;
}

int main_newton_raphson() {
    double coefficients[7]; 
    double x0, tolerance;


    cout << "Enter coefficients for the polynomial (from x^6 to x^0):" << endl;
    for (int i = 0; i < 7; ++i) {
        cout << "Coefficient for x^" << (6 - i) << ": ";
        cin >> coefficients[i];
    }


    cout << "Enter initial guess for the root (x0): ";
    cin >> x0;


    cout << "Enter tolerance for the root approximation: ";
    cin >> tolerance;


    double root = newtonRaphson(x0, coefficients, tolerance);


    if (!isnan(root)) {
        cout << "The root of the polynomial is approximately: " << setprecision(6) << root << endl;
    }

    return 0;
}
