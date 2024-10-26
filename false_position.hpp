//…false position.cpp..(main_falseposition)

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double evaluatePolynomial(double x, double coefficients[]) {
    return coefficients[0] * pow(x, 6) + coefficients[1] * pow(x, 5) +
           coefficients[2] * pow(x, 4) + coefficients[3] * pow(x, 3) +
           coefficients[4] * pow(x, 2) + coefficients[5] * x + coefficients[6];
}


double falsePosition(double a, double b, double coefficients[], double tolerance) {
    double c;
    
    while (true) {

        c = b - (evaluatePolynomial(b, coefficients) * (a - b)) / 
              (evaluatePolynomial(a, coefficients) - evaluatePolynomial(b, coefficients));
        
        if (fabs(evaluatePolynomial(c, coefficients)) < tolerance || fabs(b - a) < tolerance) {
            break; 
        }

      
        if (evaluatePolynomial(c, coefficients) * evaluatePolynomial(a, coefficients) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    
    return c; 
}

int main_false_position() {
    double coefficients[7]; 
    double a, b, tolerance;

    
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

  
    if (evaluatePolynomial(a, coefficients) * evaluatePolynomial(b, coefficients) >= 0) {
        cout << "The function must have different signs at the endpoints a and b." << endl;
        return 1; 
    }

    
    double root = falsePosition(a, b, coefficients, tolerance);


    cout << "The root of the polynomial is approximately: " << setprecision(6) << root << endl;

    return 0;
}
