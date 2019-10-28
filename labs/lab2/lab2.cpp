//Name: Ajani Burgos
//Purpose: To test if a year is a leap year or not
//Date: 2 Feburary 2016
#include<iostream>

using namespace std;

void prompt(int *input);
bool check(int input);

/********************************************************************************/
/*                       -----MAIN FUNCTION-----                                */
/********************************************************************************/
int main()
{
  int input;
  prompt(&input);
  check(input);
  if(input == true)
  {
    cout << input << " is a leap year" << endl;
  }
  else
  {
    cout << input << " is not a leap year" << endl;
  }

  return 0;
}

void prompt(int *input)
{
  cout << "Enter desired year: ";
  cin >> *input;
}

bool check(int input)
{
  if((input%4000) != 0)
  {
    return false;
  }
  else
  {
    return true;
  }
}
