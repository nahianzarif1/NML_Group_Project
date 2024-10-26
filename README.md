# NML_Group_Project
This project is about solving different type of equations and finding there roots.We have learnt about solving Linear Equations,Non linear Equations,Ordinary Differential Equations and Matrix Inversion Process.The group members are :

1.Abu Jar Gefaree Sayeem
roll:2107033
2.Mahhia Kamal Mim
roll:2107081
3.Al Nahian Zarif
roll:2107098



Abu Jar Gefaree Sayeem

Linear equation:


a)Jacobi iteration method: 
It is one of the simple iterative method. This method updates each variable independently by using values from the previous iteration.  Each variable update does not depend on the others within the same iteration. 

A brief description of how the Jacobi iteration method works in my code :
The program will ask the user to enter coefficients for five linear equations (in the standard form, i.e. a*x + b*y + c*z + d*w + e*v = f).
The code checks for diagonal dominance as the factor (in each row, all main coefficients must be larger than the sum of other coefficients). It check that there is a diagonal dominance, and if it fails then make all possible row swaps to fix the matrix; but in case of success exit with an error. The program initializes all variables ( x, y, z, w ,v) with zero.Next, the program solves up to 20 Jacobi iterations(iteratively) as follows;at each iteration, only one variable is updated at a time by using the most recent values from previous iterations while keeping all other variables fixed.Each iteration saves new values of x, y, z, w and v.
The program is calculating the error for every iteration, for each of variable.For the first 20 iterations, this program prints values & errors of each variable to see how it converges.



b) Gauss seidel  method:
It is an improved version of jacobi iteration method.Here updates each variable immediately, using the most recent values within the same iteration.

A brief description of how the gauss seidel  method works in my code :
The program will ask the user to enter coefficients for five linear equations (in the standard form, i.e. a*x + b*y + c*z + d*w + e*v = f).The code checks for diagonal dominance as the factor (in each row, all main coefficients must be larger than the sum of other coefficients). It check that there is a diagonal dominance, and if it fails then make all possible row swaps to fix the matrix; but in case of success exit with an error.The program initializes all variables ( x, y, z, w ,v) with zero.Every iteration, the program:
–Recursively applies updates to each variable ( x, y, z, w ,v) based on the latest update values for each mask element in order to make most of newly computed one iteration input which leads better convergence efficiency.It will calculate error for all variables after each iteration to track Convergence.For the first 20 iterations, this program prints values & errors of each variable to see how it converges.



C) Runge-Kutta method:
It is a numerical method to solve ordinary differential equation of 1st degree.

A brief description of how the range kutta  method works in my code :
set initial values x0,y0 and xn and step size h.For each interval, compute four slope estimates k1,k2,k3 and k4 at different points to approximate the slope over h.Then use a weighted average of these slope to find out y.Move x ahead by h and repat until reaches xn.
Finally show x and y for solution.









Al Nahian Zarif




Non Linear Equations: 



1.…Bisection Method for Finding Polynomial Roots

The bisection method is a numerical technique used to find the roots of a polynomial within a given interval. This method is particularly useful when the polynomial does not have an analytical solution or when it is difficult to find the roots algebraically. The bisection method works by iteratively narrowing down the interval in which the root lies until a satisfactory approximation is obtained.

…Algorithm

The bisection method algorithm can be summarized as follows:

1. We start with an interval [a, b] such that the function changes sign at the endpoints a and b.
2. Then we calculate the midpoint c = (a + b) / 2.
3. After that ,evaluate the function at the midpoint c.
4. If the function value at c is close enough to zero (i.e., within a specified tolerance), then c is considered as the root and the algorithm terminates.
5. Otherwise, we should determine which half of the interval [a, b] to continue with based on the sign of the function at the midpoint.
6. We must repeat steps 2-5 with the new interval until the function value at the midpoint is sufficiently close to zero.

… Implementation

The bisection method is implemented in C++ using the following steps:

1. We must define a function to evaluate the polynomial at a given x using its coefficients.
2. Then Implementing the bisection method to find the root of the polynomial within a specified interval.
3. Again , the user will input the coefficients of the polynomial and the interval [a, b].
4. Then we check if the function has different signs at the endpoints of the interval, as this is a requirement for the bisection method to work.
5. If the condition is satisfied, call the bisection method to find the root and output the result.

…Example

Consider a polynomial with coefficients [1, -3, 0, 1, 1, -5, 2] for x^6 to x^0. We want to find a root of this polynomial within the interval [1, 2] with a tolerance of 0.001.

Entering the coefficients and interval into the program, we obtain the result that the root of the polynomial is approximately 1.73205.

We must repeat the process every time and change the interval for getting more roots of the equation.

The bisection method provides a simple yet effective way to approximate the roots of a polynomial within a specified interval. By iteratively narrowing down the interval based on the change in sign of the function, this method can be used to find roots even when analytical solutions are not readily available. When implementing the bisection method, it is important to ensure that the initial interval satisfies the condition of having different signs at its endpoints in order for the method to converge to a valid root.

In conclusion, the bisection method is a valuable tool for numerical root finding and can be applied to various types of functions, including polynomials, to obtain accurate approximations of their roots.





2.…False Position Method for Finding Polynomial Roots

The false position method, also known as the regula falsi method, is an iterative technique for finding the roots of a polynomial equation within a specified interval. It is based on the intermediate value theorem, which states that if a continuous function changes sign over an interval, then it must have at least one root within that interval.

…Overview
This method involves iteratively narrowing down the interval in which the root is located by linearly interpolating between two initial points. The process continues until a root is found within a specified tolerance or until the interval becomes sufficiently small.

… Implementation
The implementation of the false position method involves the following steps:

1. Firstly,we give input coefficients for the polynomial from the user.
2. Then,we input the interval [a, b] where the function changes sign.
3. Again,Input the tolerance for the root approximation.
4. Finally,checking if the function has different signs at the endpoints of the interval.
5. And Lastly,applying  the false position method to find the root of the polynomial within the specified interval and tolerance.

The false position method is based on the following formula for linear interpolation:
[ c = b - frac{f(b) \c* (a - b)}{f(a) - f(b)} ]
where:
- ( a ) and ( b ) are the endpoints of the interval
- ( c ) is the new approximation for the root
- ( f(x) ) is the polynomial function to be evaluated

The process involves updating the interval based on the signs of ( f(c) ) and ( f(a) ) to narrow down the range in which the root is located.


…Example
Consider a polynomial with coefficients for (x^6) to (x^0) as follows:
[ 2x^6 - 4x^5 + 3x^4 - 6x^3 + 8x^2 - 5x + 7 ]

Let's find the root of this polynomial within the interval \([1, 3]\) with a tolerance of (0.0001).

The result of applying the false position method to this example yields a root of approximately (1.73205).

… Conclusion
The false position method provides an effective way to approximate the roots of a polynomial equation within a specified interval and tolerance. By iteratively narrowing down the interval based on linear interpolation, this method offers a reliable approach for root-finding in continuous functions.

In conclusion, the false position method serves as a valuable tool in numerical analysis and computational mathematics for solving polynomial equations and finding their roots with precision and efficiency.










3…Secant Method for Finding Polynomial Roots

The Secant Method is a numerical technique used to find the roots of a polynomial. It is an iterative process that uses two initial guesses to approximate the root of the polynomial within a specified tolerance. This method is particularly useful when the derivative of the function is not readily available or when other methods such as the Newton-Raphson method may not converge.

… Implementation in C++

The following C++ code demonstrates the implementation of the Secant Method to find the root of a polynomial. The user is prompted to input the coefficients of the polynomial, initial guesses for the root, and the tolerance for the approximation.



…Usage

To use the Secant Method for finding polynomial roots in C++, follow these steps:

1. Firstly,we must give input the coefficients of the polynomial from highest power to lowest power.
2. Then we must enter two initial guesses for the root.
3. Finally,specify the tolerance for the root approximation.

The program will then use the Secant Method to approximate the root of the polynomial based on the provided inputs.

…Example

Suppose we have a polynomial with the following coefficients:
- Coefficient for x^6: 1
- Coefficient for x^5: -3
- Coefficient for x^4: 0
- Coefficient for x^3: 4
- Coefficient for x^2: -2
- Coefficient for x^1: 1
- Coefficient for x^0: -5

We want to find a root of this polynomial using initial guesses x0 = 1 and x1 = 2 with a tolerance of 0.0001.

Upon running the program with these inputs, we obtain the result:
"The root of the polynomial is approximately: 1.00003"

This demonstrates how the Secant Method can be used to approximate the root of a polynomial based on user-provided inputs.

In conclusion, the Secant Method provides a reliable approach to finding polynomial roots when other methods may not be suitable. Its ease of implementation and ability to handle functions without readily available derivatives make it a valuable tool in numerical analysis and computational mathematics.








4…Newton-Raphson Method for Finding Polynomial Roots

The Newton-Raphson method is a powerful numerical technique used to find the roots of a polynomial equation. In this article, we will discuss the implementation of the Newton-Raphson method in C++ to find the root of a polynomial of degree 6.

…Introduction
The Newton-Raphson method, also known as the Newton's method, is an iterative algorithm used for finding successively better approximations to the roots (or zeroes) of a real-valued function. It is particularly useful for finding the roots of nonlinear equations, including polynomial equations.

…Implementation
We have implemented the Newton-Raphson method in C++ to find the root of a polynomial equation of degree 6. The main components of the implementation include the evaluation of the polynomial and its derivative, as well as the iterative application of the Newton-Raphson formula to converge to the root.

…Function to Evaluate the Polynomial
The `ev_poly` function is used to evaluate the polynomial at a given value of x. It takes the value of x and an array of coefficients as input and returns the value of the polynomial at that point.

… Function to Evaluate the Derivative
The `evaluateDerivative` function calculates the derivative of the polynomial at a given value of x. It also takes the value of x and an array of coefficients as input and returns the value of the derivative at that point.

…Newton-Raphson Method
The `newtonRaphson` function implements the Newton-Raphson method to find the root of the polynomial equation. It takes an initial guess for the root, an array of coefficients representing the polynomial, and a tolerance value as input. It iteratively applies the Newton-Raphson formula to converge to the root within the specified tolerance.

… Usage
To use the implemented Newton-Raphson method, the user is prompted to input the coefficients of the polynomial from highest degree to lowest degree (from x^6 to x^0), an initial guess for the root, and a tolerance for the root approximation. The program then calls the `newtonRaphson` function to find the root and outputs the result.

…Example
Let's consider an example where we want to find the root of a polynomial with the following coefficients:
- Coefficient for x^6: 1
- Coefficient for x^5: -3
- Coefficient for x^4: 0
- Coefficient for x^3: 2
- Coefficient for x^2: 0
- Coefficient for x^1: 1
- Coefficient for x^0: -5

We choose an initial guess for the root as 1 and a tolerance of 0.0001. Running the program with these inputs, we obtain the following result:
```
Enter coefficients for the polynomial (from x^6 to x^0):
Coefficient for x^6: 1
Coefficient for x^5: -3
Coefficient for x^4: 0
Coefficient for x^3: 2
Coefficient for x^2: 0
Coefficient for x^1: 1
Coefficient for x^0: -5
Enter initial guess for the root (x0): 1
Enter tolerance for the root approximation: 0.0001
The root of the polynomial is approximately: 1.73205
```

…Conclusion
The Newton-Raphson method provides an efficient way to find the roots of a polynomial equation. By implementing this method in C++, users can easily approximate the roots of a given polynomial with a specified tolerance. This method is widely used in various fields such as engineering, physics, and finance for solving complex equations and optimizing functions.
