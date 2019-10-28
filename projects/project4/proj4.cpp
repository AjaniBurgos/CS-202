//Name: Ajani Burgos
//Purpose: To expand upon the previous project's rental car agency to get practice with class operators
//Date: 1 March 2017
#include<iostream>
#include<fstream>
#include "agencies.h"

using namespace std;
/*                                                         FUNCTION DECLARATIONS:                                                  */
void readFile();
void userMenu();
void printData();
void printFile(int printtype);
void printSensorCount();
void findExpensive();

/***********************************************************************************************************************************/
/*                                                         ---MAIN FUNCTION---                                                     */
/***********************************************************************************************************************************/
int main()
{
  readFile();
  userMenu();
  return 0;
}

/*                                                         FUNCTION DEFINITIONS:                                                  */
void readFile()
{
  char input[20];
  char temp_name[20];
  int temp_zip[5];
  int* iptr = temp_zip;
  int temp_year;
  char temp_make[20];
  char temp_model[20];
  float temp_tank;
  float temp_price;
  bool temp_available;
  char temp_owner[20];
  char temp_scanner[10];
  int gps=0, lidar=0, scanner=0, camera=0;

  cout << "Enter input filename: ";
  cin >> input;
  ifstream inputFile;
  inputFile.open(input);
  inputFile.clear();

  inputFile >> temp_name;
  inputFile.get();
  for(int i=0;i<5;i++)
  {
    *iptr = inputFile.get()-'0';
    iptr++;
  }
  for(int i=1;i<10;i++)
  {
    inputFile >> temp_year;
    inputFile >> temp_make;
    inputFile >> temp_model;
    inputFile >> temp_tank;
    inputFile >> temp_price;
    /*INSERT WAY TO READ IN THE SCANNER*/
    inputFile.get();
    inputFile.get();
  //  while(inputFile.get()!= '}')
  //  {
      if(inputFile.peek() == ' ')
      {
        inputFile.get();
        inputFile >> temp_scanner;
        if(strcmp(temp_scanner, (char*)"gps") == 0)
        {
          gps++;
        }
        else if(strcmp(temp_scanner, (char*)"camera") == 0)
        {
          camera++;
        }
        else if(strcmp(temp_scanner, (char*)"lidar") == 0)
        {
          lidar++;
        }
        else if(strcmp(temp_scanner, (char*)"scanner") == 0)
        {
          scanner++;
        }
      }
    //}
    inputFile >> boolalpha >> temp_available;
    if(temp_available == false)
    {
      inputFile >> temp_owner;
    }
    else
    {
      strcpy(temp_owner,(char*)"NULL");
    }
  }
  /***The following chunk of code is supposed to set the members of the RentalCar class, but I couldn't figure out how to set up my object***/

  // for(int i=0;i<10;i++)
  // {
  //   SetName(temp_name);
  //   SetZip(temp_zip);
  //   SetMake(temp_make);
  //   SetModel(temp_model);
  //   SetPrice(temp_price);
  //   SetTank(temp_tank);
  //   SetOwner(temp_owner);
  //   SetAvailable(temp_available);
  // }
  inputFile.close();
}
void userMenu()
{
  bool loop_main = true;
  int option;

  while(loop_main == true)
  {
    cout << "\n";
    cout << "Select an option below: " << endl;
    cout << "(1) - Read in a Different File" << endl;
    cout << "(2) - Print all Data" << endl;
    cout << "(3) - Print Total Number of Sensors" << endl;
    cout << "(4) - Find Most Expensive Car" << endl;
    cout << "(5) - Exit the Program" << endl;
    cout << "Please enter desired option: ";
    cin >> option;
    cout << "\n";

    switch(option)
    {
      case 1:
        readFile();
        break;
      case 2:
        printData();
        break;
      case 3:
        printSensorCount();
        break;
      case 4:
        findExpensive();
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
void printData()
{
  printFile(1);
  // int year = GetYear;
  // char* make = GetMake;
  // char* model = GetModel;
  // float price = GetPrice;
  // float tank = GetTank;
  // bool available = GetAvailable;
  // for(int i=0;i<10;i++)
  // {
  //   cout << year << make << model << "$" << price << tank << available << endl;
  // }
}
void printFile(int printtype)
{
  char output[20];
  cout << "Enter output filename: ";
  cin >> output;
  ofstream outputFile;
  outputFile.open(output);
  outputFile.clear();
  if(printtype == 1) /*Print the Car Chart*/
  {
    
  }
  else if(printtype == 2) /*Print the Sensor Count*/
  {

  }
  else if(printtype == 3) /*Print the Expensive Car*/
  {

  }
  outputFile.close();
}
void printSensorCount()
{
  printFile(2);
  // cout << "GPS: " << sptr->GetGPS() << endl;
  // cout << "Camera: " << sptr->GetCam() << endl;
  // cout << "Lidar: " << sptr->GetLidar() << endl;
  // cout << "Radar: " << sptr->GetRadar() << endl;
}
void findExpensive()
{
  printFile(3);
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
