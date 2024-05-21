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
double four_point_central1(double x,double delta_x){
    return ((-function1(x+2*delta_x) + 8*function1(x+delta_x) - 8*function1(x-delta_x) + function1(x-2*delta_x))/(12*delta_x));
}
double four_point_central2(double x,double delta_x){
    return ((-function2(x+2*delta_x) + 8*function2(x+delta_x) - 8*function2(x-delta_x) + function2(x-2*delta_x))/(12*delta_x));
}
int main(){ 
    ofstream f;
    f.open("OutputDifferentiationFourPointCentralDifference.txt");
    f<<"The derivative of stress vs strain curve for Controlled Concrete at x = 0.001 is "<<four_point_central1(0.001,0.0001)<<endl;
    f<<"The derivative of stress vs strain curve for Bacterial Concrete at x = 0.001 is "<<four_point_central2(0.001,0.0001)<<endl;
    f.close();
}