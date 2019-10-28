//Name: Ajani Burgos
//Purpose: To read in a list of cars and create a menu to display its information using structs
//Date: 8 Feburary 2017
#include<iostream>
#include<fstream>

using namespace std;

/*                                        STRUCTS                                           */
struct carData
{
  int year;
  char make[20];
  char model[20];
  float price;
  int available;
};

/*                                 FUNCTION DECLARATIONS                                    */
void readInput(char input[20], carData info[10]); /*Reads in the data from the file that the user type in*/
void displayMenu(carData info[10]); /*Displays the menu which calls the other functions*/
void displayInfo(carData info[10]); /*Displays ALL data from the file*/
void estimatePrice(carData info[10]); /*Prompts the user for the desired car; calculates cost*/
void displayExpensive(carData info[10]); /*Stores the most expensive car's data; displays it as well*/
void displayAvailable(carData info[10]); /*Displays data for ONLY cars that are available*/

/********************************************************************************************/
/*                                -----MAIN FUNCTION-----                                   */
/********************************************************************************************/
int main()
{
  //VARIABLES:
  char input[20];
  carData info[10];

  //USER INPUT:
  cout << "Enter input file name: ";
  cin >> input;

  //RESULT:
  readInput(input, info);
  displayMenu(info);

  return 0;
}

/*                                 FUNCTION DEFINITIONS                                     */
void readInput(char input[20], carData info[10])
{
  int i;

  ifstream inputFile;
  inputFile.open(input);
  inputFile.clear();
  for(i=0;i<10;i++)
  {
    inputFile >> info[i].year;
    inputFile >> info[i].make;
    inputFile >> info[i].model;
    inputFile >> info[i].price;
    inputFile >> info[i].available;
  }
  inputFile.close();
}

void displayMenu(carData info[10])
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
        displayInfo(info);
        break;
      case 2:
        estimatePrice(info);
        break;
      case 3:
        displayExpensive(info);
        break;
      case 4:
        displayAvailable(info);
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

void displayInfo(carData info[10])
{
  int i;
  cout << "==================================================\n";
  for(i=0;i<10;i++)
  {
    cout << info[i].year << " ";
    cout << info[i].make << " ";
    cout << info[i].model << " ";
    cout << "$" << info[i].price << " per day ";
    if((info[i].available) == 1)
    {
      cout << "Available: true" << endl;
    }
    else if((info[i].available) == 0)
    {
      cout << "Available: false" << endl;
    }
  }
  cout << "==================================================\n";
}

void estimatePrice(carData info[10])
{
  int car, days;
  float estimate;

  cout << "Enter desired car: ";
  cin >> car;
  cout << "Number of days renting: ";
  cin >> days;

  estimate = info[car-1].price * days;
  cout << "Estimate: $" << estimate << endl;
}

void displayExpensive(carData info[10])
{
  int i;
  float expensive = 0.0;
  for(i=0;i<10;i++)
  {
    if(info[i].price > expensive)
    {
      expensive = info[i].price;
    }
  }
  for(i=0;i<10;i++)
  {
    if(info[i].price == expensive)
    {
      cout << info[i].year << " ";
      cout << info[i].make << " ";
      cout << info[i].model << " ";
      cout << "$" << info[i].price << " per day ";
      if(info[i].available == 1)
      {
        cout << "Available: true" << endl;
      }
      else if(info[i].available == 0)
      {
        cout << "Available: false" << endl;
      }
    }
  }
}

void displayAvailable(carData info[10])
{
  int i;

  cout << "==================================================\n";
  for(i=0;i<10;i++)
  {
    if(info[i].available == 1)
    {
      cout << info[i].year << " ";
      cout << info[i].make << " ";
      cout << info[i].model << " ";
      cout << "$" << info[i].price << " per day " << endl;
    }
  }
  cout << "==================================================\n";
}
