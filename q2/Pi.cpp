#include <iostream>
#include <cmath>
#include <iomanip>
#include "Pi.h"

using namespace std;

Pi::Pi(const int nTerms){ n = nTerms; };

double Pi::apprErr(){
    double PI = ( double )22 / ( double )7;
    return abs(PI - value());
};

void Pi::print(){
    cout << "Pi with " << n << " terms: " << setprecision(6) << value() << endl;
};

double Pi::value(){
    double result = 0.0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            result -= ((double)1 / (double)((2 * i) - 1));
        }else{
            result += ((double)1 / (double)((2 * i) - 1));
        }
    };
    double pi = 4 * result;
    return pi;
}