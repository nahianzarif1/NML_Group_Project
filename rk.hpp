//…(rk4)..(main_rk4)
#include <iostream>
#include <iomanip>
#include <cmath>
#include <functional>

using namespace std;

// Function to implement the Runge-Kutta method
void rungeKutta(function<double(double, double)> f, double x0, double y0, double x_end, double h) {
    double x = x0;
    double y = y0;

    cout << "x\ty" << endl; // Output header

    // Loop until x reaches x_end
    while (x <= x_end) {
        cout << setprecision(6) << fixed << x << "\t" << y << endl; // Print current values
        
        // Calculate the coefficients
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);

        // Update the next value of y
        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        // Increment x by the step size
        x += h;
    }
}

// New example function to define f(x, y) = x^2 + y
double exampleFunction(double x, double y) {
    return x * x + y; // ODE: dy/dx = x^2 + y
}

int main_rk4() {
    double x0, y0, x_end, h;

    // User input for initial conditions and parameters
    cout << "Enter the initial value of x (x0): ";
    cin >> x0;
    cout << "Enter the initial value of y (y0): ";
    cin >> y0;
    cout << "Enter the final value of x (x_end): ";
    cin >> x_end;
    cout << "Enter the step size (h): ";
    cin >> h;

    // Call the Runge-Kutta method
    rungeKutta(exampleFunction, x0, y0, x_end, h);

    return 0;
}