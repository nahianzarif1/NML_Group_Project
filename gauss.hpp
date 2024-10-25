
#include <bits/stdc++.h>
using namespace std;

double aa1, bb1, cc1, dd1, ee1, ff1;
double aa2, bb2, cc2, dd2, ee2, ff2;
double aa3, bb3, cc3, dd3, ee3, ff3;
double aa4, bb4, cc4, dd4, ee4, ff4;
double aa5, bb5, cc5, dd5, ee5, ff5;

double ff1_func1(double y, double z, double w, double v) {
    return (ff1 - bb1 * y - cc1 * z - dd1 * w - ee1 * v) / aa1;
}

double ff2_func1(double x, double z, double w, double v) {
    return (ff2 - aa2 * x - cc2 * z - dd2 * w - ee2 * v) / bb2;
}

double ff3_func1(double x, double y, double w, double v) {
    return (ff3 - aa3 * x - bb3 * y - dd3 * w - ee3 * v) / cc3;
}

double ff4_func1(double x, double y, double z, double v) {
    return (ff4 - aa4 * x - bb4 * y - cc4 * z - ee4 * v) / dd4;
}

double ff5_func1(double x, double y, double z, double w) {
    return (ff5 - aa5 * x - bb5 * y - cc5 * z - dd5 * w) / ee5;
}


void main_gauss_seidel() {
    cout << "Enter the coefficients for the 5 equations (a, b, c, d, e, f):\n";

    // Equation 1 coefficients
    cout << "Equation 1: ";
    cin >> aa1 >> bb1 >> cc1 >> dd1 >> ee1 >> ff1;

    // Equation 2 coefficients
    cout << "Equation 2: ";
    cin >> aa2 >> bb2 >> cc2 >> dd2 >> ee2 >> ff2;

    // Equation 3 coefficients
    cout << "Equation 3: ";
    cin >> aa3 >> bb3 >> cc3 >> dd3 >> ee3 >> ff3;

    // Equation 4 coefficients
    cout << "Equation 4: ";
    cin >> aa4 >> bb4 >> cc4 >> dd4 >> ee4 >> ff4;

    // Equation 5 coefficients
    cout << "Equation 5: ";
    cin >> aa5 >> bb5 >> cc5 >> dd5 >> ee5 >> ff5;

     // Ensure diagonal dominance for each row
    if (abs(aa2) > abs(bb2) + abs(cc2) + abs(dd2) + abs(ee2)) {
        swap(aa1, aa2); swap(bb1, bb2); swap(cc1, cc2); swap(dd1, dd2); swap(ee1, ee2); swap(ff1, ff2);
    } else if (abs(aa3) > abs(bb3) + abs(cc3) + abs(dd3) + abs(ee3)) {
        swap(aa1, aa3); swap(bb1, bb3); swap(cc1, cc3); swap(dd1, dd3); swap(ee1, ee3); swap(ff1, ff3);
    } else if (abs(aa4) > abs(bb4) + abs(cc4) + abs(dd4) + abs(ee4)) {
        swap(aa1, aa4); swap(bb1, bb4); swap(cc1, cc4); swap(dd1, dd4); swap(ee1, ee4); swap(ff1, ff4);
    } else if (abs(aa5) > abs(bb5) + abs(cc5) + abs(dd5) + abs(ee5)) {
        swap(aa1, aa5); swap(bb1, bb5); swap(cc1, cc5); swap(dd1, dd5); swap(ee1, ee5); swap(ff1, ff5);
    }

    if (abs(bb3) > abs(aa3) + abs(cc3) + abs(dd3) + abs(ee3)) {
        swap(aa2, aa3); swap(bb2, bb3); swap(cc2, cc3); swap(dd2, dd3); swap(ee2, ee3); swap(ff2, ff3);
    } else if (abs(bb4) > abs(aa4) + abs(cc4) + abs(dd4) + abs(ee4)) {
        swap(aa2, aa4); swap(bb2, bb4); swap(cc2, cc4); swap(dd2, dd4); swap(ee2, ee4); swap(ff2, ff4);
    } else if (abs(bb5) > abs(aa5) + abs(cc5) + abs(dd5) + abs(ee5)) {
        swap(aa2, aa5); swap(bb2, bb5); swap(cc2, cc5); swap(dd2, dd5); swap(ee2, ee5); swap(ff2, ff5);
    }

    if (abs(cc4) > abs(aa4) + abs(bb4) + abs(dd4) + abs(ee4)) {
        swap(aa3, aa4); swap(bb3, bb4); swap(cc3, cc4); swap(dd3, dd4); swap(ee3, ee4); swap(ff3, ff4);
    } else if (abs(cc5) > abs(aa5) + abs(bb5) + abs(dd5) + abs(ee5)) {
        swap(aa3, aa5); swap(bb3, bb5); swap(cc3, cc5); swap(dd3, dd5); swap(ee3, ee5); swap(ff3, ff5);
    }

    if (abs(dd5) > abs(aa5) + abs(bb5) + abs(cc5) + abs(ee5)) {
        swap(aa4, aa5); swap(bb4, bb5); swap(cc4, cc5); swap(dd4, dd5); swap(ee4, ee5); swap(ff4, ff5);
    }

    // Check diagonal dominance for each equation
    if (abs(aa1) < abs(bb1) + abs(cc1) + abs(dd1) + abs(ee1) ||
        abs(bb2) < abs(aa2) + abs(cc2) + abs(dd2) + abs(ee2) ||
        abs(cc3) < abs(aa3) + abs(bb3) + abs(dd3) + abs(ee3) ||
        abs(dd4) < abs(aa4) + abs(bb4) + abs(cc4) + abs(ee4) ||
        abs(ee5) < abs(aa5) + abs(bb5) + abs(cc5) + abs(dd5)) {
        cout << "Diagonal dominance error" << endl;
        exit(0);
    }

    cout << "System is diagonally dominant." << endl;



     // Initial guesses
    double x = 0, y = 0, z = 0, w = 0, v = 0;

    // Arrays to store results of each iteration
    vector<double> rootx(30, 0), rooty(30, 0), rootz(30, 0), rootw(30, 0), rootv(30, 0);
    vector<double> ex(30, 0), ey(30, 0), ez(30, 0), ew(30, 0), ev(30, 0);

    // Gauss-Seidel iterations (up to 20 iterations)
    for (int i = 1; i <= 20; i++) {
        // Update each variable immediately after calculation
        x = ff1_func1(y, z, w, v);  // Update x
        y = ff2_func1(x, z, w, v);  // Update y
        z = ff3_func1(x, y, w, v);  // Update z
        w = ff4_func1(x, y, z, v);  // Update w
        v = ff5_func1(x, y, z, w);  // Update v

        // Store the values of x, y, z, w, v for this iteration
        rootx[i] = x;
        rooty[i] = y;
        rootz[i] = z;
        rootw[i] = w;
        rootv[i] = v;
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





