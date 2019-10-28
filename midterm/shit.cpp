#include<iostream>
using namespace std;

class BaseClass{
  public:
    void SetIntVar(int i){
      m_intVar = i;
    }
    int GetIntVar(){
      return m_intVar;
    }
  private:
    int m_intVar;
};
class DerivedClass : public BaseClass{
  public:
    void SetDoubleVar(double d){
      m_doubleVar = d * m_intVar;
    }
    double GetDoubleVar(){
      return m_doubleVar;
    }
  private:
    double m_doubleVar;
};

int main()
{
  BaseClass b_result;

  BaseClass b1;
  b1.SetIntVar(10);
  DerivedClass d2;
  d2.SetDoubleVar(2.5);

  b_result.SetDoubleVar((double)b1.GetIntVar() + d2.GetDoubleVar());
  cout << b_result.GetDoubleVar();
  
  return 0;
}
