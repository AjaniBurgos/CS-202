#include<iostream>
using namespace std;
void printArray(int arr[], int size){
  for(int i=0;i<size;++i){
    cout << arr[i] << " ";
  }
  cout << endl;
}
void fillArrayAscending(int arr[], int size){
  for(int i=0;i<size;++i){
    arr[i]=i;
  }
}

const int ARRAYSIZE = 10;
struct MyStruct{
  int intArray[ARRAYSIZE];
};
void fillStructArrayAscending(MyStruct *st_in){
  fillArrayAscending(st_in->intArray, ARRAYSIZE);
}
void printStructArray(MyStruct *st_in){
  printArray(st_in->intArray, ARRAYSIZE);
}

int main(){
  MyStruct my_struct;
  MyStruct* ptr = &my_struct;
  printStructArray(ptr);
  fillStructArrayAscending(ptr);
  printStructArray(ptr);
  return 0;
}
