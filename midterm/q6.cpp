#include<iostream>
using namespace std;
class Parent{
  public:
    virtual void SetValue(int value){
      m_value = value;
    }
    virtual int GetValue(){
      return m_value;
    }
  protected:
    int m_value;
};
class Child : public Parent{
  public:
    virtual void SetValue(int value){
      m_precisionValue = value;
    }
    virtual double GetValue(){
      return m_precisionValue;
    }
  private:
    double m_precisionValue;
};

int main(){
  Child c;

  c.SetValue(1);
  cout << c.GetValue()/2 << endl;

  return 0;
}
