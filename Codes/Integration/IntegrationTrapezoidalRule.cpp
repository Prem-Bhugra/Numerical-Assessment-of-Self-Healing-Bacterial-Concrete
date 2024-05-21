#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
long double function1(double x)
{
    return (2.38231*pow(10,15)*pow(x,5)-1.85918*pow(10,13)*pow(x,4)+4.18539*pow(10,10)*pow(x,3)-2.91685*pow(10,7)*pow(x,2)+37116.7*x-0.111587);
}
long double function2(double x)
{
    return (3.05535*pow(10,15)*pow(x,5)-2.48216*pow(10,13)*pow(x,4)+6.00584*pow(10,10)*pow(x,3)-5.02749*pow(10,7)*pow(x,2)+56698.3*x-0.520595);
}
double trapezoidal1(double a, double b, double delta_x)
{
    if (a == b)
    {
        return 0;
    }
    double sum = 0;
    sum += function1(a);
    a += delta_x;
    while (a <= b)
    {
        sum += 2 * function1(a);
        a += delta_x;
    }
    sum += function1(a);
    return ((delta_x * sum) / 2);
}
double trapezoidal2(double a, double b, double delta_x)
{
    if (a == b)
    {
        return 0;
    }
    double sum = 0;
    sum += function2(a);
    a += delta_x;
    while (a <= b)
    {
        sum += 2 * function2(a);
        a += delta_x;
    }
    sum += function2(a);
    return ((delta_x * sum) / 2);
}
int main(){
    ofstream s;
    s.open("OutputIntegration.txt");
    s<<"Area under the graph for Controlled Concrete = "<<trapezoidal1(0,0.0035,0.0001)<<endl;
    s<<"Area under the graph for Bacterial Concrete = "<<trapezoidal2(0,0.0035,0.0001)<<endl;
    s.close();
}