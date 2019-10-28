#include <iostream>

//#include "ArrayQueue.h"
#include "NodeQueue.h"

using namespace std;

int main(){

  //Test Driver Code
  NodeQueue<int> q1;
  q1.push(1);
  q1.push(2);
  q1.push(3);
  cout << "Q1_size:" << q1.size() << ", Q1:" << q1 << endl;

  NodeQueue<int> q2;
  q2.push(4);
  q2.push(5);
  q2.push(6);
  q2.push(7);
  cout << "Q2_size:" << q2.size() << ", Q2:" << q2 << endl;

  cout << "Setting Q2 = Q1" << endl;
  q2 = q1;
  cout << "Q2_size:" << q2.size() << ", Q2:" << q2 << endl;

  return 0;

}
