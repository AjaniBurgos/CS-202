//Name: Ajani Burgos
//Purpose: To read in names from a .txt file, sort them alphebtically, and output them in another .txt
//Date: 30 Jan 2017
#include<iostream>
#include<fstream>

using namespace std;

/*                                          -----FUNCTION DECLARATIONS-----                                           */
void read_file(char input[20], char names[10][10]); /*Reads the names within the desired file*/
void print_names(char names[10][10]); /*Prints the list of names in the terminal*/
int strcmp(char names[][10], int row); /*Compares two strings*/
void strcopy(char name[][10], int row); /*Copies one string into another*/
void sort(char names[][10]); /*Sorts the names in alphabetical order*/
void print_file(char output[20], char names[10][10]); /*Creates a new file desired by the user and adds the new names*/

/**********************************************************************************************************************/
/*                                              -----MAIN FUNCTION-----                                               */
/**********************************************************************************************************************/

int main()
{
  //VARIABLES:
  char input[20];
  char output[20];
  char names[10][10];

  //LOGIC & ARITHMETIC:
  cout << "Enter name of desired input file: ";
  cin >> input;
  cout << "Enter name of desired output file: ";
  cin >> output;

  //RESULT:
  read_file(input, names);
  cout << "Unsorted Names\n" << "====================" << endl;
  print_names(names);
  cout << "\nSorted Names\n" << "====================" << endl;
  sort(names);
  print_names(names);
  print_file(output, names);

  return 0;
}

/*                                          -----FUNCTION DEFINITIONS=-----                                             */
void read_file(char input[20], char names[10][10])
{
  int index;

  ifstream inputFile;
  inputFile.open(input);
  for(index=0;index<10;index++)
  {
    inputFile >> names[index];
  }
  inputFile.close();
}

void print_names(char names[10][10])
{
  int index;

  for(index=0;index<10;index++)
  {
    cout << names[index] << endl;
  }
}

int strcmp(char names[][10], int row)
{
	int col;

	for(col = 0; col < 10; col++){
		if (names[row][col] > names[row+1][col]){
			return 1;
		}
		if (names[row][col] < names[row+1][col]){
			return 0;
		}
	}
	return 0;
}

void strcopy(char names[][10], int row)
{
	char temp[10];
	int col;

	for(col=0;col<9;col++)
  {
		temp[col]=names[row][col];
		names[row][col]=names[row+1][col];
		names[row+1][col]=temp[col];
	}
}

void sort(char names[][10])
{
	int swap;
	int row, col;
	bool swapping = true;

	while(swapping != false)
  {
		swapping = false;
		for(row=0;row<9;row++)
    {
			for(col=0;col<9;col++)
      {
				swap = strcmp(names, row);
				if (swap == 1)
        {
					strcopy(names, row);
					swapping = true;
				}
		  }
		}
	}
}

void print_file(char output[20], char names[10][10])
{
  int index;

  ofstream outputFile;
  outputFile.open(output);
  for(index=0;index<10;index++)
  {
    outputFile << names[index] << endl;
  }
  outputFile.close();
}
