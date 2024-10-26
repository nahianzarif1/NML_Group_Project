#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const float EPSILON3 = 1e-6;

void swap_rows3(vector<vector<float>>&matrix,int row1,int row2,int var) 
{
    for (int i=0;i<=var;++i)
     {
        swap(matrix[row1][i],matrix[row2][i]);
    }
}

vector<float>LU_Factorization(vector<vector<float>>&matrix,int var) 
{
    vector<float>b(var);
    for (int i=0;i<var;++i) 
    {
        b[i]=matrix[i][var]; 
    }

    vector<vector<float>> L(var,vector<float>(var,0));
    vector<vector<float>> U(var,vector<float>(var,0));

    
    for (int i=0;i<var;++i) {
        L[i][i] = 1;
    }

    for (int j=0;j<var;++j) {
        for (int i=j;i<var;++i) {
            
            float sum=0;
            for (int k=0;k<j;++k) {
                sum+=L[i][k]*U[k][j];
            }
            U[i][j]=matrix[i][j]-sum;
        }

        for (int i=j+1;i<var;++i) 
        {
            
            if (fabs(U[j][j])<EPSILON3) {
                swap_rows3(matrix,j,j+1,var); 
                j--; 
                continue;
            }

            float factor = U[i][j] / U[j][j];
            L[i][j] = factor;

            
            for (int k = j; k < var; ++k) {
                matrix[i][k] -= factor * matrix[j][k];
            }
        }
    }

    
    for (int i = 0; i < var; ++i) {
        for (int j = 0; j < var; ++j) {
            if (i <= j)
                U[i][j] = matrix[i][j];
        }
    }

    vector<float> y(var, 0);
    for (int i = 0; i < var; ++i) {
        y[i] = b[i];  
        for (int j = 0; j < i; ++j) {
            y[i] -= L[i][j] * y[j]; 
        }
    }

    vector<float> x(var, 0);
    for (int i = var - 1; i >= 0; --i) {
        x[i] = y[i];
        for (int j = i + 1; j < var; ++j) {
            x[i] -= U[i][j] * x[j]; 
        }
        x[i] /= U[i][i]; 
    }

    return x;
}

int main_lu_factorization() {
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

    vector<float> x = LU_Factorization(matrix, var);

    cout << "Solution:" << endl;
    for (int i = 0; i < var; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}

