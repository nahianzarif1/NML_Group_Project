//…matrixinversion..(main_matrix_inver)
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Function to perform matrix inversion
bool invertMatrix(vector<vector<double>>& matrix, vector<vector<double>>& inverse) {
    int n = matrix.size(); // Size of the matrix

    // Create an augmented matrix [matrix | I]
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = (i == j) ? 1.0 : 0.0; // Initialize identity matrix
        }
    }

    // Applying Gaussian elimination
    for (int i = 0; i < n; ++i) {
        // Find the pivot element
        double pivot = matrix[i][i];
        if (pivot == 0) {
            return false; // Matrix is singular and cannot be inverted
        }

        // Normalize the pivot row
        for (int j = 0; j < n; ++j) {
            matrix[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }

        // Eliminate the other rows
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < n; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }
    return true;
}

int main_matrix_inver() {
    int n;

    // User input for matrix size
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));
    vector<vector<double>> inverse(n, vector<double>(n));

    // User input for matrix elements
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Call the invertMatrix function
    if (invertMatrix(matrix, inverse)) {
        cout << "The inverse of the matrix is:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << setprecision(6) << fixed << inverse[i][j] << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "The matrix is singular and cannot be inverted." << endl;
    }

    return 0;
}