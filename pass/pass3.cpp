#include<iostream>
using namespace std;
const int function(){
  const int i=5;
  return i;
}
int main()
{
  int test;
  test=function();
  cout << test;
  return 0;
}
