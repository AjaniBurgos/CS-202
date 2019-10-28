#include<vector>

using namespace std;

template<typename T>struct VectorRecursion
{
	VectorRecursion<T>();
	int partition(int top, int bottom);
	void vector_resort(int top, int bottom);
	int vector_research(int top, int bottom, int target);
	void readFile();
	void printFile();
	vector<T> storage;
};
template<typename T> VectorRecursion<T>::VectorRecursion()
{
	storage.reserve(100);
}
template<typename T> int VectorRecursion<T>::partition(int top, int bottom)
{
	int p, i, j, t;
	p=top;
	i=top;
	j=bottom;
	while(i<j)
	{
		while((storage[i]<=storage[p])&&(i<bottom))
		{
			i++;
		}
		while(storage[j] > storage[p])
		{
			j--;
		}
		if(i<j)
		{
			t=storage[i];
			storage[i]=storage[j];
			storage[j]=t;
		}
	}
	t=storage[p];
	storage[p]=storage[j];
	storage[j]=t;
	return j;
}
template<typename T> void VectorRecursion<T>::vector_resort(int top, int bottom)
{
	int middle;
	if(top<bottom)
	{
		middle=partition(top,bottom);
		vector_resort(top,middle-1);
		vector_resort(middle+1,bottom);
	}
}
template<typename T> int VectorRecursion<T>::vector_research(int top, int bottom, int target)
{
	int pivot=(top+bottom)/2;
	if(pivot==target)
	{
		return pivot;
	}
	else if(pivot<target)
	{
		vector_research(top, pivot+1, target);
	}
	else if(pivot>target)
	{
		vector_research(pivot-1, bottom, target);
	}
	else if(top==bottom)
	{
		vector_research(top, bottom, target);
	}
	return -1;
}
template<typename T> void VectorRecursion<T>::readFile()
{
	std::ifstream inputFile;
	inputFile.open("RandomData.txt");
	inputFile.clear();
	for(int index=0;index<100;index++)
	{
		inputFile >> storage[index];
	}
	inputFile.close();
}
template<typename T> void VectorRecursion<T>::printFile()
{
	std::ofstream outputFile;
	outputFile.open("output.txt");
	for(int index=0;index<10;index++)
	{
		outputFile << storage[index] << "|";
	}
	outputFile.close();
}
