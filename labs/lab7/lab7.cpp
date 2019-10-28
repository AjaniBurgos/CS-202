#include<iostream>
#include "matrix.h"
#include "matrix.cpp"

using namespace std;
int main()
{
  Matrix og;
  Matrix tran;
  Matrix diag;
  Matrix dtran;

  og.Input();
  cout << "Matrix:" << endl;
  og.Output();
  cout << endl;

  tran=og;
  tran.Transpose();
  cout << "Transpose of Matrix: " << endl;
  tran.Output();

  cout << endl;

  if(og==tran){
    cout << "The matrix is symmetric." << endl;
  }
  else{
    cout << "The matrix is not symmetric." << endl;
  }
  cout << endl;

  diag=og;
  diag.Diagonal();
  cout << "Diagonal-elements Matrix: " << endl;
  diag.Output();
  cout << endl;

  diag.Transpose();
  cout << "Diagonal-elements Matrix Transpose: " << endl;
  diag.Output();
  dtran=diag;
  cout << endl;

  if(diag==dtran){
    cout << "The Diagonal-elements Matrix is symmetric." << endl;
  }
  else{
    cout << "The Diagonal-elements Matrix is not symmetric." << endl;
  }

  return 0;
}
