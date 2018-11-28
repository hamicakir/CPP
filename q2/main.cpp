#include <iostream>
#include "Pi.h"

using namespace std;

int main(int argc, char* argv[]){

    Pi pi1(2);
    pi1.print();
    cout << "Approximation Error: " << pi1.apprErr() << endl;
    return 0;

}