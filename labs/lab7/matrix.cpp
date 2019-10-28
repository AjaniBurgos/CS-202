#include<iostream>
using namespace std;

Matrix::Matrix(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      m_array[i][j] = 0;
    }
  }
}
Matrix::Matrix(int initialValueForAllElements){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      m_array[i][j] = initialValueForAllElements;
    }
  }
}
Matrix::Matrix(Matrix& otherMatrix){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      m_array[i][j] = otherMatrix.m_array[i][j];
    }
  }
}
void Matrix::operator=(Matrix& otherMatrix){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      this->m_array[i][j]=otherMatrix.m_array[i][j];
    }
  }
}
bool Matrix::operator==(Matrix& otherMatrix){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(this->m_array[i][j] != otherMatrix.m_array[i][j]){
        return false;
      }
    }
  }
  return true;
}
void Matrix::SetElement(int element, int value){
  if(element <=2){
   m_array[0][element%3] = value;
  }
  else if(element >=3 && element <=5){
   m_array[1][element%3] = value;
  }
  else if(element >=6 && element <=8){
   m_array[2][element%3] = value;
  }
}
void Matrix::Transpose(){
  int tmp[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      tmp[i][j]=this->m_array[i][j];
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      this->m_array[i][j]=tmp[j][i];
    }
  }
}
void Matrix::Diagonal(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(i!=j){
        this->m_array[i][j] = 0;
      }
    }
  }
}
void Matrix::Input(){
  int input;
  cout << "Enter elements of 3x3 matrix:" << endl;
  for(int i=0;i<9;i++)
  {
    cin >> input;
    SetElement(i, input);
  }
}
void Matrix::Output(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cout << m_array[i][j];
    }
    cout << endl;
  }
}
