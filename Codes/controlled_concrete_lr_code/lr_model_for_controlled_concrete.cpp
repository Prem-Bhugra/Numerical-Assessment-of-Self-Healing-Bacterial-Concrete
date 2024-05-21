
#include"bits/stdc++.h"
using namespace std;


vector<double> gauss(vector<vector<double>> &u,vector<double> &b)
{
vector<vector<double>> a;
int n =3;
for(int i=0;i<3;i++)
{
vector<double> temp(4);
for(int j=0;j<3;j++)
{
temp[j] = u[i][j];
}
temp[3] = b[i];
a.push_back(temp);
}
for(int i=0;i<n;i++)
{
int idx = i;
float max = a[idx][i];
for(int l=i+1;l<n;l++)
{
if (abs(a[l][i])>abs(max))
{
max = a[l][i];
idx= l;
}
}
for(int m=0;m<n+1;m++)
{
swap(a[i][m],a[idx][m]);
}
}
for(int i=0;i<n;i++)
{
a[i][n]/=a[i][i];
for(int l=0;l<n;l++)
{
double dk = a[i][i];
if (l!=i)
{
a[i][l]/=dk;
}
}
a[i][i] =1;
for(int j=0;j<n;j++)
{ if (j!=i)
{
double rat = a[j][i]/a[i][i];
for(int k=0 ;k<n+1;k++)
{
a[j][k]+=(-1)*rat*a[i][k];
}
}
}
}
vector<double> ans(n);
for(int i=0;i< n;i++)
{
ans[i] = a[i][n]/a[i][i];
}
return ans;
}


int main()
{  
    fstream op;
    op.open("input_for_controlled_concrete.txt",ios::in);
    int n;
    double k;
    op >> n;
    vector<double> y1(n);
    vector<double> x1(n);
    vector<double> x2(n);
    double sum_x1 = 0;
    double sum_x1s = 0;
    for (int i = 0; i < n; i++)
    {   
        
        op >> k;
        x1[i]=k;
        x2[i]= 1/k;
        sum_x1 += x1[i];
        sum_x1s += x1[i] * x1[i];
    }

    double sum_x2 = 0;
    double sum_x2s = 0;
    for (int i = 0; i < n; i++)
    {
    
        sum_x2 += x2[i];
        sum_x2s += x2[i] * x2[i];
    }

    double sum_y1 = 0;
    double sum_y1_x1 = 0;
    double sum_y1_x2 = 0;
    for (int i = 0; i < n; i++)
    {
        op >> k;
        y1[i]=1/k;
        sum_y1 += y1[i];
        sum_y1_x1 += y1[i] * x1[i];
        sum_y1_x2 += y1[i] * x2[i];
    }
    
    double sum_x1_x2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum_x1_x2 += x1[i] * x2[i];
    }
    op.close();

  fstream out ;
  out.open("output_for_controlled_concrete.txt",ios::out);
  vector<vector<double>> A1;
    vector<double> temp(3);
    temp[0] = n;
    temp[1] = sum_x1;
    temp[2] = sum_x2;
    A1.push_back(temp);
    temp[0] = sum_x1;
    temp[1] = sum_x1s;
    temp[2] = sum_x1_x2;
    A1.push_back(temp);
    temp[0] = sum_x2;
    temp[1] = sum_x1_x2;
    temp[2] = sum_x2s;
    A1.push_back(temp);
    vector <double> b1(3);
    b1[0]= sum_y1;
    b1[1]=sum_y1_x1;
    b1[2]=sum_y1_x2;

    out << "--------------------------------------------------------------------" << endl;

    vector <double> sol1= gauss(A1,b1);
     out << "The constants for modified Saenz Model determined by multilinear model for controlled concrete: " << endl;
     out << " A is: " << 1/sol1[2] << endl;
     out << " B is: " << (1/sol1[2])*sol1[0] <<endl;
     out << " C is:  " << (1/sol1[2])*sol1[1] <<endl;
    out << "----------------------------- Thank you  ---------------------------" << endl;
    out.close();
    return 0;
}


