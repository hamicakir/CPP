#include <iostream>
#include "Array.h"

using namespace std;

//Constructors

Array::Array()
{
 size=1;
 data = new int[size]();
}

Array::Array(const int SIZE, const int value){
    size = SIZE;
    data = new int[size];
    for(int i = 0; i < SIZE; i++)
        data[i] = value;
}

Array::Array(const int SIZE, const int* arr){
    size = SIZE;
    data = const_cast<int*>(arr);
}

Array::Array(const Array& array){
    this->size = array.size;
    this->data = array.data; 
}

// Member Functions
void Array::add(const Array& array){
    cout << "{ " ;
    for(int i = 0; i < this->size; i++){
        *(this->data + i) +=  *(array.data + i);
        cout << *(this->data + i) << " ,";
    }
    cout << " }" << endl;
}

void Array::subtract(const Array& array){
    cout << "{ " ;
    for(int i = 0; i < this->size; i++){
        *(this->data + i)  -= *(array.data + i);
        cout << *(this->data + i) << " ,";
    }
    cout << " }" << endl;
}

int Array::multiply(const Array& array){
    int result = 0;
    for(int i = 0; i < this->size; i++){
        result += (*(this->data + i) * *(array.data + i));
    }
    return result;
}

void Array::copy(const Array& array){
    cout << "{ " ;
    for(int i = 0; i < this->size; i++){
        *(this->data + i) = *(array.data + i);
        cout << *(this->data + i) << " ,";
    }
    cout << " }" << endl;
}

int Array::getSize(){
    return size;
}

int* Array::getData(){
    return data;
}

void Array::fill(const int value){
    cout << "{ " ;
    for(int i = 0; i < this->size; i++){
        *(this->data + i) = value;
        cout << *(this->data + i) << " ,";
    }
    cout << " }" << endl;
}

void Array::print(){
    cout << "[ ";
    for(int i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    cout << "]" << endl;;
}