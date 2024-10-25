#include <iostream>

#include "bisection.hpp"
#include "false_position.hpp"
#include "gauss_jordan.hpp"
#include "gauss.hpp"
#include "gausseli.hpp"
#include "jacobi.hpp"
#include "lu.hpp"
#include "mat_inverse.hpp"
#include "newton_rapson.hpp"
#include "rk.hpp"
#include "secant.hpp"
// #include "bisection.hpp"
using namespace std;

int main()
{
    int choice, methodchoice1, methodchoice2, methodchoice3, methodchoice4;
    cout << "Select a categorty to solve the problem:" << endl;
    cout << "1.Solution of linear equations:" << endl;
    cout << "2.Solution of Non-linear equations:" << endl;
    cout << "3.Solution of Differential equations:" << endl;
    cout << "4.Matrix Inversion:" << endl;

    cin >> choice;
    switch (choice)
    {

    case 1:
        cout << "Select a category to solve the problem:" << endl;
        cout << "1. Jacobi-iterative Method" << endl;
        cout << "2. Gauss-Seidel iterative Method" << endl;
        cout << "3. Gauss Elimination Method" << endl;
        cout << "4. Gauss-Jordan Elimination Method" << endl;
        cout << "5. LU Factorization Method" << endl;
        // cout<<"6. Secant Method"<<endl;
        // break;
        cin >> methodchoice1;
        cout << endl;
        switch (methodchoice1)
        {
        case 1:
            main_jacobi_iteration();
            break;
        case 2:
            main_gauss_seidel();
            break;
        case 3:
            main_gauss_elimination2();
            break;
        case 4:
            main_gauss_jordan_elimination();
            break;
        case 5:
            main_lu_factorization();
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
        break;

    case 2:
        cout << "Select a category to solve the problem" << endl;
        cout << "1. Bisection Method" << endl;
        cout << "2. False Position Method" << endl;
        cout << "3. Secant Method" << endl;
        cout << "4. Newton-Raphson Method" << endl;
        // cout<<"5. Gauss-Seidel Method"<<endl;
        cin >> methodchoice2;
        cout << endl;
        switch (methodchoice2)
        {
        case 1:
            main_bisection();
            break;
        case 2:
            main_false_position();
            break;
        case 3:
            main_secant();
            break;
        case 4:
            main_newton_raphson();
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
        break;

    case 3:
        cout << "Select a category to solve the problem" << endl;
        cout << "1. Runge-Kutta Method" << endl;
        cin >> methodchoice3;
        cout << endl;
        switch (methodchoice3)
        {
        case 1:
            main_rk4();
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
        break;

    case 4:
        main_matrix_inver();
        break;
    }
}
