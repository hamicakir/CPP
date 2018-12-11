#include <iostream>
#include <stdexcept>
#include "Matrix.h"

using namespace std;

Matrix::Matrix()
// initialize Matrix class object with rowN=1, colN=1, and a zero value
{
 rowN = 1;
 colN = 1;
 data = new float[rowN*colN];

 for (int i=0; i<rowN; i++)
 for (int j=0; j<colN; j++)
    data[i*rowN+j]=0;
};

Matrix::Matrix(const int rN, const int cN)
// initialize Matrix class object with rowN=1, colN=1, and a zero value
{
 rowN = rN;
 colN = cN;
 data = new float[rowN * colN];

 for (int i = 0; i < rowN; i++)
 for (int j = 0; j < colN; j++)
 data[i * rowN + j]=0;
};

Matrix::Matrix(const int rN, const int cN, const float *srcPtr){
    rowN = rN;
    colN = cN;
    data = new float[rowN * colN];

    for(int i = 0; i < rowN; i++){
        for(int j = 0; j < colN; j++){
            data[i * rowN +j] = srcPtr[i * rowN + j];
        }
    }
}; 

int Matrix::getColN() const{
    return colN;
};

int Matrix::getRowN() const{
    return rowN;
};

void Matrix::print() const{
    for(int i = 0; i < rowN; i++){
        for(int j = 0; j < colN; j++){
            cout << data[i * rowN + j] << " ";
        }
        cout << "\n";
    }
};  // prints the Matrix object in rowNxcolN form


Matrix Matrix::transpose() const{
    Matrix temp;
    for(int j = 0; j < colN; j++){
        for(int i = 0; i < rowN; i++){
            temp.data[j * rowN + i] = data[i * rowN + j];
        }
    }
    return temp;
}; 


Matrix Matrix::operator+(const Matrix &rhsMatrix)const{
    Matrix temp;
    if(rowN == rhsMatrix.rowN || colN == rhsMatrix.colN){
        for(int i = 0; i < rowN ; i++){
            for(int j = 0; j < colN; j++){
                temp.data[i * rowN + j] = data[i * rowN + j] + rhsMatrix.data[i * rowN + j];
            }
        };
    }else{
        throw invalid_argument("Dimensions are not equal so that you cant sum this matrix");
    }
    return temp;
};

Matrix Matrix::operator-(const Matrix &rhsMatrix)const{
    Matrix temp;
    if(rowN == rhsMatrix.rowN || colN == rhsMatrix.colN){
        for(int i = 0; i<rowN ; i++){
            for(int j = 0; j<colN; j++){
                temp.data[i * rowN + j] = data[i * rowN + j] - rhsMatrix.data[i*rowN + j];
            }
        };
    }else{
        throw invalid_argument("Dimensions are not equal so that you cant sum this matrix");
    }
    return temp;
};

Matrix Matrix::operator*(const Matrix &rhsMatrix) const{
    Matrix temp;
    if(rowN == rhsMatrix.rowN || colN == rhsMatrix.colN){
        for(int i = 0; i<rowN ; i++){
            for(int j = 0; j<colN; j++){
                temp.data[i * rowN + j] = data[i * rowN + j] * rhsMatrix.data[i * rowN + j];
            }
        };
    }else{
        throw invalid_argument("Dimensions are not equal so that you cant sum this matrix");
    }
    return temp;
};

float Matrix::operator()(const int r,const int c)const{
    return data[r + c];
};

Matrix& Matrix::operator=(const Matrix &rhsMatrix){
    if(&rhsMatrix != this){
        for(int i = 0; i<rowN ; i++){
            for(int j = 0; j<colN; j++){
                data[i * rowN + j] = rhsMatrix.data[i * rowN + j];
            }
        };
        return *this;
    }else{
        throw invalid_argument("Dimensions are not equal so that you cant sum this matrix");
    }
};

Matrix& Matrix::operator+=(const Matrix &rhsMatrix){
    if(&rhsMatrix != this){
        for(int i = 0; i<rowN ; i++){
            for(int j = 0; j<colN; j++){
                data[i * rowN + j] += rhsMatrix.data[i * rowN + j];
            }
        };
        return *this;
    }else{
        throw invalid_argument("Dimensions are not equal so that you cant sum this matrix");
    }
};

Matrix& Matrix::operator-=(const Matrix &rhsMatrix){
    if(&rhsMatrix != this){
        for(int i = 0; i<rowN ; i++){
            for(int j = 0; j<colN; j++){
                data[i * rowN + j] -= rhsMatrix.data[i * rowN + j];
            }
        };
        return *this;
    }else{
        throw invalid_argument("Dimensions are not equal so that you cant sum this matrix");
    }
};

Matrix& Matrix::operator*=(const Matrix &rhsMatrix){
    if(&rhsMatrix != this){
        for(int i = 0; i<rowN ; i++){
            for(int j = 0; j<colN; j++){
                data[i * rowN + j] *= rhsMatrix.data[i * rowN + j];
            }
        };
        return *this;
    }else{
        throw invalid_argument("Dimensions are not equal so that you cant sum this matrix");
    }
};

int Matrix::operator==(const Matrix &rhsMatrix)const{
    int response = 1;
    if(rowN == rhsMatrix.rowN && colN == rhsMatrix.colN){
        for(int i = 0; i < rowN; i++){
            for(int j = 0; j < colN; i++){
                if(data[i * rowN + j] !=  rhsMatrix.data[i * rowN + j]){
                    response = 0;
                    break;
                }
            }
        }
    }else{
        response = 0;
    }
    return response;
};

int Matrix::operator!=(const Matrix &rhsMatrix)const{
    int response = 1;
    if(rowN == rhsMatrix.rowN && colN == rhsMatrix.colN){
        for(int i = 0; i < rowN; i++){
            for(int j = 0; j < colN; i++){
                if(data[i * rowN + j] ==  rhsMatrix.data[i * rowN + j]){
                    response = 0;
                    break;
                }
            }
        }
    }
    return response;
}