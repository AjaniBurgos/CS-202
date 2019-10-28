#include<iostream>
using namespace std;
class Complex
{
  public:
    Complex();
    void SetReal(double real);
    void SetImaginary(double imaginary);
    double GetReal() const;
    double GetImaginary() const;
    double Magnitude()const;
    void Print() const;
    Complex& operator+(const Complex& rhs); /*Overloaded Operator*/
    Complex& operator-(const Complex& rhs); /*Overloaded Operator*/
  private:
    double m_real;
    double m_imaginary;
};

Complex::Complex()
{
  m_real=0.0;
  m_imaginary=0.0;
}
void Complex::SetReal(double real)
{
  m_real=real;
}
void Complex::SetImaginary(double imaginary)
{
  m_imaginary=imaginary;
}
double Complex::GetReal() const
{
  return m_real;
}
double Complex::GetImaginary() const
{
  return m_imaginary;
}
double Complex::Magnitude() const
{
  return sqrt((m_real*m_real) + (m_imaginary*m_imaginary));
}
void Complex::Print() const
{
  //real + iimaginary
  else if(m_imaginary < 0)
  {
    if(m_real == 0)
    {
      cout << "-i" << -1 * m_imaginary;
    }
    else
    {
      cout << m_real << " - i" << m_imaginary << endl;
    }
  }
  else if(m_imaginary > 0)
  {
    if(m_real == 0)
    {
      cout << "i" << m_imaginary;
    }
    else
    {
    cout << m_real << " + i" << m_imaginary << endl;
    }
  }
  else if(m_imaginary == 0)
  {
    if(m_real == 0)
    {
      cout << "0" << endl;
    }
    else
    {
      cout << m_real << endl;
    }
  }
}
Complex Complex::operator+(const Complex& rhs)
{
  m_real+=rhs.m_real;
  m_imaginary+=rhs.m_imaginary;
  return *this; /*'this' is a function that points to an object*/
}
Complex& operator-(const Complex& rhs)
{
  m_real-=rhs.m_real;
  m_imaginary-=rhs.m_imaginary;
  return *this;
}

int main()
{
  for(int i=1;i<=100;i++)
  {
    if(i%5==0 && i%3==0)
    {
      cout << i << ": fizzbuzz" << endl;
    }
    else if(i%5==0)
    {
      cout << i << ": fizz" << endl;
    }
    else if(i%3==0)
    {
      cout << i << ": buzz" << endl;
    }
  }
  return 0;
}
