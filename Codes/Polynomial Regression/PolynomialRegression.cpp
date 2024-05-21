#include <iostream>
#include <math.h>
#include <vector>
#include<fstream>
using namespace std;
void gauss_elimination(vector<vector<double>> A, vector<double> B, vector<double> &X, int n)
{
    vector<double> row(n + 1);
    vector<vector<double>> AB(n, row);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            AB[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        AB[i][n] = B[i];
    }
    for (int k = 0; k < n - 1; k++)
    {
        int p = k;
        double big = AB[k][k];
        for (int i = k + 1; i < n; i++)
        {
            if (AB[i][k] > big)
            {
                big = AB[i][k];
                p = i;
            }
        }
        if (p != k)
        {
            for (int i = k; i < n + 1; i++)
            {
                swap(AB[k][i], AB[p][i]);
            }
        }
        for (int i = k + 1; i < n; i++)
        {
            double temp = AB[i][k] / AB[k][k];
            for (int j = k; j < n + 1; j++)
            {
                AB[i][j] = AB[i][j] - (AB[k][j] * temp);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = AB[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        B[i] = AB[i][n];
    }
    X[n - 1] = B[n - 1] / A[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int j = n - 1;
        double sub = 0;
        while (j > i)
        {
            sub += A[i][j] * X[j];
            j--;
        }
        X[i] = (B[i] - sub) / A[i][i];
    }
}
vector<double> Summation(vector<double> X, vector<double> Y, int n, int m)
{
    vector<double> row(m+1);
    vector<vector<double>> A(m+1,row);
    vector<double> B(m+1);
    vector<double> Z(m+1);
    for(int i=0;i<m+1;i++){
        B[i] = 0;
        for(int j=0;j<n;j++){
            B[i]+=Y[j]*pow(X[j],i);
        }
    }
    for(int i=0;i<m+1;i++){
        for(int j=0;j<m+1;j++){
            A[i][j]=0;
            for(int k=0;k<n;k++){
                A[i][j]+=pow(X[k],i+j);
            }
        }
    }
    gauss_elimination(A,B,Z,m+1);
    return Z;
}
int main()
{
    ifstream f;
    ofstream s;
    // f.open("InputPolynomialRegressionControlConcrete.txt");
    f.open("InputPolynomialRegressionBacterialConcrete.txt");
    s.open("OutputPolynomialRegression.txt");
    //Enter the degree of the polynomial you want to generate
    int m;
    f >> m;
    //Enter the number of data points
    int n;
    f >> n;
    s << "Enter the value of Xs" << endl;
    vector<double> X(n);
    for (int i = 0; i < n; i++)
    {
        f >> X[i];
    }
    //Enter the value of Ys
    vector<double> Y(n);
    for (int i = 0; i < n; i++)
    {
        f >> Y[i];
    }
    s<<"The values of coefficients are:"<<endl;
    vector<double> output = Summation(X, Y, n, m);
    for (int i = 0; i < output.size(); i++)
    {
        s << output[i] << endl;
    }
    f.close();
    s.close();
}