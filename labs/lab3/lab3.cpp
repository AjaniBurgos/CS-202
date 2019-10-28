//Name: Ajani Burgos
//Purpose:
//Date: 9 Feburary 2017

#include<iostream>

 using namespace std;

int strcmp(char str1[], char str2[]);
int main()
{
  char word1[15];
  char word2[15];
  int compare;

  cout << "Enter Word 1:";
  cin >> word1;
  cout << "Enter Word 2:";
  cin >> word2;

  compare = strcmp(word1,word2);
  if(compare == 1)
  {
    cout << word2 << "is first." << endl;
  }
  else if(compare == -1)
  {
    cout << word1 << " is first." << endl;
  }
  else if(compare == 0)
  {
    cout << "Both " << word1 << " and " << word2 << " are the same." << endl;
  }
  else
  {
    cout << "You fucked up nigga." << endl;
  }

  return 0;
}
int strcmp(char str1[], char str2[])
{
  int i;
  while(str1[i] != '\0' || str2[i] != '\0')
  {
    if(str1[i] < str2[i])
    {
      return -1;
    }
    else if(str1[i] > str2[i])
    {
      return 1;
    }
    else
    {
      i++;
    }
  }
  if(str1[i] == '\0')
  {
    return -1;
  }
  else if(str2[i] == '\0')
  {
    return 1;
  }
  else if(str1[i] == str2[i])
  {
    return 0;
  }
}
