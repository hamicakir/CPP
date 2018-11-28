#include <iostream>
#include "Array.h"

using namespace std;

int main(int argc, char* argv[]){

    Array a1; // a1 ← {0}
    Array a2(5, 0);
    int arr[]={3,3,3,3,3};
    Array a3(5, arr); // a3 ← {3, 3, 3, 3, 3}
    Array a4(a3);

    a2.add(a3);
    a2.subtract(a3);
    cout << a3.multiply(a4)<< endl; // 45
    cout << a3.getSize()<<endl; //5
    cout << a3.getData()[2]<<endl; //3

    a2.copy(a3); // a2 ← {3, 3, 3, 3, 3}
    a2.fill(1); 
    a2.print(); // [1 1 1 1 1];

    return 0;

}

