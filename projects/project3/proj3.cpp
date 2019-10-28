//Name: Ajani Burgos
//Purpose: To practice using C++ Classes and pointers in order to create a Rental Car user interface
//Date: 15 Feburary 2017
#include<iostream>
#include<fstream>

#include "rentalcar.h"

using namespace std;

/*                                                         FUNCTION DECLARATIONS:                                                  */
void readFile(RentalAgency* aptr); /*Reads in the data and stores it*/
void userMenu(RentalAgency* aptr); /*User interface; calls for other functions*/
void printData(RentalAgency* aptr); /*Prints out all data*/
void outputFile(RentalAgency* aptr); /*Prompts the user for output filename & prints it out*/
void estimateValue(RentalAgency* aptr); /*Prompts for an agency and car number; estimates the value of the selected car*/
void findExpensive(RentalAgency* aptr); /*Finds the most expensive car and outputs its information*/
void printAvailable(RentalAgency* aptr); /*Prints out the information for all cars that are available from all agencies*/
int strcmp(char* str1, char* str2); /*Compares 2 strings to each other*/
/***********************************************************************************************************************************/
/*                                                           ---MAIN FUNCTION---                                                   */
/***********************************************************************************************************************************/
int main()
{
  //VARIABLES:
  RentalAgency agency[3];
  RentalAgency* aptr = agency;
  RentalCar* cptr = agency->inventory;

  //USER INPUT:
  readFile(aptr);
  userMenu(aptr);

  //RESULT:

  return 0;
}
/*                                                         FUNCTION DEFINITIONS:                                                  */

void readFile(RentalAgency* aptr)
{
  int* iptr = aptr -> zipcode;
  char input[STR_LEN];
  int temp_year;
  char temp_make[STR_LEN];
  char temp_model[STR_LEN];
  float temp_price;
  bool temp_available;
  RentalCar* cptr;
  cptr=aptr->inventory;
  cout << "Enter input filename: ";
  cin >> input;

  ifstream inputFile;
  inputFile.open(input);
  inputFile.clear();

  for(int i=0;i<3;i++)
  {
    inputFile >> aptr->agency_name;
    inputFile.get();
    for(int j=0;j<5;j++)
    {
      *iptr = inputFile.get() - '0';
      iptr++;
    }
    for(int index=0;index<5;index++)
    {
      inputFile >> temp_year;
      inputFile >> temp_make;
      inputFile >> temp_model;
      inputFile >> temp_price;
      inputFile >> boolalpha >> temp_available;
      cptr->SetYear(temp_year);
      cptr->SetMake(temp_make);
      cptr->SetModel(temp_model);
      cptr->SetPrice(temp_price);
      cptr->SetAvailable(temp_available);
      cptr++;
    }
    aptr++;
  }
}
void userMenu(RentalAgency* aptr)
{
  bool loop_main = true;
  int option;

  while(loop_main == true)
  {
    cout << "\n";
    cout << "Select an option below: " << endl;
    cout << "(1) - Print all Data" << endl;
    cout << "(2) - Estimate Rental Cost of a Car" << endl;
    cout << "(3) - Find Most Expensive Car" << endl;
    cout << "(4) - Print Out Data for Available Cars" << endl;
    cout << "(5) - Exit the Program" << endl;
    cout << "Please enter desired option: ";
    cin >> option;
    cout << "\n";

    switch(option)
    {
      case 1:
        printData(aptr);
        break;
      case 2:
        estimateValue(aptr);
        break;
      case 3:
        findExpensive(aptr);
        break;
      case 4:
        printAvailable(aptr);
        break;
      case 5:
        loop_main = false;
        break;
      default:
        cout << "Invalid input; please select a different option." << endl;
        break;
    }
  }
}

void printFile(RentalAgency* aptr)
{
  RentalCar* cptr = aptr->inventory;
  char output[STR_LEN];

  cout << "Enter output filename: ";
  cin >> output;

  ofstream outputFile;
  outputFile.open(output);
  outputFile.clear();
  for(int i=0;i<3;i++)
  {
    outputFile << aptr->agency_name << " ";
    outputFile << aptr->zipcode << endl;
    for(int i=0;i<5;i++)
    {
      outputFile << cptr->GetYear() << " ";
      cout << cptr->GetYear() << " ";
      cout << cptr->GetMake() << " ";
      cout << cptr->GetModel() << " ";
      cout << "$" << cptr->GetPrice() << " per day ";
      cout << "Available: " << boolalpha << cptr->GetAvailable() << endl;
      cptr++;
    }
    aptr++;
  }
}

void printData(RentalAgency* aptr)
{
  RentalCar* cptr = aptr->inventory;

  //printFile(aptr);
  for(int i=0;i<3;i++)
  {
    cout << aptr->agency_name << " ";
    cout << aptr->zipcode << endl;
    for(int i=0;i<5;i++)
    {
      cout << cptr->GetYear() << " ";
      cout << cptr->GetMake() << " ";
      cout << cptr->GetModel() << " ";
      cout << "$" << cptr->GetPrice() << " per day ";
      cout << "Available: " << boolalpha << cptr->GetAvailable() << endl;
      cptr++;
    }
    aptr++;
  }
}

void estimateValue(RentalAgency* aptr)
{
  RentalCar* cptr = aptr->inventory;
  char name_input[STR_LEN];
  int input, days;
  float estimate;
  bool loop = true;

  cout << "Enter desired agency: ";
  cin >> name_input;
  while(loop = true)
  {
    if((strcmp(name_input, aptr->agency_name))!= 0)
    {
      cout << "Error: agency input unrecognized." << endl;
      loop = true;
    }
    else
    {
      loop = false;
    }
  }
  cout << "Enter number of desired car (1-5): ";
  cin >> input;
  cout << "Enter number of days renting: ";
  cin >> days;

  for(int i=0;i<3;i++)
  {
    if((strcmp(name_input, aptr->agency_name)) == 0)
    {
      for(int i=0;i<5;i++)
      {

      }
    }
    else
    {
      aptr++;
    }
  }
  estimate = cptr->GetPrice() * days;

  cout << "Estimate: $" << estimate << endl;
}
void findExpensive(RentalAgency* aptr)
{
  printFile(aptr);
}
void printAvailable(RentalAgency* aptr)
{
  printFile(aptr);
}
void strcpy(char* dest, char* src)
{
  while(*src != '\0')
  {
    *dest = *src;
    src++;
    dest++;
  }
  *dest = '\0';
}
int strcmp(char* str1, char* str2)
{
  while((*str1 != '\0') || (*str2 != '\0'))
  {
    if(*str1 < *str2)
    {
      return -1;
    }
    else if(*str2 < *str1)
    {
      return 1;
    }
    else
    {
      str1++;
      str2++;
    }
  }
  if(*str1 == '\0')
  {
    return -1;
  }
  else if(*str2 == '\0')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
