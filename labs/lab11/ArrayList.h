#include <iostream>
using namespace std;

#define MAX_SIZE 10

class ArrayList{
 public:
  ArrayList();
  ArrayList(const ArrayList&);
  ~ArrayList();

  void GoToNext();
  void GoToPrevious();
  bool IsEmpty() const;
  bool IsFull() const;
  bool InsertAfter(int);
  bool Remove(int &);

  void PrintList();
 private:
  int m_list[MAX_SIZE];
  int m_size;
  int m_cursor;
};
