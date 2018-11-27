#include <iostream>
#include "Array.h"

using namespace std;

//Constructors

Array::Array(){ size = 1; };
Array::Array(const int SIZE, const int value){
    size = SIZE;
    for(int i = 0; i < SIZE; i++){
        *(this->data + i) = value;
    }
}
Array::Array(const int SIZE, const int* arr){
    size = SIZE;
    data = (int) &arr[0];
}
Array::Array(const Array& array){
    this->size = array.size;
    for(int i = 0; i < size; i++){
        *(this->data + i) = *(array.data + i);
    }  
}

// Member Functions

int Array::getSize(){
    return sizeof(size);
}

int* Array::getData(){
    return data;
}

void Array::add(const Array& array){
    cout << "{ " ;
    for(int i = 0; i < this->size; i++){
        *(this->data + i) +=  *(array.data + i);
        cout << *(this->data + i) << " ,";
    }
    cout << " }";
}

void Array::subtract(const Array& array){
    cout << "{ " ;
    for(int i = 0; i < this->size; i++){
        *(this->data + i)  -= *(array.data + i);
        cout << *(this->data + i) << " ,";
    }
    cout << " }";
}

int Array::multiply(const Array& array){
    int result = 1;
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
    cout << " }";
}

void Array::fill(const int value){
    cout << "{ " ;
    for(int i = 0; i < this->size; i++){
        *(this->data + i) = value;
        cout << *(this->data + i) << " ,";
    }
    cout << " }";
}

void Array::print(){
    cout << "[ ";
    for(int i = 0; i < this->size; i++){
        cout << *(this->data + i) << " ";
    }
    cout << " ]";
}