#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const float EPSILON2 = 1e-6;

void swap_rows2(vector<vector<float>> &matrix, int row1, int row2, int var) {
    for (int i = 0; i <= var; ++i) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}

vector<float>  gauss_elimination2(vector<vector<float>> &matrix, int var)
{
   
    for (int j = 0; j < var - 1; j++)
    {
        for (int i = var - 1; i > j; i--)
        {
            if(matrix[i][j] == 0) {
                continue;
            }

            if(matrix[i-1][j] == 0) {
                swap_rows2(matrix, i, i-1, var);
                continue;
            }

            float factor = (matrix[i][j] / matrix[i-1][j]);
            for (int k = 0; k <= var; ++k) {
                matrix[i][k] -= (matrix[i-1][k] * factor);
                if (fabs(matrix[i][k]) < EPSILON2) {
                    matrix[i][k] = 0;
                }
            }
        }
    }

   //row echelon
    for (int i = 0; i < var; i++) {
        float diagonal_element = matrix[i][i];
        if (fabs(diagonal_element) > EPSILON2) {
            for (int j = 0; j <= var; ++j) {
                matrix[i][j] /= diagonal_element;
                if (matrix[i][j] == -0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }


//solution
vector<float> result(var);    

for (int i = var - 1; i >= 0; --i) {
        result[i] = matrix[i][var];  
        for (int j = i + 1; j < var; ++j) {
            result[i] -= matrix[i][j] * result[j];
        }
    }

    return result;
   
}

int main_gauss_elimination2()
{
    int var;
    cout << "Enter the number of variables: ";
    cin >> var;

    vector<vector<float>> matrix(var, vector<float>(var + 1));
    cout << "Enter the augmented matrix coefficients:" << endl;
    for (int i = 0; i < var; ++i) {
        for (int j = 0; j <= var; ++j) {
            cin >> matrix[i][j];
        }
    }


    vector<float> result=gauss_elimination2(matrix, var);

    
    cout << "\nSolution:\n";
    for (int i = 0; i < var; ++i) {
        cout << "x" << i + 1 << " : " << result[i] << endl;
    }

    return 0;
}
