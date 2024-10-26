#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const float EPSILON1 = 1e-6;

void swap_rows1(vector<vector<float>> &matrix, int row1, int row2, int var) {
    for (int i = 0; i <= var; ++i) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}

void gauss_elimination(vector<vector<float>> &matrix, int var)
{
    for (int j = 0; j < var - 1; j++) {
        for (int i = var - 1; i > j; i--) {
            if (matrix[i][j] == 0)
                continue;

            if (matrix[i - 1][j] == 0) {
                swap_rows1(matrix, i, i - 1, var);
                continue;
            }

            float flag = (matrix[i][j] / matrix[i - 1][j]);
            for (int k = 0; k <= var; ++k) {
                matrix[i][k] -= matrix[i - 1][k] * flag;
                if (fabs(matrix[i][k]) < EPSILON1) {
                    matrix[i][k] = 0;
                }
            }
        }
    }
}

void gauss_jordan(vector<vector<float>> &matrix, int var)
{
    for (int j = var - 1; j > 0; j--) {
        for (int i = 0; i < j; i++) {
            if (matrix[i][j] == 0) continue;

            float flag = (matrix[i][j] / matrix[j][j]);
            for (int k = 0; k <= var; ++k) {
                matrix[i][k] -= matrix[j][k] * flag;
                if (fabs(matrix[i][k]) < EPSILON1) {
                    matrix[i][k] = 0;
                }
            }
        }
    }
}

void echelon(vector<vector<float>> &matrix, int var)
{
    for (int i = 0; i < var; i++) {
        float temp = matrix[i][i];
        for (int j = 0; j <= var; ++j) {
            matrix[i][j] /= temp;
            if (fabs(matrix[i][j]) < EPSILON1) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main_gauss_jordan_elimination()
{
    int var;
    cout << "Enter the number of variables: ";
    cin >> var;
    vector<vector<float>> matrix(var, vector<float>(var + 1));

    cout << "Enter the augmented matrix coefficients: \n";
    for (int i = 0; i < var; ++i) {
        for (int j = 0; j <= var; ++j) {
            cin >> matrix[i][j];
        }
    }

    gauss_elimination(matrix, var);
    gauss_jordan(matrix, var);
    echelon(matrix, var);

    cout << "Solution:\n";
    for (int i = 0; i < var; ++i) {
        cout << "x" << i + 1 << " : " << matrix[i][var] << endl;
    }

    return 0;
}
