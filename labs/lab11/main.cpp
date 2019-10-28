#include <iostream>
#include "ArrayList.h"
using namespace std;

int main() {
  ArrayList array_list;
  int removed;

  array_list.PrintList();

  for(int i = 10; i > 0; i--) {
    array_list.InsertAfter(i);
  }
  array_list.PrintList();

  array_list.GoToPrevious();
  array_list.GoToPrevious();
  array_list.Remove(removed);
  array_list.PrintList();

  array_list.GoToNext();
  array_list.InsertAfter(removed);
  array_list.PrintList();

  return 0;
};
