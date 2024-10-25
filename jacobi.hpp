#include <bits/stdc++.h>
using namespace std;

double a1, b1, c1, d1, e1, f1;
double a2, b2, c2, d2, e2, f2;
double a3, b3, c3, d3, e3, f3;
double a4, b4, c4, d4, e4, f4;
double a5, b5, c5, d5, e5, f5;

double f1_func(double y, double z, double w, double v) {
    return (f1 - b1 * y - c1 * z - d1 * w - e1 * v) / a1;
}

double f2_func(double x, double z, double w, double v) {
    return (f2 - a2 * x - c2 * z - d2 * w - e2 * v) / b2;
}

double f3_func(double x, double y, double w, double v) {
    return (f3 - a3 * x - b3 * y - d3 * w - e3 * v) / c3;
}

double f4_func(double x, double y, double z, double v) {
    return (f4 - a4 * x - b4 * y - c4 * z - e4 * v) / d4;
}

double f5_func(double x, double y, double z, double w) {
    return (f5 - a5 * x - b5 * y - c5 * z - d5 * w) / e5;
}


void main_jacobi_iteration() {
    cout << "Enter the coefficients for the 5 equations (a, b, c, d, e, f):\n";

    // Equation 1 coefficients
    cout << "Equation 1: ";
    cin >> a1 >> b1 >> c1 >> d1 >> e1 >> f1;

    // Equation 2 coefficients
    cout << "Equation 2: ";
    cin >> a2 >> b2 >> c2 >> d2 >> e2 >> f2;

    // Equation 3 coefficients
    cout << "Equation 3: ";
    cin >> a3 >> b3 >> c3 >> d3 >> e3 >> f3;

    // Equation 4 coefficients
    cout << "Equation 4: ";
    cin >> a4 >> b4 >> c4 >> d4 >> e4 >> f4;

    // Equation 5 coefficients
    cout << "Equation 5: ";
    cin >> a5 >> b5 >> c5 >> d5 >> e5 >> f5;

     // Ensure diagonal dominance for each row
    if (abs(a2) > abs(b2) + abs(c2) + abs(d2) + abs(e2)) {
        swap(a1, a2); swap(b1, b2); swap(c1, c2); swap(d1, d2); swap(e1, e2); swap(f1, f2);
    } else if (abs(a3) > abs(b3) + abs(c3) + abs(d3) + abs(e3)) {
        swap(a1, a3); swap(b1, b3); swap(c1, c3); swap(d1, d3); swap(e1, e3); swap(f1, f3);
    } else if (abs(a4) > abs(b4) + abs(c4) + abs(d4) + abs(e4)) {
        swap(a1, a4); swap(b1, b4); swap(c1, c4); swap(d1, d4); swap(e1, e4); swap(f1, f4);
    } else if (abs(a5) > abs(b5) + abs(c5) + abs(d5) + abs(e5)) {
        swap(a1, a5); swap(b1, b5); swap(c1, c5); swap(d1, d5); swap(e1, e5); swap(f1, f5);
    }

    if (abs(b3) > abs(a3) + abs(c3) + abs(d3) + abs(e3)) {
        swap(a2, a3); swap(b2, b3); swap(c2, c3); swap(d2, d3); swap(e2, e3); swap(f2, f3);
    } else if (abs(b4) > abs(a4) + abs(c4) + abs(d4) + abs(e4)) {
        swap(a2, a4); swap(b2, b4); swap(c2, c4); swap(d2, d4); swap(e2, e4); swap(f2, f4);
    } else if (abs(b5) > abs(a5) + abs(c5) + abs(d5) + abs(e5)) {
        swap(a2, a5); swap(b2, b5); swap(c2, c5); swap(d2, d5); swap(e2, e5); swap(f2, f5);
    }

    if (abs(c4) > abs(a4) + abs(b4) + abs(d4) + abs(e4)) {
        swap(a3, a4); swap(b3, b4); swap(c3, c4); swap(d3, d4); swap(e3, e4); swap(f3, f4);
    } else if (abs(c5) > abs(a5) + abs(b5) + abs(d5) + abs(e5)) {
        swap(a3, a5); swap(b3, b5); swap(c3, c5); swap(d3, d5); swap(e3, e5); swap(f3, f5);
    }

    if (abs(d5) > abs(a5) + abs(b5) + abs(c5) + abs(e5)) {
        swap(a4, a5); swap(b4, b5); swap(c4, c5); swap(d4, d5); swap(e4, e5); swap(f4, f5);
    }

    // Check diagonal dominance for each equation
    if (abs(a1) < abs(b1) + abs(c1) + abs(d1) + abs(e1) ||
        abs(b2) < abs(a2) + abs(c2) + abs(d2) + abs(e2) ||
        abs(c3) < abs(a3) + abs(b3) + abs(d3) + abs(e3) ||
        abs(d4) < abs(a4) + abs(b4) + abs(c4) + abs(e4) ||
        abs(e5) < abs(a5) + abs(b5) + abs(c5) + abs(d5)) {
        cout << "Diagonal dominance error" << endl;
        exit(0);
    }

    cout << "System is diagonally dominant." << endl;


    // Initial guesses
    double x0 = 0, y0 = 0, z0 = 0, w0 = 0, v0 = 0;
    double x, y, z, w, v;

    // Arrays to store results of each iteration
    vector<double> rootx(30, 0), rooty(30, 0), rootz(30, 0), rootw(30, 0), rootv(30, 0);
    vector<double> ex(30, 0), ey(30, 0), ez(30, 0), ew(30, 0), ev(30, 0);

    // Jacobi iterations (up to 20 iterations)
    for (int i = 1; i <= 20; i++) {
        x = f1_func(y0, z0, w0, v0);  // Update x
        y = f2_func(x0, z0, w0, v0);  // Update y
        z = f3_func(x0, y0, w0, v0);  // Update z
        w = f4_func(x0, y0, z0, v0);  // Update w
        v = f5_func(x0, y0, z0, w0);  // Update v

        // Store the values of x, y, z, w, v for this iteration
        rootx[i] = x;
        rooty[i] = y;
        rootz[i] = z;
        rootw[i] = w;
        rootv[i] = v;

        // Update x0, y0, z0, w0, v0 for the next iteration
        x0 = x;
        y0 = y;
        z0 = z;
        w0 = w;
        v0 = v;
    }

    // Calculate the errors for each iteration
    for (int i = 1; i <= 20; i++) {
        ex[i] = abs(rootx[i] - rootx[i - 1]);
        ey[i] = abs(rooty[i] - rooty[i - 1]);
        ez[i] = abs(rootz[i] - rootz[i - 1]);
        ew[i] = abs(rootw[i] - rootw[i - 1]);
        ev[i] = abs(rootv[i] - rootv[i - 1]);
    }

    // Set precision for printing results
    cout << fixed << showpoint << setprecision(5);

    // Print the results for each iteration
    for (int i = 1; i <= 20; i++) {
        cout << "Iteration " << i << ": ";
        cout << "x = " << rootx[i] << ", y = " << rooty[i] << ", z = " << rootz[i]
             << ", w = " << rootw[i] << ", v = " << rootv[i] << "\n";
        cout << "Errors: ex = " << ex[i] << ", ey = " << ey[i] << ", ez = " << ez[i]
             << ", ew = " << ew[i] << ", ev = " << ev[i] << "\n";
    }


}






/*

//this shown diagonal error

 3 1  -1 2 -1 4
 2 3 1 -1 2 7
 1 -1 4 -1 1 5
 -2 1 1 5 -2 -3
 3 2 1 1 6 10

*/



/*

10 1 -1 2 -1 6
2 10 1 -2 3 25
-3 1 10 1 -2 -11
1 -3 2 10 3 15
2 -1 3 -1 10 13

*/

