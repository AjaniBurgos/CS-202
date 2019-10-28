#include<iostream>
using namespace std;

class StaticClass{
  public:

    static int count;

    StaticClass(){
      m_count = 0;
      count++;
    }
    StaticClass(int count_in){
      m_count = count_in;
      count++;
    }
    void CountUp(){
      m_count++;
    }
    int GetCount(){
      return m_count;
    }
  private:
    int m_count;
};
int StaticClass::count = 0;

int main(){
  StaticClass sc_a;
  sc_a.CountUp();
  StaticClass sc_b(sc_a.count);
  sc_b.CountUp();
  StaticClass sc_c(sc_b);
  sc_c.CountUp();

  cout << sc_a.GetCount() << " " <<
          sc_b.GetCount() << " " <<
          sc_c.GetCount() << " " <<
          StaticClass::count << endl;
  return 0;
}
