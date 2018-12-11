#include <iostream>
#include "Matrix.h"

using namespace std;

int main(int argc, char* argv[]){
    float initialArray[9] = {1,2,3,4,5,6,7,8,9};
    Matrix *m1 = new Matrix();
    m1 -> print();
    cout << "Second Matrix" << endl;
    Matrix *matricetwo = new Matrix(3, 3);
    matricetwo -> print();
    cout << "Sum of Matrix" <<endl;
    Matrix *matricethree = new Matrix(3 ,3 , initialArray);
    matricethree -> print();
    return 0;
}