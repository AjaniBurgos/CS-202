//Name: Ajani Burgos
//Date: 4 May 2017
//Purpose: To implement recursion and vectors
#include<iostream>
#include<fstream>
#include "VectorRecursion.h"

/*																										---FUNCTION DECLARATIONS---																								 */
// int partition(int storage[], int top, int bottom);
// void vector_resort(int storage[], int top, int bottom);
// int vector_research(int storage[], int top, int bottom, int target);
// void readFile(int storage[]);
// void printFile(int storage[]);

/*********************************************************************************************************************************/
/*																											-----MAIN FUNCTION-----																									 */
/*********************************************************************************************************************************/
int main()
{
	VectorRecursion<int> array;
	array.readFile();
	array.printFile();
	array.vector_resort(0, 15);
	int target=array.vector_research(0, 5, 2);
	cout << "Target = " << target << endl;
	return 0;
}

/*																										---FUNCTION DEFINITIONS---																								 */
// int partition(int storage[], int top, int bottom)
// {
// 	// int p, i, j, t;
// 	// p=top;
// 	// i=top;
// 	// j=bottom;
// 	// while(i<j)
// 	// {
// 	// 	while((storage[i]<=storage[p])&&(i<bottom))
// 	// 	{
// 	// 		i++;
// 	// 	}
// 	// 	while(storage[j] > storage[p])
// 	// 	{
// 	// 		j--;
// 	// 	}
// 	// 	if(i<j)
// 	// 	{
// 	// 		t=storage[i];
// 	// 		storage[i]=storage[j];
// 	// 		storage[j]=t;
// 	// 	}
// 	// }
// 	// t=storage[p];
// 	// storage[p]=storage[j];
// 	// storage[j]=t;
// 	// return j;
// }
// // void vector_resort(int storage[], int top, int bottom)
// {
// 	// int middle;
// 	// if(top<bottom)
// 	// {
// 	// 	middle=partition(storage,top,bottom);
// 	// 	vector_resort(storage,top,middle-1);
// 	// 	vector_resort(storage,middle+1,bottom);
// 	// }
// }
// // int vector_research(int storage[], int top, int bottom, int target)
// {
// 	// int pivot=(top+bottom)/2;
// 	// if(pivot==target)
// 	// {
// 	// 	return pivot;
// 	// }
// 	// else if(pivot<target)
// 	// {
// 	// 	vector_research(storage, top, pivot	, target);
// 	// }
// 	// else if(pivot>target)
// 	// {
// 	// 	vector_research(storage, pivot-1, bottom, target);
// 	// }
// 	// else if(top==bottom)
// 	// {
// 	// 	vector_research(storage, top, bottom, target);
// 	// }
// 	// else
// 	// {
// 	// 	return -1;
// 	// }
// }
// // void readFile(int storage[])
// {
// 	// std::ifstream inputFile;
// 	// inputFile.open("RandomData.txt");
// 	// inputFile.clear();
// 	// for(int index=0;index<100;index++)
// 	// {
// 	// 	inputFile >> storage[index];
// 	// }
// 	// inputFile.close();
// }
// // void printFile(int storage[])
// {
// 	// int index;
// 	// std::ofstream outputFile;
// 	// outputFile.open("output.txt");
// 	// for(index=0;index<100;index++)
// 	// {
// 	// 	outputFile << storage[index] << "|";
// 	// }
// 	// outputFile << "Size: " << index;
// 	// outputFile.close();
// }
